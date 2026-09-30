#include "scene/elementScene.h"

Scene::ElementScene::ElementScene(Chemistry::Element* e)
{
	element = e;
}

void Scene::ElementScene::Update(SceneManager& manager)
{

}

void Scene::ElementScene::Draw()
{
	ImVec2 size(200, 0);

	ImGuiViewport* viewport = ImGui::GetMainViewport();

	ImVec2 pos(
		viewport->WorkPos.x + viewport->WorkSize.x - size.x - 10,
		viewport->WorkPos.y + 10
	);

	ImGui::SetNextWindowPos(pos);
	ImGui::SetNextWindowSize(size);

	ImGui::Begin("Element Specifications", nullptr, Style::Get().flags);
	ImGui::Text("Element: %s", element->Symbol.c_str());
	ImGui::Text("Orbital Settings");

	static int n = 0;
	ImGui::SliderInt("n", &n, 0, 7);
	static int l = 0;
	ImGui::SliderInt("l", &l, 0, 2);
	static int m = 0;
	ImGui::SliderInt("m", &m, 0, 2);

	if (ImGui::Button("Update"))
	{
		// Simulation::Element::instance::UpdateElement(n, l, m);
	}

	ImGui::End();

	size = ImVec2(0, 0);

	pos = ImVec2(
		10,
		10
	);

	ImGui::SetNextWindowPos(pos);
	ImGui::SetNextWindowSize(size);

	ImGui::Begin("###1", nullptr, Style::Get().flags);

	if (ImGui::Button("Back"))
	{
		prevScene = true;
	}

	ImGui::End();
}