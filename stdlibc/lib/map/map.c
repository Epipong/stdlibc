/*
** map.c for  in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_y@epitech.net>
**
** Started on  Wed Feb  4 19:18:21 2015 davy tran
** Last update Wed Sep 23 16:18:03 2015 davy
*/

#include <string.h>
#include "map.h"

static void	*ptrdup(void *ptr, size_t size)
{
  void		*new;

  if ((new = calloc(size + 1, 1)) == NULL)
    return (NULL);
  memcpy(new, ptr, size);
  return (new);
}

/*
** Private method for search node with key compare method.
**
** Attributes:
**	tree (node) -- Binary tree instance.
**	k (key_type) -- Key comparison.
**	comp (key_compare) -- Method comparison between key.
*/
static node	_node_key_search(node tree, const key_type k, key_compare comp)
{
  int		n;

  if (tree == NULL || tree->key == NULL)
    return (NULL);
  if ((n = comp(tree->key, k)) == 0)
    return (tree);
  else if (n < 0)
    return (_node_key_search(tree->left, k, comp));
  else
    return (_node_key_search(tree->right, k, comp));
}

/*
** Private method for search node with value compare method.
**
** Attributes:
**	tree (node) -- Binary tree instance.
**	v (value_type) -- Value comparison.
**	comp (value_compare) -- Method comparison between value.
*/
static node	_node_value_search(node tree, const value_type v,
				   value_compare comp)
{
  int		n;

  if (tree == NULL || tree->content == NULL || tree->content->second)
    return (NULL);
  if ((n = comp(tree->content->second, v)) == 0)
    return (tree);
  else if (n < 0)
    return (_node_value_search(tree->left, v, comp));
  else
    return (_node_value_search(tree->right, v, comp));
}

/*
** Private method for insert node with key compare method.
**
** Attributes:
**	tree (node *) -- Binary tree instance.
**	k (key_type) -- Key comparison.
**	comp (key_compare) -- Method comparison between key.
*/
static node	_node_insert(node *tree, const key_type k, key_compare comp)
{
  node		tmp;
  int		n;

  tmp = NULL;
  if (*tree == NULL)
  {
    if ((tmp = calloc(sizeof(*tmp), 1)) == NULL)
      exit(EXIT_FAILURE);
    if ((tmp->key = ptrdup(k, 32)) == NULL)
      exit(EXIT_FAILURE);
    return ((*tree = tmp));
  }
  if ((n = comp((*tree)->key, k)) < 0)
    return (_node_insert(&(*tree)->left, k, comp));
  else if (n > 0)
    return (_node_insert(&(*tree)->right, k, comp));
  return (NULL);
}

/*
** Private method for clear all node.
**
** Attributes:
**	tree (node) -- Binary tree instance.
*/
static void	_node_clear(node tree)
{
  if (tree != NULL)
  {
    _node_clear(tree->left);
    _node_clear(tree->right);
    if (tree->content->first != NULL)
      free(tree->content->first);
    free(tree);
    tree = NULL;
  }
}

static void		constructor(map *this)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  this->k_comp = (key_compare)strcmp;
  this->v_comp = (key_compare)strcmp;
}

static void		destructor(map *this)
{
  if (this == NULL)
    return ;
  g_map.clear(this);
  if (this->content != NULL)
    free(this->content);
  if (this->tree != NULL)
    free(this->tree);
  this->content = NULL;
  this->tree = NULL;
}

static p_iterator	begin(map *this)
{
  p_iterator		it;

  it = this->content;
  while (it != NULL && it->rewind != NULL)
    DECREMENT_IT(it);
  return (it);
}

static p_iterator	end(map *this)
{
  p_iterator		it;

  it = this->content;
  while (it != NULL && it->forward != NULL)
    INCREMENT_IT(it);
  return (it);
}

static bool		empty(map *this)
{
  return (!this || !this->content ||
	  !this->content->first || !this->content->second);
}

static size_type	size(map *this)
{
  p_iterator		it;
  size_type		n;

  it = g_map.begin(this);
  n = 0;
  while (it != NULL)
  {
    ++n;
    INCREMENT_IT(it);
  }
  return (n);
}

static size_type	max_size(map *this)
{
  return (size(this));
}

static void		*at(map *this, const key_type k)
{
  node			tmp;

  if ((tmp = _node_key_search(this->tree, k, this->k_comp)) != NULL &&
      tmp->content != NULL)
    return (tmp->content->second);
  return (NULL);
}

static p_iterator	insert(map *this, first_type first, second_type second)
{
  p_iterator		it;
  p_iterator		end;
  node			tmp;

  if (g_map.count(this, first) == 1 ||
      (tmp = _node_insert(&this->tree, first, this->k_comp)) == NULL)
    return (NULL);
  if ((end = g_map.end(this)) != NULL && end->second == NULL)
  {
    end->second = second;
    return (end);
  }
  if ((it = calloc(sizeof(*it), 1)) == NULL)
    exit(EXIT_FAILURE);
  it->first = tmp->key;
  it->second = second;
  if (end != NULL)
  {
    end->forward = it;
    it->rewind = end;
  }
  else
    this->content = it;
  return ((tmp->content = g_map.end(this)));
}

static p_iterator	erase(map *this, p_iterator position)
{
  return ((p_iterator)g_list.erase((list *)this, (iterator)position));
}

static void		swap(map *this, map *x)
{
  SWAP_PTR(this->content, x->content);
  SWAP_NBR(this->size, x->size);
  SWAP_PTR(this->tree, x->tree);
  SWAP_PTR(this->k_comp, x->k_comp);
  SWAP_PTR(this->v_comp, x->v_comp);
}

static void		clear(map *this)
{
  _node_clear(this->tree);
  this->tree = NULL;
  g_list.clear((list *)this);
}

static key_compare	key_comp(map *this)
{
  return (this->k_comp);
}

static value_compare	value_comp(map *this)
{
  return (this->v_comp);
}

static p_iterator	find(map *this, const value_type v)
{
  node			tmp;

  if ((tmp = _node_value_search(this->tree, v, this->v_comp)) != NULL)
    return (tmp->content);
  return (NULL);
}

static size_type	count(map *this, const value_type v)
{
  return (_node_value_search(this->tree, v, this->v_comp) != NULL ? 1 : 0);
}

static p_iterator	lower_bound(__attribute__((unused))map *this, const __attribute__((unused))key_type k)
{
  return (NULL);
}

static p_iterator	upper_bound(__attribute__((unused))map *this, __attribute__((unused))const key_type k)
{
  return (NULL);
}

static void		*equal_range(__attribute__((unused))map *this, __attribute__((unused))const key_type k)
{
  return (NULL);
}

struct s_map_class	g_map = {
  &constructor,
  &destructor,
  &begin,
  &end,
  &empty,
  &size,
  &max_size,
  &at,
  &insert,
  &erase,
  &swap,
  &clear,
  &key_comp,
  &value_comp,
  &find,
  &count,
  &lower_bound,
  &upper_bound,
  &equal_range
};
