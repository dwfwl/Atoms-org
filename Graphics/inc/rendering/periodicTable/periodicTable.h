#pragma once
#include <vector>
#include <array>

#include "../Graphics/inc/opengl/shaders/shader.h"
#include "../Graphics/inc/opengl/pipeline/VBO.h"

// #include "../Chemistry/chemistry.h"
#include "../element/element.h"

namespace Renderer
{
    class PeriodicTable
    {
    public:
        PeriodicTable(Shader* shader);

        std::vector<Geometry> rows =
        {
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.66827f, 0.95f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.66827f, 0.78f ,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.78f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.95f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // row 1
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.66827f, 0.77, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.66827f, 0.6, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.6, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.77, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // row 2
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.66827f, 0.59f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.66827f, 0.42f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.42f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.59f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // row 3
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.66827f,  0.41f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.66827f,	 0.24f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.24f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.41f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // row 4
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.66827f,  0.23f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.66827f,	 0.06f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.06f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, 0.23f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // row 5
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.66827f,   0.05f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.66827f,	 -0.12f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, -0.12f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f,  0.05f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // row 6
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.66827f,  -0.13f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.66827f,	 -0.3f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, -0.3f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.49827f, -0.13f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // row 7
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.30827f,  -0.36f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.30827f,	 -0.54,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.13827, -0.54f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.13827, -0.36f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // bottom row 1 
            Geometry
            {
                std::vector<Vertex>{
                    Vertex{glm::vec3(-1.30827f, -0.55f, 0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.30827f, -0.72f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.13827f, -0.72f,  0.0f), glm::vec3(1.0f)},
                    Vertex{glm::vec3(-1.13827f, -0.55f, 0.0f), glm::vec3(1.0f)}
                }, std::vector<uint32_t>
                {
                    0, 1,
                    1, 2,
                    2, 3,
                    3, 0
                }
            }, // bottom row 2
        };

        void draw()
        {
            int i = 0;
            for (auto& elementUi : m_ElementsUi)
            {
                shader_use(m_Shader);

                elementUi.draw();
                i++;
            }
        }

        Geometry addOffset(float yOffset, Geometry& placeHolder);

        std::array<ElementUi, 118> m_ElementsUi;

    private:
        Shader* m_Shader;
    };
}