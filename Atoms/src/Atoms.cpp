#include <Atoms.h>

Atoms Atoms::s_Instance;

bool Atoms::initialize()
{
	if (m_InitializeGLFW() && m_InitializeOpenGL())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Atoms::run()
{
	m_Render();
}

bool Atoms::m_InitializeGLFW()
{
	if (!glfwInit()) return false;

	m_Window = glfwCreateWindow(m_Width, m_Height, "Atoms", nullptr, nullptr);
	if (!m_Window) return false;
	glfwMakeContextCurrent(m_Window);

	glfwSwapInterval(0);
	return true;
}

bool Atoms::m_InitializeOpenGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		return false;
	};

	m_Shader = std::make_unique<Shader>();
	m_PeriodicTable = std::make_unique<Renderer::PeriodicTable>(m_Shader.get());

	glViewport(0, 0, m_Width, m_Height);

	shader_create(m_Shader.get(), "inc/default/default.vert", "inc/default/default.frag");
	if (!m_Shader) return false;

	float aspectRatio = (float)m_Width / (float)m_Height;
	glm::mat4 projection = glm::ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
	u_mat4f(m_Shader, "proj", projection);
}

void Atoms::m_Render()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	manager.SetScene(std::make_unique<Scene::PeriodicTableScene>(m_PeriodicTable.get(), m_Window));

	double ptime = glfwGetTime();

	while (!glfwWindowShouldClose(m_Window))
	{
		double ctime = glfwGetTime();
		double delta = ctime - ptime;

		ptime = ctime;
		double fps = 1.0 / delta;

		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		manager.Update();
		manager.Draw();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		std::cout << fps << "\n";
		glfwSwapBuffers(m_Window);
	}
}

void Atoms::cleanup()
{
	glfwDestroyWindow(m_Window);
	glfwTerminate();

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}