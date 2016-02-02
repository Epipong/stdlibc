#ifndef AUDIO_H_
# define AUDIO_H_

# include "message/message.h"
# include "std.h"

typedef struct s_audio audio;

struct  s_audio
{
};

struct  s_audio_class
{
  void  (*constructor)(audio *this);
  void  (*destructor)(audio *this);

  void  (*update)(audio *this, float datetime);
  void  (*init)(audio *this);
  void  (*send_message)(audio *this, message *msg);
};

extern struct s_audio_class g_audio;

#endif /* !AUDIO_H_ */
