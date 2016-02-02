#include "system/ui.h"

static void constructor(ui *this)
{
}

static void destructor(ui *this)
{
}

static void update(ui *this, float datetime)
{
}

static void init(ui *this)
{
}

static void send_message(ui *this, message *msg)
{
}

struct s_ui_class g_ui = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
