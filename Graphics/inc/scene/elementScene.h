#pragma once

#include "scene.h"

#include "../Chemistry/chemistry.h"
#include "../Graphics/inc/imgui/instance_imgui.h"

namespace Scene
{
	class ElementScene : public Scene
	{
	public:
		ElementScene(Chemistry::Element* e);

		void Update(SceneManager& manager) override;
		void UpdateElement(int n, int l, int m);

		void Draw() override;
	private:
		Chemistry::Element* element;
	};
}