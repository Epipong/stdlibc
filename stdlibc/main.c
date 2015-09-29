/*
** main.c for  in /home/davy/Templates/stdlibc/stdlibc
**
** Made by davy
** Login   <davy@epitech.net>
**
** Started on  Thu Sep 24 17:14:19 2015 davy
** Last update Tue Sep 29 17:27:43 2015 davy
*/

#define GENERIC

#include <stdio.h>
#include "std.h"

static int	intcmp(int *a, int *b) { return (*a - *b); }

static void	test_vector()
{
  vector	v;

  constructor(v);
  push_back(v, "toto");
  printf("%s\n", at(v, 0));
  destructor(v);
}

int		main(void)
{
  map		m;
  map		mm;
  map		*pm;

  constructor(m);
  new(pm);
  m.k_comp = (key_compare)intcmp;
  constructor(mm);
  insert(*pm, "test", "fox in the beach");
  insert(m, (int []){51}, "area");
  insert(mm, "toto", "titi");
  printf("v = %s\n", at(m, (int []){51}));
  printf("v = %s\n", at(mm, "toto"));
  printf("pm has key (%s) and value (%s)\n", "test", at(*pm, "test"));
  destructor(m);
  destructor(mm);
  delete(pm);
  test_vector();
  return 0;
}
