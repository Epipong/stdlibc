#include <string.h>
#include "map.h"

static void		constructor(map *this, key_compare comp)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
}

static void		destructor(map *this)
{

}

static iterator		begin(map *this)
{
  return (NULL);
}

static iterator		end(map *this)
{
  return (NULL);
}

static bool		empty(map *this)
{
  return (false);
}

static size_type	size(map *this)
{
  return (0);
}

static size_type	max_size(map *this)
{
  return (0);
}

static void		*at(map *this, const key_type k)
{
  return (NULL);
}

static iterator		insert(map *this, iterator position, const value_type val)
{
  return (NULL);
}

static iterator		erase(map *this, iterator position)
{
  return (NULL);
}

static void		swap(map *this, map *x)
{

}

static void		clear(map *this)
{

}

static key_compare	key_comp(map *this)
{
  return (NULL);
}

static value_compare	value_comp(map *this)
{
  return (NULL);
}

static iterator		find(map *this, const key_type k)
{
  return (NULL);
}

static size_type	count(map *this, const key_type k)
{
  return (0);
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
