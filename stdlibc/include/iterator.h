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

#endif /* :ITERATOR_H_ */
