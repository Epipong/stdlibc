#ifndef ITERATOR_H_
# define ITERATOR_H_

# include "bits/helper.h"

typedef struct s_iterator *	iterator;

struct		s_iterator
{
  value_type	value;
  iterator	forward;
  iterator	rewind;
};

struct		s_node
{
  key_type	key;
  value_type	value;
};

# define INCREMENT_IT(x)	((x) = (x)->forward)
# define DECREMENT_IT(x)	((x) = (x)->forward)

#endif /* :ITERATOR_H_ */
