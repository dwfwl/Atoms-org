#include <glad/glad.h>

#include <opengl/pipeline/VAO.h>
#include <opengl/pipeline/VBO.h>
#include <opengl/pipeline/EBO.h>

#include <memory>

namespace Simulation
{
	class Particle
	{
	public:
		Particle();

		void create(int t);
		void draw();
	protected:
		std::unique_ptr<Geometry> geometry;

		std::unique_ptr<VAO> vao;
		std::unique_ptr<VBO> vbo;
		std::unique_ptr<EBO> ebo;
	};
}