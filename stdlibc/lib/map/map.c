#include <string.h>
#include "map.h"

static node	node_search(node tree, const key_type k, key_compare comp)
{
  int		n;

  if (tree == NULL || tree->key == NULL)
    return (NULL);
  if ((n = comp(tree->key, k)) == 0)
    return (tree);
  else if (n < 0)
    return (node_search(tree->left, k, comp));
  else
    return (node_search(tree->right, k, comp));
}

static node	node_insert(node *tree, const key_type k, key_compare comp)
{
  node		tmp;
  int		n;

  tmp = NULL;
  if (*tree == NULL)
  {
    if ((tmp = calloc(sizeof(*tmp), 1)) == NULL)
      exit(EXIT_FAILURE);
    if ((tmp->key = strdup(k)) == NULL)
      exit(EXIT_FAILURE);
    return ((*tree = tmp));
  }
  if ((n = comp((*tree)->key, k)) < 0)
    return (node_insert(&(*tree)->left, k, comp));
  else if (n > 0)
    return (node_insert(&(*tree)->right, k, comp));
  return (NULL);
}

static void	node_clear(node tree)
{
  if (tree != NULL)
  {
    node_clear(tree->left);
    node_clear(tree->right);
    if (tree->content->first != NULL)
      free(tree->content->first);
    free(tree);
    tree = NULL;
  }
}

/*
** *****************************************************************************
*/

static void		constructor(map *this, key_compare comp)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  this->k_comp = (comp != NULL) ? 
    comp : (int (*)(const value_type, const value_type))&strcmp;
  this->v_comp = this->k_comp;
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

  if ((tmp = node_search(this->tree, k, this->k_comp)) != NULL && 
      tmp->content != NULL)
    return (tmp->content->second);
  return (NULL);
}

static p_iterator	insert(map *this, const pair val)
{
  p_iterator		it;
  p_iterator		end;
  node			tmp;

  if (g_map.count(this, val.first) == 1 || 
      (tmp = node_insert(&this->tree, val.first, this->k_comp)) == NULL)
    return (NULL);
  if ((end = g_map.end(this)) != NULL && end->second == NULL)
  {
    end->second = val.second;
    return (end);
  }
  if ((it = calloc(sizeof(*it), 1)) == NULL)
    exit(EXIT_FAILURE);
  it->first = tmp->key;
  it->second = val.second;
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
  this->content = (void *)((size_t)(this->content) ^ (size_t)(x->content));
  x->content = (void *)((size_t)(x->content) ^ (size_t)(this->content));
  this->content = (void *)((size_t)(this->content) ^ (size_t)(x->content));
  this->size ^= x->size;
  x->size ^= this->size;
  this->size ^= x->size;
  this->tree = (void *)((size_t)(this->tree) ^ (size_t)(x->tree));
  x->tree = (void *)((size_t)(x->tree) ^ (size_t)(this->tree));
  this->tree = (void *)((size_t)(this->tree) ^ (size_t)(x->tree));
  this->k_comp = (void *)((size_t)(this->k_comp) ^ (size_t)(x->k_comp));
  x->k_comp = (void *)((size_t)(x->k_comp) ^ (size_t)(this->k_comp));
  this->k_comp = (void *)((size_t)(this->k_comp) ^ (size_t)(x->k_comp));
  this->v_comp = (void *)((size_t)(this->v_comp) ^ (size_t)(x->v_comp));
  x->v_comp = (void *)((size_t)(x->v_comp) ^ (size_t)(this->v_comp));
  this->v_comp = (void *)((size_t)(this->v_comp) ^ (size_t)(x->v_comp));
}

static void		clear(map *this)
{
  node_clear(this->tree);
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

static p_iterator	find(map *this, const key_type k)
{
  node			tmp;

  if ((tmp = node_search(this->tree, k, this->k_comp)) != NULL)
    return (tmp->content);
  return (NULL);
}

static size_type	count(map *this, const key_type k)
{
  return (node_search(this->tree, k, this->k_comp) != NULL ? 1 : 0);
}

static p_iterator	lower_bound(map *this, const key_type k)
{
  return (NULL);
}

static p_iterator	upper_bound(map *this, const key_type k)
{
  return (NULL);
}

static void		*equal_range(map *this, const key_type k)
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
