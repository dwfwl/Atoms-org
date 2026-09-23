#pragma once
#include <string>
#include <functional>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <fstream>

#include "../Chemistry/chemistry.h"
#include "../renderer.h"

#include "../Graphics/inc/opengl/pipeline/VAO.h"
#include "../Graphics/inc/opengl/pipeline/VBO.h"
#include "../Graphics/inc/opengl/pipeline/EBO.h"
#include "../text/text.h"

namespace Renderer
{
	class ElementUi
	{
	public:
		ElementUi();
		ElementUi(Chemistry::Element& element, Geometry&& geometry);
		~ElementUi();

		void buffers();
		void update();
		void draw();

		Chemistry::Element* m_Element;
		Geometry m_Geometry;

	private:
		std::stringstream m_Stream;

		VAO vao;
		VBO vbo;
		EBO ebo;
		Renderer::Text textUI;
	};

	bool inbound(double xpos, double ypos, ElementUi& element);
	glm::vec3 findMidpoint(const std::vector<Vertex>& vertices);
}