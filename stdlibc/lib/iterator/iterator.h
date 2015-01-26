#ifndef ITERATOR_H_
# define ITERATOR_H_

typedef struct s_iterator *	iterator;
typedef void *			InputIterator;
typedef void *			pointer;
typedef void *			value_type;
typedef size_t			size_type;

struct		s_iterator
{
  value_type	value;
  iterator	forward;
  iterator	rewind;
};

#endif /* :ITERATOR_H_ */
