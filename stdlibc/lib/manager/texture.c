#include "manager/texture.h"

sfTexture **g_textures;

static void   constructor(texture_manager *this)
{
  char const  *filename;

  for (size_t i = 0; i < TEXTURE_COUNT; ++i)
  {
    filename = g_texture_filename[i].filename;
    this->textures[i] = sfTexture_createFromFile(filename, NULL);
  }
  g_textures = this->textures;
}

static void destructor(texture_manager *this)
{
  for (size_t i = 0; i < TEXTURE_COUNT; ++i)
    sfTexture_destroy(this->textures[i]);
}

struct s_texture_manager_class g_texture_manager = {
  &constructor,
  &destructor
};
