/*
** std.h for vector in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_yepitech.net>
**
** Started on  Wed Feb  4 14:45:10 2015 davy tran
** Last update Wed Sep 23 16:14:31 2015 davy
*/

#ifndef STD_H_
# define STD_H_

# include "_string.h"
# include "list.h"
# include "deque.h"
# include "map.h"
# include "vector.h"

typedef struct s_namespace
{
  struct s_string_class	*string;
  struct s_list_class	*list;
  struct s_deque_class	*deque;
  struct s_map_class	*map;
  struct s_vector_class	*vector;
  string		*(*to_string)(int val);
} namespace;

extern namespace	std;

# define STRING	(*std.string)
# define LIST	(*std.list)
# define DEQUE	(*std.deque)
# define MAP	(*std.map)
# define VECTOR	(*std.vector)

# define constructor(x)				\
  _Generic((x),					\
	   string: STRING.constructor,		\
	   list: LIST.constructor,		\
	   deque: DEQUE.constructor,		\
	   map: MAP.constructor,		\
	   vector: VECTOR.constructor)(&x)

# define destructor(x)				\
  _Generic((x),					\
	   string: STRING.destructor,		\
	   list: LIST.destructor,		\
	   deque: DEQUE.destructor,		\
	   map: MAP.destructor,			\
	   vector: VECTOR.destructor)(&x)

# define new(x)					\
  if (((x) = calloc(sizeof(*(x)), 1)))		\
    _Generic((x),				\
	     string *: STRING.constructor,	\
	     list *: LIST.constructor,		\
	     deque *: DEQUE.constructor,	\
	     map *: MAP.constructor,		\
	     vector *: VECTOR.constructor)(x)

# define delete(x)				\
  _Generic((x),					\
	   string *: STRING.destructor,		\
	   list *: LIST.destructor,		\
	   deque *: DEQUE.destructor,		\
	   map *: MAP.destructor,		\
	   vector *: VECTOR.destructor)(x);	\
  free((x))

# define begin(x)				\
  _Generic((x),					\
	   string: STRING.begin,		\
	   list: LIST.begin,			\
	   deque: DEQUE.begin,			\
	   map: MAP.begin,			\
	   vector: VECTOR.begin)(&x)

# define end(x)					\
  _Generic((x),					\
	   string: STRING.end,			\
	   list: LIST.end,			\
	   deque: DEQUE.end,			\
	   map: MAP.end,			\
	   vector: VECTOR.end)(&x)

# define clear(x)				\
  _Generic((x),					\
	   string: STRING.clear,		\
	   list: LIST.clear,			\
	   deque: DEQUE.clear,			\
	   map: MAP.clear,			\
	   vector: VECTOR.clear)(&x)

# define insert(x, y, z)			\
  _Generic((x),					\
	   string: STRING.insert,		\
	   list: LIST.insert,			\
	   deque: DEQUE.insert,			\
	   map: MAP.insert,			\
	   vector: VECTOR.insert)(&x, y, z)

#endif /* !STD_H_ */
