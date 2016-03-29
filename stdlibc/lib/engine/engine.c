#include <SFML/System.h>
#include <string.h>

#include "engine/engine.h"

static void constructor(engine *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
    g_vector.constructor(&this->systems[i]);
  init_system();
}

static void     destructor(engine *this)
{
  struct s_sys  *sys;
  iterator      it;

  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
  {
    for (it = g_vector.begin(&this->systems[i]); it != NULL; it = it->forward)
    {
      if ((sys = it->value) != NULL)
      {
        destructor_system[sys->type](sys->system);
        free(sys->system);
        free(sys);
      }
    }
    g_vector.destructor(&this->systems[i]);
  }
}

static void       update(engine *this, sfTime datetime)
{
  struct s_sys    *sys;
  object_factory  *of;
  list            *objects;
  iterator        it;

  of = g_vector.front(&this->systems[OBJECT_FACTORY]);
  objects = of != NULL ? &of->objects : NULL;
  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
  {
    for (it = g_vector.begin(&this->systems[i]); it != NULL; it = it->forward)
    {
      sys = it->value;
      update_system[sys->type](sys->system, datetime, objects);
    }
  }
}

static void loop(engine *this)
{
  sfClock   *clock;
  sfTime    current_time;

  clock = sfClock_create();
  current_time = sfClock_restart(clock);
  while (g_is_run)
  {
    update(this, current_time);
    current_time = sfClock_restart(clock);
  }
  sfClock_destroy(clock);
}

static void     add_system(engine *this, struct s_sys src, size_t n)
{
  struct s_sys  *dest;
  void          *s;

  if ((s = calloc(1, n)) == NULL)
    exit(EXIT_FAILURE);
  src.system = s;
  constructor_system[src.type](src.system);
  if ((dest = malloc(sizeof(*dest))) == NULL)
    exit(EXIT_FAILURE);
  memcpy(dest, &src, sizeof(*dest));
  g_vector.push_back(&this->systems[src.type], dest);
}

struct s_engine_class	g_engine = {
  &constructor,
  &destructor,
  &update,
  &loop,
  &add_system
};
