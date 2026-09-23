#pragma once
#include <memory>
#include "scene.h"

namespace Scene
{
	class SceneManager
	{
	public:
		SceneManager() = default;

		void SetScene(std::unique_ptr<Scene> newScene);
		void Update();

		void Draw();

	private:
		std::unique_ptr<Scene> currentScene;
		std::unique_ptr<Scene> pendingScene;
	};
}