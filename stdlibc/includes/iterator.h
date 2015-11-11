/*
** iterator.h for iterator in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_yepitech.net>
**
** Started on  Wed Feb  4 14:44:46 2015 davy tran
** Last update Wed Sep 30 15:43:17 2015 davy
*/

#ifndef ITERATOR_H_
# define ITERATOR_H_

# include "bits/helper.h"

typedef struct s_iterator *   iterator;
typedef struct s_p_iterator * p_iterator;
typedef struct s_node *       node;

typedef iterator    InputIterator;

/*
** Node structure use for binary tree.
**
** Attributes:
**  key (key_type) -- Key access to data stored.
**  content (p_iterator) -- Content pair (first and second).
**  left (node) -- Left node of binary tree.
**  right (node) -- Right node of binary tree.
*/
struct        s_node
{
  key_type    key;
  p_iterator  content;
  node        left;
  node        right;
};

/*
** iterator structure use for chained list (e.g., deque, list or vector).
**
** Attributes:
**  value (value_type) -- Data stored.
**  forward (iterator) -- Pointer of next element.
**  rewind (iterator) -- Pointer of previous element.
*/
struct        s_iterator
{
  value_type  value;
  iterator    forward;
  iterator    rewind;
};

/*
** iterator structure use for pair list (e.g., map)
**
** Attributes:
**  second (value_type) -- Data right of element.
**  forward (iterator) -- Pointer of next element.
**  rewind (iterator) -- Pointer of previous element.
**  first (value_type) -- Data left of element.
*/
struct        s_p_iterator
{
  value_type  second;
  p_iterator  forward;
  p_iterator  rewind;
  key_type    first;
};

# define next(x)        ((x) = (x)->forward)
# define previous(x)    ((x) = (x)->rewind)

#endif /* !ITERATOR_H_ */
