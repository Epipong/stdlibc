#define GENERIC

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

static void _destructor(engine *this)
{
  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
  {
    foreach (row, this->systems[i])
      free(row->value);
    destructor(this->systems[i]);
  }
}

static void     _update(engine *this, float datetime)
{
  struct s_sys  *sys;

  for (size_t i = 0; i < SYSTEM_LENGTH; ++i)
  {
    foreach (row, this->systems[i])
    {
      sys = row->value;
      update_system[sys->type](sys->system, 0);
    }
  }
}

static void _loop(engine *this)
{
}

static void     _add_system(engine *this, struct s_sys src)
{
  struct s_sys  *dest;

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
