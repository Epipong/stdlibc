#ifndef VECTOR_H_
# define VECTOR_H_

# include <stdlib.h>
# include <stdbool.h>
# include "iterator.h"

typedef struct s_vector	vector;

struct		s_vector
{
  void		**array;
  size_type	size;
};

struct		s_vector_class
{
  void		(*constructor)(vector *this);
  void		(*destructor)(vector *this);

  iterator	(*begin)(vector *this);
  iterator	(*end)(vector *this);

  size_type	(*size)(vector *this);
  size_type	(*max_size)(vector *this);
  void		(*resize)(vector *this, size_type n);
  size_t	(*capacity)(vector *this);
  bool		(*empty)(vector *this);
  void		(*reserve)(vector *this, size_type n);

  void		*(*at)(vector *this, size_type n);
  void		*(*front)(vector *this);
  void		*(*back)(vector *this);

  void		(*assign)(vector *this, InputIterator first, InputIterator last);
  void		(*push_back)(vector *this, const value_type val);
  void		(*pop_back)(vector *this);
  iterator	(*insert)(vector *this, iterator position, const value_type val);
  iterator	(*erase)(vector *this, iterator position);
  void		(*swap)(vector *this, vector *x);
  void		(*clear)(vector *this);
};

extern struct s_vector_class	g_vector;

#endif /* !VECTOR_H_ */
