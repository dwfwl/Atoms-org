#include "../VBO.h"

void vbo_create(VBO& self)
{
    glGenBuffers(1, &self.handle);
}

void vbo_bind(VBO& self)
{
    glBindBuffer(GL_ARRAY_BUFFER, self.handle);
}

void vbo_buffer(VBO& self, std::vector<Vertex> vertices)
{
    vbo_bind(self);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void vbo_update(VBO& self, std::vector<Vertex> vertices)
{
    vbo_bind(self);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());
}

void vbo_unbind(VBO& self)
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vbo_delete(VBO& self)
{
    glDeleteBuffers(1, &self.handle);
}
