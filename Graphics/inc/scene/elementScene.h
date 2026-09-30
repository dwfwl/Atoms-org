#pragma once

#include "scene.h"

#include "../Chemistry/chemistry.h"
#include "../Graphics/inc/imgui/instance_imgui.h"

#include "../Graphics/inc/rendering/element/element.h"

namespace Scene
{
	class ElementScene : public Scene
	{
	public:
		ElementScene(Chemistry::Element* e);

		void Update(SceneManager& manager) override;
		void Draw() override;

	private:
		Chemistry::Element* element;
		Renderer::ElementUi elementUi;
	};
}