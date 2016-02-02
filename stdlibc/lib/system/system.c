#include "system/system.h"

t_update  update_system[SYSTEM_LENGTH + 1];

void init_system(void)
{
  update_system[AUDIO] = (t_update)g_audio.update;
  update_system[GAME_LOGIC] = (t_update)g_game_logic.update;
  update_system[GRAPHIC] = (t_update)g_graphic.update;
  update_system[INPUT] = (t_update)g_input.update;
  update_system[OBJECT_FACTORY] = (t_update)g_object_factory.update;
  update_system[PHYSIC] = (t_update)g_physic.update;
  update_system[UI] = (t_update)g_ui.update;
}

struct s_sys    _system(enum e_system type, void *system)
{
  struct s_sys  s = {
    .type = type,
    .system = system
  };
  return (s);
}
