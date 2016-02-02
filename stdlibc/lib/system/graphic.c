#include "system/graphic.h"

static void constructor(graphic *this)
{
}

static void destructor(graphic *this)
{
}

static void update(graphic *this, float datetime)
{
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
