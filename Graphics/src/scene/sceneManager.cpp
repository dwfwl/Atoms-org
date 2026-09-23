#include "scene/sceneManager.h"

void Scene::SceneManager::SetScene(std::unique_ptr<Scene> newScene)
{
	pendingScene = std::move(newScene);
}

void Scene::SceneManager::Update()
{
	if (pendingScene)
	{
		currentScene = std::move(pendingScene);
	} if (currentScene)
	{
		currentScene->Update(*this);
	}
}

void Scene::SceneManager::Draw()
{
	if (currentScene) currentScene->Draw();
}