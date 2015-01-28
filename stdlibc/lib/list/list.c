#include <string.h>
#include "list.h"

static int const	g_default_val = 0;

static void		constructor(list *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  if ((this->content = calloc(sizeof(*(this->content)), 1)) == NULL)
    exit(EXIT_FAILURE);
  this->size = 0;
}

static void		destructor(list *this)
{
  if (this == NULL)
    return ;
  g_list.clear(this);
  if (this->content != NULL)
    free(this->content);
  this->content = NULL;
}

static iterator		begin(list *this)
{
  iterator		begin;

  begin = this->content;
  while (begin != NULL && begin->rewind != NULL)
    begin = begin->rewind;
  return (begin);
}

static iterator		end(list *this)
{
  iterator		end;

  end = this->content;
  while (end != NULL && end->forward != NULL)
    end = end->forward;
  return (end);
}

static bool		empty(list *this)
{
  return (!this || !this->content || !this->content->value);
}

static size_type	size(list *this)
{
  iterator		it;
  size_type		n;

  it = g_list.begin(this);
  n = 0;
  while (it != NULL)
  {
    ++n;
    it = it->forward;
  }
  return (n);
}

static size_type	max_size(list *this)
{
  return (g_list.size(this));
}

static void		*front(list *this)
{
  iterator		it;

  it = g_list.begin(this);
  return (it != NULL ? it->value : NULL);
}

static void		*back(list *this)
{
  iterator		it;

  it = g_list.end(this);
  return (it != NULL ? it->value : NULL);
}

static void		assign(list *this, iterator first, iterator last)
{
  iterator		it;

  g_list.clear(this);
  it = first;
  while (it != NULL && it != last)
  {
    g_list.push_back(this, it->value);
    it = it->forward;
  }
}

static void		push_front(list *this, const value_type val)
{
  iterator		it;

  if (g_list.begin(this)->value == NULL)
  {
    g_list.begin(this)->value = val;
    return ;
  }
  if ((it = calloc(sizeof(*it), 1)) == NULL)
    exit(EXIT_FAILURE);
  it->value = val;
  it->rewind = NULL;
  it->forward = NULL;
  if ((this->content = g_list.begin(this)) != NULL)
  {
    this->content->rewind = it;
    it->forward = this->content;
    this->content = it;
  }
}

static void		pop_front(list *this)
{
  if ((this->content = g_list.begin(this)) != NULL && this->content->forward != NULL)
  {
    this->content = this->content->forward;
    free(this->content->rewind);
    this->content->rewind = NULL;
  }
  else if (this->content != NULL && this->content->rewind == NULL)
    this->content->value = NULL;
}

static void		push_back(list *this, const value_type val)
{
  iterator		it;
  iterator		end;

  if ((end = g_list.end(this)) != NULL && end->value == NULL)
  {
    end->value = val;
    return ;
  }
  if ((it = calloc(sizeof(*it), 1)) == NULL)
    exit(EXIT_FAILURE);
  it->value = val;
  it->rewind = NULL;
  it->forward = NULL;
  if (end != NULL)
  {
    end->forward = it;
    it->rewind = end;
  }
  else
    this->content = it;
}

static void		pop_back(list *this)
{
  iterator		it;

  if ((it = g_list.end(this)) != NULL && it->rewind != NULL)
  {
    it->rewind->forward = NULL;
    free(it);
  }
  else if (it != NULL && it->rewind == NULL)
    it->value = NULL;
}

static iterator		insert(list *this, iterator position, const value_type val)
{
  iterator		elem;
  iterator		it;

  if ((elem = calloc(sizeof(*elem), 1)) == NULL)
    exit(EXIT_FAILURE);
  elem->value = val;
  elem->rewind = NULL;
  elem->forward = NULL;
  it = g_list.begin(this);
  while (it != NULL && it->forward != NULL && it != position)
    it = it->forward;
  elem->forward = it->forward;
  elem->rewind = it;
  if (it->forward != NULL)
    it->forward->rewind = elem;
  it->forward = elem;
  return (NULL);
}

