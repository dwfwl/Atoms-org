#include "scene/periodicTableScene.h"

Scene::PeriodicTableScene::PeriodicTableScene(Renderer::PeriodicTable* pt, GLFWwindow* window)
{
	m_Window = window;
	m_PeriodicTable = pt;
}

void Scene::PeriodicTableScene::Update(SceneManager& manager)
{
	std::string word;
	double xpos, ypos;
	glfwGetCursorPos(m_Window, &xpos, &ypos);

	for (int i = 0; i < 118; i++)
	{
		// if (inbound(xpos, ypos, m_PeriodicTable->m_ElementsUi[i]) && glfwGetMouseButton(m_Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{
			// manager.SetScene(std::make_unique<ElementScene>(m_PeriodicTable->m_ElementsUi[i].m_Element));
		}
	}
}

void Scene::PeriodicTableScene::Draw()
{
	// m_PeriodicTable->draw();
}