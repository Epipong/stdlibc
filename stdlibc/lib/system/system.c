#include "system/system.h"

t_ctor    constructor_system[SYSTEM_LENGTH];
t_dtor    destructor_system[SYSTEM_LENGTH];
t_update  update_system[SYSTEM_LENGTH];

static void init_constructor_system(void)
{
  constructor_system[AUDIO] = (t_ctor)g_audio.constructor;
  constructor_system[GAME_LOGIC] = (t_ctor)g_game_logic.constructor;
  constructor_system[GRAPHIC] = (t_ctor)g_graphic.constructor;
  constructor_system[INPUT] = (t_ctor)g_input.constructor;
  constructor_system[OBJECT_FACTORY] = (t_ctor)g_object_factory.constructor;
  constructor_system[PHYSIC] = (t_ctor)g_physic.constructor;
  constructor_system[UI] = (t_ctor)g_ui.constructor;
}

static void init_destructor_system(void)
{
  destructor_system[AUDIO] = (t_dtor)g_audio.destructor;
  destructor_system[GAME_LOGIC] = (t_dtor)g_game_logic.destructor;
  destructor_system[GRAPHIC] = (t_dtor)g_graphic.destructor;
  destructor_system[INPUT] = (t_dtor)g_input.destructor;
  destructor_system[OBJECT_FACTORY] = (t_dtor)g_object_factory.destructor;
  destructor_system[PHYSIC] = (t_dtor)g_physic.destructor;
  destructor_system[UI] = (t_dtor)g_ui.destructor;
}

static void init_update_system(void)
{
  update_system[AUDIO] = (t_update)g_audio.update;
  update_system[GAME_LOGIC] = (t_update)g_game_logic.update;
  update_system[GRAPHIC] = (t_update)g_graphic.update;
  update_system[INPUT] = (t_update)g_input.update;
  update_system[OBJECT_FACTORY] = (t_update)g_object_factory.update;
  update_system[PHYSIC] = (t_update)g_physic.update;
  update_system[UI] = (t_update)g_ui.update;
}

void init_system(void)
{
  init_constructor_system();
  init_destructor_system();
  init_update_system();
}

struct s_sys    _system(enum e_system type, void *system)
{
  struct s_sys  s = {
    .type = type,
    .system = system
  };
  return (s);
}