static iterator		erase(list *this, iterator position)
{
  iterator		it;
  iterator		tmp;

  it = g_list.begin(this);
  while (it != NULL && it != position)
    it = it->forward;
  if (it != position)
    return (NULL);
  tmp = it->forward;
  if (it->rewind != NULL)
    it->rewind->forward = it->forward;
  if (it->forward != NULL)
    it->forward->rewind = it->rewind;
  free(it);
  return (tmp);
}

static void		swap(list *this, list *x)
{
  this->content = (void *)((size_t)(this->content) ^ (size_t)(x->content));
  x->content = (void *)((size_t)(x->content) ^ (size_t)(this->content));
  this->content = (void *)((size_t)(this->content) ^ (size_t)(x->content));
}

static void		resize(list *this, size_type n)
{
  size_type		i;

  if ((i = g_list.size(this)) == n)
    return ;
  else if (i < n)
  {
    while (i < n)
    {
      g_list.push_back(this, (void *)(&g_default_val));
      ++i;
    }
  }
  else
  {
    while (i > n)
    {
      g_list.pop_back(this);
      --i;
    }
  }
}

static void		clear(list *this)
{
  iterator			it;
  iterator			forward;

  if (g_list.size(this) == 0)
    return ;
  if (g_list.size(this) == 1)
    return ((void)(this->content->value = NULL));
  if ((it = g_list.begin(this))->forward != NULL)
  {
    it->value = NULL;
    it = it->forward;
  }
  while (it != NULL)
  {
    forward = it->forward;
    free(it);
    it = forward;
  }
}

static void		splice(list *this, iterator position, list *x)
{
  iterator		it;
  iterator		tmp;

  if (x == NULL || x->content == NULL)
    return ;
  it = g_list.begin(this);
  while (it != NULL && it->forward != position)
    it = it->forward;
  if (it == NULL)
    return ;
  tmp = it->forward;
  it->forward = x->content;
  x->content->rewind = it;
  it = g_list.end(x);
  if (tmp != NULL)
    tmp->rewind = it;
  if (it != NULL)
    it->forward = tmp;
  x->content = NULL;
}

static void		remove(list *this, const value_type val)
{
  iterator		it;

  it = g_list.begin(this);
  while (it != NULL && it->value != val)
    it = it->value;
  if (it != NULL)
    g_list.erase(this, it);
}

static void		remove_if(list *this, Predicate pred)
{
  iterator		it;

  it = g_list.begin(this);
  while (it != NULL)
  {
    if (pred(it != NULL ? it->value : NULL))
      g_list.erase(this, it);
    it = it->forward;
  }
}

static void		unique(list *this, BinaryPredicate binary_pred)
{
  iterator		it;
  iterator		tmp;

  it = g_list.begin(this);
  while (it != NULL)
  {
    tmp = it->forward;
    while (tmp != NULL)
    {
      tmp = binary_pred(it->value, tmp->value) ? 
	g_list.erase(this, tmp) : tmp->forward;
    }
    it = it->forward;
  }
}

static void		merge(list *this, list *x)
{
}

static void		sort(list *this, Compare comp)
{
  iterator		it;
  iterator		tmp;

  it = g_list.begin(this);
  while (it != NULL)
  {
    tmp = it->forward;
    while (tmp != NULL)
    {
      if (comp(it->value, tmp->value))
      {
	it->value = (void *)((size_t)(it->value) ^ (size_t)(tmp->value));
	tmp->value = (void *)((size_t)(tmp->value) ^ (size_t)(it->value));
	it->value = (void *)((size_t)(it->value) ^ (size_t)(tmp->value));
      }
      tmp = tmp->forward;
    }
    it = it->forward;
  }
}

static void		reverse(list *this)
{

}

struct s_list_class	g_list = {
  &constructor, 
  &destructor, 
  &begin, 
  &end, 
  &empty, 
  &size, 
  &max_size, 
  &front, 
  &back, 
  &assign, 
  &push_front, 
  &pop_front, 
  &push_back, 
  &pop_back, 
  &insert, 
  &erase, 
  &swap, 
  &resize, 
  &clear, 
  &splice, 
  &remove, 
  &remove_if, 
  &unique, 
  &merge, 
  &sort, 
  &reverse
};
