#ifndef SDL_H_
# define SDL_H_

# include <SDL2/SDL.h>

# include "math/vector4.h"

typedef struct s_sdl SDL;

struct        s_sdl
{
  SDL_Window  *window;
  SDL_Surface *screen_surface;
};

struct        s_sdl_class
{
  void        (*constructor)(SDL *this);
  void        (*destructor)(SDL *this);
  SDL_Window  *(*create_window)(SDL *this, char const *title,
                                vector4 m, int flags);
  SDL_Surface *(*get_window_surface)(SDL *this);
  int         (*fill_rect)(SDL *this, const SDL_Rect *rect, Uint32 color);
  int         (*update_window_surface)(SDL *this);
  void        (*delay)(Uint32 ms);
  char const  *(*get_error)();
};

extern struct s_sdl_class  g_sdl;

#endif /* !SDL_H_ */
