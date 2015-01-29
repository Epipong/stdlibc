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
    tmp->key = k;
    return ((*tree = tmp));
  }
  if ((n = comp((*tree)->key, k)) < 0)
    return (node_insert(&(*tree)->left, k, comp));
  else if (n > 0)
    return (node_insert(&(*tree)->right, k, comp));
  return (NULL);
}

static void	node_clear(node *tree)
{
  if (*tree == NULL)
    return ;
  if ((*tree)->left != NULL)
    node_clear(&((*tree)->left));
  else if ((*tree)->right != NULL)
    node_clear(&((*tree)->right));
  if (*tree != NULL)
  {
    free(*tree);
    *tree = NULL;
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

static iterator		begin(map *this)
{
  iterator		it;

  it = this->content;
  while (it != NULL && it->rewind != NULL)
    DECREMENT_IT(it);
  return (it);
}

static iterator		end(map *this)
{
  iterator		it;

  it = this->content;
  while (it != NULL && it->forward != NULL)
    INCREMENT_IT(it);
  return (it);
}

static bool		empty(map *this)
{
  return (!this || !this->content || !this->content->value);
}

static size_type	size(map *this)
{
  iterator		it;
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
    return (tmp->content->value);
  return (NULL);
}

static iterator		insert(map *this, const pair val)
{
  node			tmp;

  if ((tmp = node_insert(&this->tree, val.first, this->k_comp)) == NULL)
    return (NULL);
  g_list.push_back((list *)this, val.second);
  return ((tmp->content = g_list.end((list *)this)));
}

static iterator		erase(map *this, iterator position)
{
  return (g_list.erase((list *)this, position));
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
  node_clear(&this->tree);
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

static iterator		find(map *this, const key_type k)
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

static iterator		lower_bound(map *this, const key_type k)
{
  return (NULL);
}

static iterator		upper_bound(map *this, const key_type k)
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
