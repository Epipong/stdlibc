#include "animation/sora.h"
#include "generic.h"

static int    ptrcmp(const value_type a, const value_type b)
{
  return (a - b);
}

static void sora_init_down(animation *action)
{
  int       i;

  if (action == NULL)
    return ;
  action->texture = g_textures[SORA_SPRITE_SHEET];
  g_animation.add_frame(action, (sfIntRect){0, 0, 32, 56});
  g_animation.add_frame(action, (sfIntRect){-5, 56, 32, 42});
  g_animation.add_frame(action, (sfIntRect){30, 56, 30, 42});
  g_animation.add_frame(action, (sfIntRect){62, 56, 32, 42});
  g_animation.add_frame(action, (sfIntRect){92, 56, 32, 42});
  g_animation.add_frame(action, (sfIntRect){130, 56, 36, 42});
  g_animation.add_frame(action, (sfIntRect){166, 56, 30, 42});
  g_animation.add_frame(action, (sfIntRect){199, 56, 30, 42});
  g_animation.add_frame(action, (sfIntRect){231, 56, 33, 42});
}

static void sora_init_movement(sora_animation *this)
{
  animation *action;

  this->animations.v_comp = &ptrcmp;
  insert(this->animations, "down", new(action));
  // insert(this->animations, "left", new(action));
  // insert(this->animations, "right", new(action));
  // insert(this->animations, "up", new(action));
  sora_init_down(_at(this->animations, "down"));
  action = _at(this->animations, "down");
}

static void sora_destructor(animation *action)
{
  destructor(*action);
  free(action);
}

void sora_ctor(sora_animation *this)
{
  constructor(this->animations);
  sora_init_movement(this);
}

void    sora_dtor(sora_animation *this)
{
  char  *movements[] = {"down", NULL};
  // char  *movements[] = {"down", "left", "right", "up", NULL};

  for (int i = 0; movements[i] != NULL; ++i)
    sora_destructor(_at(this->animations, movements[i]));
  destructor(this->animations);
}
