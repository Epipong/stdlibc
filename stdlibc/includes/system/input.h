#ifndef INPUT_H_
# define INPUT_H_

# include "message/message.h"
# include "std.h"

typedef struct s_input input;

struct    s_input
{
};

struct s_input_class
{
  void (*constructor)(input *this);
  void (*destructor)(input *this);

  void (*update)(input *this, float datetime);
  void (*init)(input *this);
  void (*send_message)(input *this, message *msg);
};

extern struct s_input_class g_input;

#endif /* !INPUT_H_ */
