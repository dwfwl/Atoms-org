#include "../Texture.h"

bool texture_create(Texture& self, const char* file)
{
    int width = 0, height = 0, nrChannels = 0;

    self.data = stbi_load(file, &width, &height, &nrChannels, 0);

    glGenTextures(1, &self.handle);
    glBindTexture(GL_TEXTURE_2D, self.handle);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (!self.data)
    {
        std::cout << "TEXTURE ERR :: include/gfx/texture.h\nFailed to load image to `data`" << std::endl;
        return false;
    }
    else
    {
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, self.data);
        glGenerateMipmap(GL_TEXTURE_2D);
        return true;
    }
 }

void texture_bind(Texture& self)
{
    glBindTexture(GL_TEXTURE_2D, self.handle);
}

void texture_unbind(Texture& self)
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void texture_delete(Texture& self)
{
    glDeleteTextures(1, &self.handle);
    if (self.data) {
        stbi_image_free(self.data);
        self.data = nullptr;
    }
}
