#define GENERIC

#include <SFML/System.h>

#include "engine/engine.h"
#include "generic.h"

static void _constructor(engine *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
    constructor(this->systems[i]);
  init_system();
}

static void     _destructor(engine *this)
{
  struct s_sys  *sys;

  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
  {
    foreach (row, this->systems[i])
    {
      sys = row->value;
      destructor_system[sys->type](sys->system);
      free(sys->system);
      free(row->value);
    }
    destructor(this->systems[i]);
  }
}

static void     _update(engine *this, sfTime datetime)
{
  struct s_sys  *sys;

  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
  {
    foreach (row, this->systems[i])
    {
      sys = row->value;
      update_system[sys->type](sys->system, 0, (list){0});
    }
  }
}

static void _loop(engine *this)
{
  sfClock   *clock;
  sfTime    current_time;

  clock = sfClock_create();
  current_time = sfClock_restart(clock);
  while (true)
  {
    _update(this, current_time);
  }
  sfClock_destroy(clock);
}

static void     _add_system(engine *this, struct s_sys src, size_t n)
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
  push_back(this->systems[src.type], dest);
}

struct s_engine_class	g_engine = {
  &_constructor,
  &_destructor,
  &_update,
  &_loop,
  &_add_system
};
