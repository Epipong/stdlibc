#include <stdio.h>
#include <string.h>

#include "config.h"
#include "system/system.h"
#include "system/input.h"

static void constructor(input *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  this->video_mode = (sfVideoMode){WIDTH, HEIGHT, BITSPERPIXEL};
  this->render_window = sfRenderWindow_create(this->video_mode, TITLE,
                                              STYLE, NULL);
  if (this->render_window == NULL)
    exit(EXIT_FAILURE);
  sfRenderWindow_setFramerateLimit(this->render_window, FRAMERATE_LIMIT);

  sora_ctor(&this->sora);
  g_sprite_graphic.constructor(&this->anim);
  g_sprite_graphic.set_animation(&this->anim, g_map.at(&this->sora.animations, "down"));
  g_sprite_graphic.set_position(&this->anim, (sfVector2f){WIDTH >> 1, 100});
  g_sprite_graphic.set_scale(&this->anim, (sfVector2f){8, 8});

  animation *action = g_map.at(&this->sora.animations, "down");
}

static void destructor(input *this)
{
  if (this->render_window != NULL)
    sfRenderWindow_destroy(this->render_window);

  sora_dtor(&this->sora);
  g_sprite_graphic.destructor(&this->anim);
}

static void _key(input *this)
{
  if (sfKeyboard_isKeyPressed(sfKeyDown) && this->event.type == sfEvtKeyPressed)
    g_sprite_graphic.play(&this->anim, NULL);
  else if (this->event.type == sfEvtKeyReleased)
    g_sprite_graphic.stop(&this->anim);
}

static void _joystick(input *this)
{
  if (sfJoystick_isConnected(0) && false)
  {
    unsigned int c = sfJoystick_getButtonCount(0);
    for (unsigned int i = 0; i < c; ++i)
      printf("%d -> %s\n", i, sfJoystick_isButtonPressed(0, i) ? "true" : "false");
  }
}

static void _mouse(input *this)
{
  for (unsigned int i = 0; i < sfMouseButtonCount; ++i)
  {
    if (sfMouse_isButtonPressed(i) && this->event.type == sfEvtMouseButtonPressed)
      printf("mouse button %d is pressed\n", i);
  }
}

static void _window(input *this)
{
  if (this->event.type == sfEvtClosed)
  {
    sfRenderWindow_close(this->render_window);
    g_input.send_message(this, &((message){0}));
  }
}

static void _text(input *this)
{
  if (this->event.type == sfEvtTextEntered)
    printf("%u\n", this->event.text.unicode);
}

static void update(input *this, sfTime datetime, list *objects)
{
  if (sfRenderWindow_isOpen(this->render_window))
  {
    sfRenderWindow_clear(this->render_window, sfBlack);
    if (sfWindow_pollEvent((sfWindow *)this->render_window, &this->event))
    {
      _key(this);
      _joystick(this);
      _mouse(this);
      _window(this);
      _text(this);
    }
    g_sprite_graphic.update(&this->anim, datetime);
    g_sprite_graphic.draw(&this->anim, this->render_window, NULL);
    sfRenderWindow_display(this->render_window);
  }
}

static void init(input *this)
{
}

static void send_message(input *this, message *msg)
{
  if (msg->id == 0)
  {
    g_is_run = false;
  }
}

struct s_input_class g_input = {
  &constructor,
  &destructor,
  &update,
  &init,
  &send_message
};
