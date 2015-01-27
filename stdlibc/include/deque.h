/*
** deque.h for deque in /home/tran_y/Templates/C/libs/libdeque
**
** Made by davy tran
** Login   <tran_y@epitech.net>
**
** Started on  Tue Apr 29 17:02:08 2014 davy tran
** Last update Wed Jul  2 02:33:44 2014 davy tran
*/

#ifndef		DEQUE_H_
# define	DEQUE_H_

# include	<stdlib.h>
# include	<stdbool.h>
# include	"iterator.h"

typedef struct s_deque	deque;

struct		s_deque
{
  iterator	content;
  size_type	size;
};

struct		s_deque_class
{
  void		(*constructor)(deque *this);
  void		(*destructor)(deque *this);

  iterator	(*begin)(deque *this);
  iterator	(*end)(deque *this);

  size_type	(*size)(deque *this);
  size_type	(*max_size)(deque *this);
  void		(*resize)(deque *this, size_type n);
  bool		(*empty)(deque *this);

  void		*(*at)(deque *this, size_type n);
  void		*(*front)(deque *this);
  void		*(*back)(deque *this);

  void		(*assign)(deque *this, InputIterator first, InputIterator last);
  void		(*push_back)(deque *this, const value_type val);
  void		(*push_front)(deque *this, const value_type val);
  void		(*pop_back)(deque *this);
  void		(*pop_front)(deque *this);
  iterator	(*insert)(deque *this, iterator position, const value_type val);
  iterator	(*erase)(deque *this, iterator position);
  void		(*swap)(deque *this, deque *x);
  void		(*clear)(deque *this);
};

extern struct s_deque_class	g_deque;

#endif		/* !DEQUE_H_ */
