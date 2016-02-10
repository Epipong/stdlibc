#ifndef SYSTEM_H_
# define SYSTEM_H_

# include "audio.h"
# include "game_logic.h"
# include "graphic.h"
# include "input.h"
# include "object_factory.h"
# include "physic.h"
# include "ui.h"

enum  e_system
{
  AUDIO,
  GAME_LOGIC,
  GRAPHIC,
  INPUT,
  OBJECT_FACTORY,
  PHYSIC,
  UI,
  SYSTEM_LENGTH
};

struct          s_sys
{
  enum e_system type;
  void          *system;
};

typedef void (*t_ctor)(void *this);
typedef void (*t_dtor)(void *this);
typedef void (*t_update)(void *this, float datetime, list objects);

extern t_ctor constructor_system[SYSTEM_LENGTH];
extern t_dtor destructor_system[SYSTEM_LENGTH];
extern t_update update_system[SYSTEM_LENGTH];

void          init_system(void);
struct s_sys  _system(enum e_system type, void *system);

#endif /* !SYSTEM_H_ */
