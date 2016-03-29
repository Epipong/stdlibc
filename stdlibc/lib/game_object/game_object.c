#include "game_object/game_object.h"

static void constructor(game_object *this)
{
  g_vector.constructor(&this->components);
}

static void destructor(game_object *this)
{
  g_vector.destructor(&this->components);
}

static component  *get_component(game_object *this, int id)
{
  iterator        it;

  for (it = g_vector.begin(&this->components);
       it != NULL && ((component *)it->value)->id != id; it = it->forward);
  return (it != NULL ? it->value : NULL);
}

static void add_component(game_object *this, component *comp)
{
  g_vector.push_back(&this->components, comp);
}

static bool has_component(game_object *this, int id)
{
  return (get_component(this, id) != NULL);
}

struct s_game_object_class  g_game_object = {
  &constructor,
  &destructor,
  &get_component,
  &add_component,
  &has_component
};
