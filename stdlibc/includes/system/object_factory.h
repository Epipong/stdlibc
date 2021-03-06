#ifndef OBJECT_FACTORY_H_
# define OBJECT_FACTORY_H_

# include <SFML/System.h>

# include "message/message.h"
# include "std.h"

typedef struct s_object_factory object_factory;

struct    s_object_factory
{
  list    objects;
};

struct s_object_factory_class
{
  void (*constructor)(object_factory *this);
  void (*destructor)(object_factory *this);

  void (*update)(object_factory *this, sfTime datetime, list *objects);
  void (*init)(object_factory *this);
  void (*send_message)(object_factory *this, message *msg);
};

extern struct s_object_factory_class  g_object_factory;

#endif /* !OBJECT_FACTORY_H_ */
