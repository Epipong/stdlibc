#include "system/game_logic.h"

static void constructor(game_logic *this)
{
}

static void destructor(game_logic *this)
{
}

static void update(game_logic *this, sfTime datetime, list objects)
{
}

static void init(game_logic *this)
{
}

static void send_message(game_logic *this, message *msg)
{
}

struct s_game_logic_class g_game_logic = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
