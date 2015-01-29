#ifndef ITERATOR_H_
# define ITERATOR_H_

# include "bits/helper.h"

typedef struct s_iterator *	iterator;
typedef struct s_node *		node;

struct		s_node
{
  key_type	key;
  iterator	content;
  node		left;
  node		right;
};

struct		s_iterator
{
  value_type	value;
  iterator	forward;
  iterator	rewind;
};

# define INCREMENT_IT(x)	((x) = (x)->forward)
# define DECREMENT_IT(x)	((x) = (x)->forward)

#endif /* :ITERATOR_H_ */
