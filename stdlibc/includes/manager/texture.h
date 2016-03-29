#ifndef TEXTURE_MANAGER_H_
# define TEXTURE_MANAGER_H_

# include <SFML/Graphics.h>

# include "config.h"

typedef struct s_texture_manager  texture_manager;

struct      s_texture_manager
{
  sfTexture *textures[TEXTURE_COUNT];
};

struct s_texture_manager_class
{
  void (*constructor)(texture_manager *this);
  void (*destructor)(texture_manager *this);
};

extern struct s_texture_manager_class g_texture_manager;
extern sfTexture  **g_textures;

#endif /* !TEXTURE_MANAGER_H_ */
