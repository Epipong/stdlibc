/*
** vector.c for vector in /home/davy/Rendu/stdlibc/stdlibc
** 
** Made by davy tran
** Login   <tran_y@epitech.net>
** 
** Started on  Wed Feb  4 19:22:11 2015 davy tran
** Last update Thu Feb 12 00:31:55 2015 davy tran
*/

#include <string.h>
#include "vector.h"

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
  return (this->size > 0 ? this->content[this->size] : NULL);
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
  return (size(this));
}

static void		resize(vector *this, size_type n)
{
  size_type		len;

  if (n < (len = size(this)))
    this->content[n] = NULL;
  this->size = 1;
  while (this->size <= n)
    this->size <<= 1;
  if ((this->content = realloc(this->content, this->size)) == NULL)
    this->size = 0;
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
  return (n >= this->size ? this->content[n] : NULL);
}

static void		*front(vector *this)
{
  return (at(this, 0));
}

static void		*back(vector *this)
{
  size_type		n;

  n = size(this);
  return (n > 0 ? at(this, n - 1) : NULL);
}

static void		assign(__attribute__((unused))vector *this, InputIterator first, InputIterator last)
{
  iterator		it;

  it = first;
  while (it != last && it != NULL)
    INCREMENT_IT(it);
}

static void		push_back(__attribute__((unused))vector *this, __attribute__((unused))const value_type val)
{
}

static void		pop_back(__attribute__((unused))vector *this)
{
}

static iterator		insert(__attribute__((unused))vector *this, __attribute__((unused))iterator position, __attribute__((unused))const value_type val)
{
  return (NULL);
}

static iterator		erase(__attribute__((unused))vector *this, __attribute__((unused))iterator position)
{
  return (NULL);
}

static void		swap(__attribute__((unused))vector *this, __attribute__((unused))vector *x)
{
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
