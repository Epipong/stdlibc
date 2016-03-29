#ifndef COMPONENT_H_
# define COMPONENT_H_

# include "message/message.h"

# include "std.h"

typedef struct s_component component;

struct    s_component
{
  int     id;
};

struct  s_component_class
{
  void  (*constructor)(component *this);
  void  (*destructor)(component *this);
  void  (*send_message)(component *this, message *msg);
};

extern struct s_component_class g_component;

#endif /* !COMPONENT_H_ */
