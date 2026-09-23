#include "rendering/renderer.h"

namespace Renderer
{
	glm::vec2 openglToGlfw(glm::vec3 openglCoords, int width, int height) {
		glm::vec2 xc(-1.83673f, 1.83673f);

		float x = ((openglCoords.x - xc.x) / (xc.y - xc.x)) * width;
		float y = (-1.0f - openglCoords.y) / (-1.0f - 1.0f) * height;

		return glm::vec2(x, y);
	}
}