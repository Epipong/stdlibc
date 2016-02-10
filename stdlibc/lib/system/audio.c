#include "system/audio.h"

static void constructor(audio *this)
{
}

static void destructor(audio *this)
{
}

static void update(audio *this, sfTime datetime, list objects)
{
}

static void init(audio *this)
{
}

static void send_message(audio *this, message *msg)
{
}

struct s_audio_class  g_audio = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
