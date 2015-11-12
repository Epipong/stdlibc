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

# ifdef GENERIC

# define foreach(row, array)  \
  for(iterator (row) = begin(array); (row) != NULL; (row) = (row)->forward)

#  define constructor(x)\
  _Generic((x),                 \
    string: STRING.constructor, \
    list: LIST.constructor,     \
    deque: DEQUE.constructor,   \
    map: MAP.constructor,       \
    vector: VECTOR.constructor)(&x)

#  define destructor(x)         \
  _Generic((x),                 \
    string: STRING.destructor,  \
    list: LIST.destructor,      \
    deque: DEQUE.destructor,    \
    map: MAP.destructor,        \
    vector: VECTOR.destructor)(&x)

#  define new(x)                        \
  if (((x) = calloc(sizeof(*(x)), 1)))  \
    _Generic((x),                       \
      string *: STRING.constructor,     \
      list *: LIST.constructor,         \
      deque *: DEQUE.constructor,       \
      map *: MAP.constructor,           \
      vector *: VECTOR.constructor)(x); \
  else                                  \
    abort()

#  define delete(x)                   \
  _Generic((x),                       \
    string *: STRING.destructor,      \
    list *: LIST.destructor,          \
    deque *: DEQUE.destructor,        \
    map *: MAP.destructor,            \
    vector *: VECTOR.destructor)(x);  \
  free((x))

#  define begin(x)        \
  _Generic((x),           \
    string: STRING.begin, \
    list: LIST.begin,     \
    deque: DEQUE.begin,   \
    map: MAP.begin,       \
    vector: VECTOR.begin)(&x)

#  define end(x)        \
  _Generic((x),         \
    string: STRING.end, \
    list: LIST.end,     \
    deque: DEQUE.end,   \
    map: MAP.end,       \
    vector: VECTOR.end)(&x)

#  define empty(x)        \
  _Generic((x),           \
    deque: DEQUE.empty,   \
    list: LIST.empty,     \
    map: MAP:empty        \
    string: STRING.empty  \
    vector: VECTOR.empty)(&x)

#  define size(x)         \
  _Generic((x),           \
    string: STRING.size,  \
    list: LIST.size,      \
    deque: DEQUE.size,    \
    map: MAP.size,        \
    vector: VECTOR.size)(&x)

#  define max_size(x)       \
  _Generic((x),             \
    list: LIST.max_size,    \
    deque: DEQUE.max_size,  \
    map: MAP.max_size,      \
    vector: VECTOR.max_size)(&x)

#  define resize(x)         \
  _Generic((x),             \
    string: STRING.resize,  \
    deque: DEQUE.resize,    \
    vector: VECTOR.resize)(&x)

#  define capacity(x)         \
  _Generic((x),               \
    vector: VECTOR.capacity,  \
    string: STRING.capacity)(&x)

#  define clear(x)        \
  _Generic((x),           \
    string: STRING.clear, \
    list: LIST.clear,     \
    deque: DEQUE.clear,   \
    map: MAP.clear,       \
    vector: VECTOR.clear)(&x)

#  define at(x, y, type)  \
  *((type *)(_at(x, y)))

#  define _at(x, y)       \
  _Generic((x),           \
    string: STRING.at,    \
    deque: DEQUE.at,      \
    map: MAP.at,          \
    vector: VECTOR.at)(&x, y)

#  define assign(x, y, z)   \
  _Generic((x),             \
    string: STRING.assign,  \
    list: LIST.assign,      \
    deque: DEQUE.assign,    \
    vector: VECTOR.assign)(&x, y, z)

#  define insert(x, y, z)   \
  _Generic((x),             \
    string: STRING.insert,  \
    list: LIST.insert,      \
    deque: DEQUE.insert,    \
    map: MAP.insert,        \
    vector: VECTOR.insert)(&x, y, z)

#  define push_front(x, y)  \
  _Generic((x),             \
    list: LIST.push_front,  \
    deque: DEQUE.push_front)(&x, y)

#  define push_back(x, y)     \
  _Generic((x),               \
    string: STRING.push_back, \
    list: LIST.push_back,     \
    deque: DEQUE.push_back,   \
    vector: VECTOR.push_back)(&x, y)

#  define pop_front(x)    \
  _Generic((x),           \
    list: LIST.pop_front, \
    deque: DEQUE.pop_front)(&x)

#  define pop_back(x)       \
  _Generic((x),             \
    list: LIST.pop_back,    \
    deque: DEQUE.pop_back,  \
    vector: VECTOR.pop_back)(&x)

#  define front(x)      \
  _Generic((x),         \
    list: LIST.front,   \
    deque: DEQUE.front, \
    vector: VECTOR.front)(&x)

#  define back(x)       \
  _Generic((x),         \
    list: LIST.back,    \
    deque: DEQUE.back,  \
    vector: VECTOR.back)(&x)

# define reserve(x, y)  \
  _Generic((x),         \
    vector: VECTOR.reserve)(&x, y)

# define get(x, type) (*((type *)(x)->value))
# define put(x, type) ((type []){x})
# define value(x)     ((x)->value)

# endif /* !GENERIC */

#endif /* !STD_H_ */
