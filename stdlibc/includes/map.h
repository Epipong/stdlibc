/*
** map.h for map in /home/davy/Rendu/stdlibc/stdlibc
** 
** Made by davy tran
** Login   <tran_yepitech.net>
** 
** Started on  Wed Feb  4 14:45:23 2015 davy tran
** Last update Wed Feb  4 19:15:14 2015 davy tran
*/

#ifndef MAP_H_
# define MAP_H_

# include "bits/helper.h"
# include "iterator.h"
# include "pair.h"
# include "list.h"

typedef struct s_map	map;

/*
** Data structure for map.
**
** Attributes:
**	content (iterator) -- Data stored.
**	size (size_type) -- Size.
**	tree (node) -- Binary tree node.
**	k_comp (key_compare) -- Key compare method return boolean.
**	v_comp (value_compare) -- Value compare method return boolean.
*/
struct		s_map
{
  p_iterator	content;
  size_type	size;
  node		tree;
  key_compare	k_comp;
  value_compare	v_comp;
};

struct		s_map_class
{
  void		(*constructor)(map *this, key_compare comp);
  void		(*destructor)(map *this);

  p_iterator	(*begin)(map *this);
  p_iterator	(*end)(map *this);

  bool		(*empty)(map *this);
  size_type	(*size)(map *this);
  size_type	(*max_size)(map *this);

  void		*(*at)(map *this, const key_type k);

  p_iterator	(*insert)(map *this, const pair val);
  p_iterator	(*erase)(map *this, p_iterator position);
  void		(*swap)(map *this, map *x);
  void		(*clear)(map *this);

  key_compare	(*key_comp)(map *this);
  value_compare	(*value_comp)(map *this);

  p_iterator	(*find)(map *this, const key_type k);
  size_type	(*count)(map *this, const key_type k);
  p_iterator	(*lower_bound)(map *this, const key_type k);
  p_iterator	(*upper_bound)(map *this, const key_type k);
  void		*(*equal_range)(map *this, const key_type k);
};

extern struct s_map_class	g_map;

#endif /* !MAP_H_ */
