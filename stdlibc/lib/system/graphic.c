#include <string.h>
#include <stdio.h>
#include <SFML/System.h>

#include "config.h"
#include "system/graphic.h"

static void constructor(graphic *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  this->video_mode = (sfVideoMode){ WIDTH, HEIGHT, BITSPERPIXEL };
  this->render_window = sfRenderWindow_create(this->video_mode, TITLE,
                                              STYLE, NULL);
}

static void destructor(graphic *this)
{
  if (this->render_window != NULL)
    sfRenderWindow_destroy(this->render_window);
}

static void update(graphic *this, sfTime datetime, list objects)
{
  sfEvent   event;

  if (sfRenderWindow_isOpen(this->render_window))
  {
    sfRenderWindow_clear(this->render_window, sfBlack);
    sfRenderWindow_display(this->render_window);
    while (sfRenderWindow_waitEvent(this->render_window, &event))
    {
      if (event.type == sfEvtClosed)
        sfRenderWindow_close(this->render_window);
    }
  }
}

static void init(graphic *this)
{
}

static void send_message(graphic *this, message *msg)
{
}

struct s_graphic_class g_graphic = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
