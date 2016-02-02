/*
** std.h for vector in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_yepitech.net>
**
** Started on  Wed Feb  4 14:45:10 2015 davy tran
** Last update Wed Sep 30 17:25:23 2015 davy
*/

#ifndef STD_H_
# define STD_H_

# include "_string.h"
# include "list.h"
# include "deque.h"
# include "map.h"
# include "vector.h"

typedef struct s_namespace  namespace;

struct                  s_namespace
{
  struct s_string_class *string;
  struct s_list_class   *list;
  struct s_deque_class  *deque;
  struct s_map_class    *map;
  struct s_vector_class *vector;
  string                *(*to_string)(int val);
};

extern namespace  std;

# define STRING (*std.string)
# define LIST   (*std.list)
# define DEQUE  (*std.deque)
# define MAP    (*std.map)
# define VECTOR (*std.vector)

#endif /* !STD_H_ */
