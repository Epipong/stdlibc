#define GENERIC

#include "game_object/game_object.h"
#include "generic.h"

static void _constructor(game_object *this)
{
}

static void _destructor(game_object *this)
{
}

static component *_get_component(game_object *this, int id)
{
  return (NULL);
}

static void _add_component(game_object *this, component *comp)
{
  push_back(this->components, comp);
}

static bool _has_component(game_object *this, int id)
{
  return (false);
}

struct s_game_object_class  g_game_object = {
  &_constructor,
  &_destructor,
  &_get_component,
  &_add_component,
  &_has_component
};
