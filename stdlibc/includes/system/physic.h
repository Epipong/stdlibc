#ifndef PHYSIC_H_
# define PHYSIC_H_

# include "message/message.h"
# include "std.h"

typedef struct s_physic physic;

struct    s_physic
{
};

struct s_physic_class
{
  void (*constructor)(physic *this);
  void (*destructor)(physic *this);

  void (*update)(physic *this, float datetime);
  void (*init)(physic *this);
  void (*send_message)(physic *this, message *msg);
};

extern struct s_physic_class  g_physic;

#endif /* !PHYSIC_H_ */
