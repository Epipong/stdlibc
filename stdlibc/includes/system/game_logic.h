#ifndef GAME_LOGIC_H_
# define GAME_LOGIC_H_

# include "message/message.h"
# include "std.h"

typedef struct s_game_logic game_logic;

struct    s_game_logic
{
};

struct  s_game_logic_class
{
  void  (*constructor)(game_logic *this);
  void  (*destructor)(game_logic *this);

  void  (*update)(game_logic *this, float datetime);
  void  (*init)(game_logic *this);
  void  (*send_message)(game_logic *this, message *msg);
};

extern struct s_game_logic_class  g_game_logic;

#endif /* !GAME_LOGIC_H_ */
