#include "system/physic.h"

static void constructor(physic *this)
{
}

static void destructor(physic *this)
{
}

static void update(physic *this, float datetime)
{
}

static void init(physic *this)
{
}

static void send_message(physic *this, message *msg)
{
}

struct s_physic_class g_physic = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
