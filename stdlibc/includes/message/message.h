#ifndef MESSAGE_H_
# define MESSAGE_H_

typedef struct s_message  message;

struct  s_message
{
  int   id;
};

struct  s_message_class
{
  void  (*constructor)(message *this);
  void  (*destructor)(message *this);
};

extern struct s_message_class g_message;

#endif /* !MESSAGE_H_ */
