#ifndef SPRITE_GRAPHIC_H_
# define SPRITE_GRAPHIC_H_

# include <SFML/Graphics.h>
# include <SFML/System.h>

# include "config.h"
# include "graphic/animation.h"
# include "std.h"

typedef struct s_sprite_graphic sprite_graphic;

struct      s_sprite_graphic
{
  animation const *action;
  sfSprite        *sprite;
  sfTime          frame_time;
  sfTime          current_time;
  size_t          current_frame;
  bool            is_paused;
  bool            is_looped;
  sfTexture const *texture;
};

struct s_sprite_graphic_class
{
  void        (*constructor)(sprite_graphic *this);
  void        (*destructor)(sprite_graphic *this);
  void        (*update)(sprite_graphic *this, sfTime delta_time);
  void        (*set_animation)(sprite_graphic *this, animation const *action);
  void        (*play)(sprite_graphic *this, animation const *action);
  void        (*pause)(sprite_graphic *this);
  void        (*stop)(sprite_graphic *this);
  void        (*set_color)(sprite_graphic *this, sfColor const color);
  sfFloatRect (*get_local_bounds)(sprite_graphic *this);
  sfFloatRect (*get_global_bounds)(sprite_graphic *this);
  void        (*set_frame)(sprite_graphic *this, size_t new_frame,
                           bool reset_time);
  void        (*draw)(sprite_graphic *this, sfRenderWindow *target,
                      sfRenderStates *states);
  void        (*move)(sprite_graphic *this, sfVector2f offset);
  void        (*set_position)(sprite_graphic *this, sfVector2f position);
  void        (*set_scale)(sprite_graphic *this, sfVector2f scale);
};

extern struct s_sprite_graphic_class g_sprite_graphic;

#endif /* !SPRITE_GRAPHIC_H_ */
