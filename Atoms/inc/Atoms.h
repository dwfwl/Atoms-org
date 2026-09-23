#pragma once
#include <iostream>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "graphics.h"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

#include "inc/opengl/shaders/shader.h"
#include "inc/rendering/periodicTable/periodicTable.h"

#include "inc/scene/sceneManager.h"
#include "inc/scene/periodicTableScene.h"

/*
* @brief Core class responsible for initializing and running the application
*
* @note This class follows the singleton design to only allow a single instance
*/

class Test
{
public:
	void printHi()
	{
		count++;
		std::cout << "Clicked ENTER " << count << " amount of times" << std::endl;
	}
private:
	int count;
};

class Atoms
{
public:
	/*
	* @brief Deletes the default copy constructor
	* Deleting the copy constructor prevents copying of the Atoms application
	*/
	Atoms(const Atoms&) = delete;

	/*
	* @brief Retrieves the instance of the application
	* @return A reference to the singleton instance
	*/
	static Atoms& Get()
	{
		return s_Instance;
	}

	/*
	* @brief Initializes the application
	* @return "true" if the init was succesful, "false" otherwise
	*/
	bool initialize();

	/*
	* @brief Runs the main game loop
	*/
	void run();

	/*
	* @brief Cleans up resources and terminates glfw
	*/
	void cleanup();

private:
	static Atoms s_Instance;
	Atoms() {};
private:
	GLFWwindow* m_Window = nullptr;
	std::unique_ptr<Shader> m_Shader;
	std::unique_ptr<Renderer::PeriodicTable> m_PeriodicTable;
private:
	int m_Width = 1800;
	int m_Height = 980;

private:
	bool m_InitializeGLFW();
	bool m_InitializeOpenGL();
	void m_Render(/*Scene* scene*/);

	Scene::SceneManager manager;
	// Scene* currentScene;
};