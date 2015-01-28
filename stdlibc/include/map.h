#ifndef MAP_H_
# define MAP_H_

# include "iterator.h"
# include "bits/helper.h"

typedef struct s_map	map;

struct		s_map
{
  iterator	content;
  size_type	size;
  key_compare	comp;
};

struct		s_map_class
{
  void		(*constructor)(map *this, key_compare comp);
  void		(*destructor)(map *this);

  iterator	(*begin)(map *this);
  iterator	(*end)(map *this);

  bool		(*empty)(map *this);
  size_type	(*size)(map *this);
  size_type	(*max_size)(map *this);

  void		*(*at)(map *this, const key_type k);

  iterator	(*insert)(map *this, iterator position, const value_type val);
  iterator	(*erase)(map *this, iterator position);
  void		(*swap)(map *this, map *x);
  void		(*clear)(map *this);

  key_compare	(*key_comp)(map *this);
  value_compare	(*value_comp)(map *this);

  iterator	(*find)(map *this, const key_type k);
  size_type	(*count)(map *this, const key_type k);
  iterator	(*lower_bound)(map *this, const key_type k);
  iterator	(*upper_bound)(map *this, const key_type k);
  void		*(*equal_range)(map *this, const key_type k);
};

extern struct s_map_class	g_map;

#endif /* !MAP_H_ */
