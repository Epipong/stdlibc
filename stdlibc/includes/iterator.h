/*
** iterator.h for iterator in /home/davy/Rendu/stdlibc/stdlibc
** 
** Made by davy tran
** Login   <tran_yepitech.net>
** 
** Started on  Wed Feb  4 14:44:46 2015 davy tran
** Last update Thu Feb 12 00:27:43 2015 davy tran
*/

#ifndef ITERATOR_H_
# define ITERATOR_H_

# include "bits/helper.h"

typedef struct s_iterator *	iterator;
typedef struct s_p_iterator *	p_iterator;
typedef struct s_node *		node;

struct		s_node
{
  key_type	key;
  p_iterator	content;
  node		left;
  node		right;
};

/*
** iterator structure use for chained list (e.g., deque, list or vector)
*/
struct		s_iterator
{
  value_type	value;
  iterator	forward;
  iterator	rewind;
};

/*
** iterator structure use for pair list (e.g., map)
*/
struct		s_p_iterator
{
  value_type	second;
  p_iterator	forward;
  p_iterator	rewind;
  key_type	first;
};

# define INCREMENT_IT(x)	((x) = (x)->forward)
# define DECREMENT_IT(x)	((x) = (x)->rewind)

#endif /* !ITERATOR_H_ */
