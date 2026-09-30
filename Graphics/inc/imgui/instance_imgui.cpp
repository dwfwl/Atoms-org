#include "instance_imgui.h"

Style::Style()
{
	init();
}

void Style::init()
{
	ImGui::GetIO().Fonts->AddFontFromFileTTF("D:\\coding\\Atoms\\Atoms\\fonts\\gotham.ttf", 25);
	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	style.WindowRounding = 5.0f;
	style.ChildRounding = 5.0f;
	style.FrameRounding = 5.0f;
	style.PopupRounding = 20.0f;
	style.ScrollbarRounding = 20.0f;
	style.GrabRounding = 20.0f;
	style.TabRounding = 20.0f;

	colors[ImGuiCol_TitleBgActive] = ImVec4(0.05f, 0.05f, 0.05f, 0.70f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.70f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.70f);
	colors[ImGuiCol_Button] = ImVec4(0.15f, 0.15f, 0.15f, 0.70f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.25f, 0.25f, 0.70f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.35f, 0.35f, 0.35f, 0.70f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.15f, 0.15f, 0.15f, 0.70f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.25f, 0.25f, 0.25f, 0.70f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.35f, 0.35f, 0.35f, 0.70f);


}