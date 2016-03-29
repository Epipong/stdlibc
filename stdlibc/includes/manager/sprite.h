#ifndef SPRITE_MANAGER_H_
# define SPRITE_MANAGER_H_

# include <SFML/Graphics.h>

# include "config.h"
# include "graphic/sprite.h"
# include "std.h"

typedef struct s_sprite_manager  sprite_manager;

struct    s_sprite_manager
{
  vector  sprites;
};

struct s_sprite_manager_class
{
  void (*constructor)(sprite_manager *this);
  void (*destructor)(sprite_manager *this);
};

extern struct s_sprite_manager_class g_sprite_manager;

#endif /* !SPRITE_MANAGER_H_ */
