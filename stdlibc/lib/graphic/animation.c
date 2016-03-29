#include <string.h>

#include "graphic/animation.h"

static void constructor(animation *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  g_vector.constructor(&this->frames);
}

static void destructor(animation *this)
{
  sfIntRect *frame;

  for (iterator it = g_vector.begin(&this->frames); it != NULL;
       it = it->forward)
  {
    frame = it->value;
    free(frame);
  }
  g_vector.destructor(&this->frames);
}

static void add_frame(animation *this, sfIntRect rect)
{
  sfIntRect *frame;

  if ((frame = calloc(1, sizeof(*frame))) == NULL)
    exit(EXIT_FAILURE);
  memcpy(frame, &rect, sizeof(rect));
  g_vector.push_back(&this->frames, frame);
}

static sfIntRect get_frame(animation const *this, size_t n)
{
  return *((sfIntRect *)(g_vector.at(&this->frames, n)));
}

struct s_animation_class  g_animation = {
  &constructor,
  &destructor,
  &add_frame,
  &get_frame
};
