#include <string.h>
#include <stdio.h>

#include "graphic/sprite.h"

static void constructor(sprite_graphic *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  this->is_paused = true;
  this->is_looped = false;
  this->frame_time = sfSeconds(.125f);
  this->sprite = sfSprite_create();
}

static void destructor(sprite_graphic *this)
{
  sfSprite_destroy(this->sprite);
}

static void update(sprite_graphic *this, sfTime delta_time)
{
  if (!this->is_paused && this->action != NULL)
  {
    this->current_time.microseconds += delta_time.microseconds;
    if (this->current_time.microseconds >= this->frame_time.microseconds)
    {
      this->current_time.microseconds = \
        sfTime_asMicroseconds(this->current_time) %
        sfTime_asMicroseconds(this->frame_time);
      if (this->current_frame + 1 < g_vector.size(&this->action->frames))
        ++this->current_frame;
      else
      {
        this->current_frame = 1;
        if (!this->is_looped)
          this->is_paused = true;
      }
      g_sprite_graphic.set_frame(this, this->current_frame, false);
    }
  }
}

static void set_animation(sprite_graphic *this, animation const *action)
{
  if (action == NULL)
    return ;
  this->action = action;
  this->texture = action->texture;
  this->current_frame = 0;
  g_sprite_graphic.set_frame(this, this->current_frame, true);
  sfSprite_setTexture(this->sprite, this->texture, false);
  sfSprite_setTextureRect(this->sprite, g_animation.get_frame(this->action, this->current_frame));
}

static void play(sprite_graphic *this, animation const *action)
{
  if (action != NULL && this->action != action)
    this->action = action;
  this->is_paused = false;
}

static void pause(sprite_graphic *this)
{
  this->is_paused = true;
}

static void stop(sprite_graphic *this)
{
  this->is_paused = true;
  this->current_frame = 0;
  g_sprite_graphic.set_frame(this, 0, true);
}

static void set_color(sprite_graphic *this, sfColor const color)
{
  sfSprite_setColor(this->sprite, color);
}

static sfFloatRect  get_local_bounds(sprite_graphic *this)
{
  return (sfSprite_getLocalBounds(this->sprite));
}

static sfFloatRect  get_global_bounds(sprite_graphic *this)
{
  sfIntRect         rect;
  float             width;
  float             height;

  rect = g_animation.get_frame(this->action, this->current_frame);
  width = (float)(abs(rect.width));
  height = (float)(abs(rect.height));
  return (sfFloatRect){0.f, 0.f, width, height};
}

static void set_frame(sprite_graphic *this, size_t new_frame, bool reset_time)
{
  if (this->action != NULL)
  {
    sfIntRect rect = g_animation.get_frame(this->action, new_frame);
    sfSprite_setTextureRect(this->sprite, rect);
    sfSprite_setOrigin(this->sprite, (sfVector2f){rect.width / 2, 10});
  }
  if (reset_time)
    this->current_time = sfTime_Zero;
}

static void draw(sprite_graphic *this, sfRenderWindow *target, sfRenderStates *states)
{
  sfRenderWindow_drawSprite(target, this->sprite, states);
}

static void move(sprite_graphic *this, sfVector2f offset)
{
  sfSprite_move(this->sprite, offset);
}

static void set_position(sprite_graphic *this, sfVector2f position)
{
  sfSprite_setPosition(this->sprite, position);
}

static void set_scale(sprite_graphic *this, sfVector2f scale)
{
  sfSprite_setScale(this->sprite, scale);
}

struct s_sprite_graphic_class g_sprite_graphic = {
  &constructor,
  &destructor,
  &update,
  &set_animation,
  &play,
  &pause,
  &stop,
  &set_color,
  &get_local_bounds,
  &get_global_bounds,
  &set_frame,
  &draw,
  &move,
  &set_position,
  &set_scale
};
