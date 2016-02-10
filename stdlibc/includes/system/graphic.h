#ifndef GRAPHIC_H_
# define GRAPHIC_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <SFML/System.h>

# include "message/message.h"
# include "std.h"

typedef struct s_graphic graphic;

struct            s_graphic
{
  sfVideoMode     video_mode;
  sfRenderWindow  *render_window;
};

struct s_graphic_class
{
  void (*constructor)(graphic *this);
  void (*destructor)(graphic *this);

  void (*update)(graphic *this, sfTime datetime, list objects);
  void (*init)(graphic *this);
  void (*send_message)(graphic *this, message *msg);
};

extern struct s_graphic_class g_graphic;

#endif /* !GRAPHIC_H_ */
