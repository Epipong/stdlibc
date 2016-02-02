#ifndef GAME_OBJECT_H_
# define GAME_OBJECT_H_

# include "component/component.h"
# include "std.h"

typedef struct s_game_object  game_object;

struct    s_game_object
{
  vector  components;
};

struct      s_game_object_class
{
  void      (*constructor)(game_object *this);
  void      (*destructor)(game_object *this);

  component *(*get_component)(game_object *this, int id);
  void      (*add_component)(game_object *this, component *comp);
  bool      (*has_component)(game_object *this, int id);
};

extern struct s_game_object_class g_game_object;

#endif /* !GAME_OBJECT_H_ */
