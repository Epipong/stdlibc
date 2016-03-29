#include "manager/sprite.h"

static void constructor(sprite_manager *this)
{
}

static void destructor(sprite_manager *this)
{
}

struct s_sprite_manager_class g_sprite_manager = {
  &constructor,
  &destructor
};
