#include "component/component.h"

static void constructor(component *this)
{
}

static void destructor(component *this)
{
}

static void send_message(component *this, message *msg)
{
}

struct s_component_class	g_component = {
  &constructor,
  &destructor,
  &send_message
};
