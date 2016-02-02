#include <string.h>

#include "math/vector4.h"
#include "sdl.h"

static void constructor(SDL *this)
{
  if (this != NULL)
    return ;
  memset(this, 0, sizeof(*this));
}

static void destructor(SDL *this)
{
  SDL_DestroyWindow(this->window);
  SDL_Quit();
}

static int init(SDL *this, int flags)
{
  return (SDL_Init(flags));
}

static SDL_Window *create_window(SDL *this, char const *title,
                                 vector4 m, int flags)
{
  return (this->window = SDL_CreateWindow(title, m.x, m.y, m.z, m.w, flags));
}

static SDL_Surface  *get_window_surface(SDL *this)
{
  return (this->screen_surface = SDL_GetWindowSurface(this->window));
}

static int fill_rect(SDL *this, const SDL_Rect *rect, Uint32 color)
{
  return (SDL_FillRect(this->screen_surface, rect, color));
}

static int update_window_surface(SDL *this)
{
  return (SDL_UpdateWindowSurface(this->window));
}

static void delay(Uint32 ms)
{
  SDL_Delay(ms);
}

static char const *get_error()
{
  return (SDL_GetError());
}

struct s_sdl_class g_sdl = {
  &constructor,
  &destructor,
  &create_window,
  &get_window_surface,
  &fill_rect,
  &update_window_surface,
  &delay,
  &get_error
};
