#ifndef STD_H_
# define STD_H_

# include "_string.h"
# include "list.h"
# include "deque.h"

typedef struct		s_namespace
{
  struct s_string_class	*string;
  struct s_list_class	*list;
  struct s_deque_class	*deque;
  string		*(*to_string)(int val);
}			namespace;

extern struct s_namespace	std;

# define STRING	(*std.string)
# define LIST	(*std.list)
# define DEQUE	(*std.deque)

#endif /* !STD_H_ */
