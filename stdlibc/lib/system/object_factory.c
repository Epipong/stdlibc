#include "system/object_factory.h"

static void constructor(object_factory *this)
{
}

static void destructor(object_factory *this)
{
}

static void update(object_factory *this, sfTime datetime, list *objects)
{
}

static void init(object_factory *this)
{
}

static void send_message(object_factory *this, message *msg)
{
}

struct s_object_factory_class g_object_factory = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
