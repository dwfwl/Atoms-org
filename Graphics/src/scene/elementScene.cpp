#include "scene/elementScene.h"

Scene::ElementScene::ElementScene(Chemistry::Element* e)
{
	element = e;
}

void Scene::ElementScene::Update(SceneManager& manager)
{

}

void Scene::ElementScene::UpdateElement(int n, int l, int m)
{
	// element->CreateOrbital(n,l,m); ??
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
	ImGui::Text("n: "); ImGui::SameLine();
	ImGui::SliderInt("##1", &n, 0, 7);
	static int l = 0;
	ImGui::Text("l: "); ImGui::SameLine();
	ImGui::SliderInt("##2", &l, 0, 2);
	static int m = 0;
	ImGui::Text("m: "); ImGui::SameLine();
	ImGui::SliderInt("##3", &m, 0, 2);

	if (ImGui::Button("Update"))
	{
		UpdateElement(n, l, m);
	}

	ImGui::End();
	// element->draw();
}