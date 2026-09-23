#pragma once
#include <glm/glm.hpp>

namespace Renderer
{
	glm::vec2 openglToGlfw(glm::vec3 openglCoords, int width, int height);
}