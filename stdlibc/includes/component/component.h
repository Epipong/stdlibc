#ifndef COMPONENT_H_
# define COMPONENT_H_

# include "std.h"

typedef struct s_component component;

struct    s_component
{
};

struct  s_component_class
{
  void  (*constructor)(component *this);
  void  (*destructor)(component *this);
};

extern struct s_component_class g_component;

#endif /* !COMPONENT_H_ */
