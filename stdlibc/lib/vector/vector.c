/*
** vector.c for vector in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_y@epitech.net>
**
** Started on  Wed Feb  4 19:22:11 2015 davy tran
** Last update Tue Sep 29 17:29:04 2015 davy
*/

#include <string.h>
#include "vector.h"

static void		_link(vector *this)
{
  size_t		i;

  i = 0;
  if (this->content != NULL)
    while (this->content[i] != NULL)
    {
      if (this->content[i] != NULL)
	this->content[i]->forward = this->content[i + 1];
      if (this->content[i + 1] != NULL)
	this->content[i + 1]->rewind = this->content[i];
      ++i;
    }
}

static void		constructor(vector *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
}

static void		destructor(vector *this)
{
  if (this == NULL)
    return ;
  g_vector.clear(this);
}

static iterator		begin(vector *this)
{
  return (this != NULL && this->content != NULL ? this->content[0] : NULL);
}

static iterator		end(vector *this)
{
  return (this->size > 0 ? this->content[this->size - 1] : NULL);
}

static size_type	size(vector *this)
{
  size_type		n;

  n = 0;
  while (this->content != NULL && this->content[n] != NULL)
    ++n;
  return (n);
}

static size_type	max_size(vector *this)
{
  return (this->size);
}

static void		resize(vector *this, size_type n)
{
  size_type		len;

  if (n < (len = size(this)))
    this->content[n] = NULL;
  this->size = 1;
  while (this->size <= n)
    this->size <<= 1;
  if ((this->content = realloc(this->content, this->size * sizeof(*this->content))) == NULL)
    this->size = 0;
  while (len < this->size)
  {
    this->content[len] = NULL;
    ++len;
  }
  _link(this);
}

static size_t		capacity(vector *this)
{
  return (this->size);
}

static bool		empty(vector *this)
{
  return (this->content == NULL || this->size == 0);
}

static void		reserve(__attribute__((unused))vector *this, __attribute__((unused))size_type n)
{
}

static void		*at(vector *this, size_type n)
{
  return (this->content != NULL ? this->content[n]->value : NULL);
}

static void		*front(vector *this)
{
  return (at(this, 0));
}

static void		*back(vector *this)
{
  return (this->content != NULL ? at(this, size(this) - 1) : NULL);
}

static void		assign(vector *this, InputIterator first, InputIterator last)
{
  iterator		it;

  it = first;
  (void)this;
  while (it != last && it != NULL)
  {
    INCREMENT_IT(it);
  }
}

static void		push_back(vector *this, const value_type val)
{
  size_type		len;
  iterator		it;

  len = size(this);
  if ((len + 1) >= max_size(this))
    resize(this, len + 1);
  if ((it = calloc(sizeof(*it), 1)) == NULL)
    exit(EXIT_FAILURE);
  it->value = val;
  if (len != 0)
  {
    this->content[len]->forward = it;
    it->rewind = this->content[len];
  }
  else
    this->content[0] = it;
}

static void		pop_back(vector *this)
{
  iterator		it;
  size_t		n;

  if ((it = g_vector.end(this)) != NULL && it->rewind != NULL)
  {
    it->rewind->forward = NULL;
    free(it);
    if ((n = size(this)) > 0)
      this->content[n - 1] = NULL;
  }
  else if (it != NULL && it->rewind == NULL)
    it->value = NULL;
}

static iterator		insert(__attribute__((unused))vector *this, __attribute__((unused))iterator position, __attribute__((unused))const value_type val)
{
  return (NULL);
}

static iterator		erase(__attribute__((unused))vector *this, __attribute__((unused))iterator position)
{
  return (NULL);
}

static void		swap(vector *this, vector *x)
{
  SWAP_PTR(this->content, x->content);
}

static void		clear(__attribute__((unused))vector *this)
{
}

struct s_vector_class	g_vector = {
  &constructor,
  &destructor,
  &begin,
  &end,
  &size,
  &max_size,
  &resize,
  &capacity,
  &empty,
  &reserve,
  &at,
  &front,
  &back,
  &assign,
  &push_back,
  &pop_back,
  &insert,
  &erase,
  &swap,
  &clear
};
