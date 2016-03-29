#ifndef UI_H_
# define UI_H_

# include <SFML/System.h>

# include "message/message.h"
# include "std.h"

typedef struct s_ui ui;

struct    s_ui
{
};

struct s_ui_class
{
  void (*constructor)(ui *this);
  void (*destructor)(ui *this);

  void (*update)(ui *this, sfTime datetime, list *objects);
  void (*init)(ui *this);
  void (*send_message)(ui *this, message *msg);
};

extern struct s_ui_class  g_ui;

#endif /* !UI_H_ */
