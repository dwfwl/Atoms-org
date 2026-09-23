#pragma once
#include "scene.h"
#include "sceneManager.h"
#include "elementScene.h"
#include "../rendering/periodicTable/periodicTable.h"

#include <string>

#include <GLFW/glfw3.h>

namespace Scene
{
	class PeriodicTableScene : public Scene
	{
	public:
		PeriodicTableScene(Renderer::PeriodicTable* pt, GLFWwindow* window);

		void Update(SceneManager& manager) override;
		void Draw() override;

		// ElementUi* e;
		Renderer::PeriodicTable* m_PeriodicTable;

		GLFWwindow* m_Window;
	};
}