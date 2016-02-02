#include <stdio.h>
#include "system/input.h"

static void constructor(input *this)
{
}

static void destructor(input *this)
{
}

static void update(input *this, float datetime)
{
  printf("input update\n");
}

static void init(input *this)
{
}

static void send_message(input *this, message *msg)
{
}

struct s_input_class g_input = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
