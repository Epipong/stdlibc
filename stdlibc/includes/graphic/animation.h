#ifndef ANIMATION_GRAPHIC_H_
# define ANIMATION_GRAPHIC_H_

# include <SFML/Graphics.h>

# include "std.h"

typedef struct s_animation animation;

struct s_animation
{
  sfTexture *texture;
  vector    frames;
};

struct      s_animation_class
{
  void      (*constructor)(animation *this);
  void      (*destructor)(animation *this);
  void      (*add_frame)(animation *this, sfIntRect rect);
  sfIntRect (*get_frame)(animation const *this, size_t n);
};

extern struct s_animation_class g_animation;

#endif /* !ANIMATION_GRAPHIC_H_ */
