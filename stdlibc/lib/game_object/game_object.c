#include "game_object/game_object.h"

static void constructor(game_object *this)
{
}

static void destructor(game_object *this)
{
}

static component *get_component(game_object *this, int id)
{
  return (NULL);
}

static void add_component(game_object *this, component *comp)
{
}

static bool has_component(game_object *this, int id)
{
  return (false);
}

struct s_game_object_class  g_game_object = {
  &constructor,
  &destructor,
  &get_component,
  &add_component,
  &has_component
};
