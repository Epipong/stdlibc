/*
** main.c for  in /home/davy/Templates/stdlibc/stdlibc
**
** Made by davy
** Login   <davy@epitech.net>
**
** Started on  Thu Sep 24 17:14:19 2015 davy
** Last update Wed Sep 30 17:36:42 2015 davy
*/

#define GENERIC

#include <stdio.h>
#include "std.h"

static int	intcmp(int *a, int *b) { return (*a - *b); }

static void	test_vector()
{
  size_type	sz;
  vector	foo;
  vector	bar;

  constructor(foo);
  constructor(bar);
  sz = capacity(foo);
  printf("making foo grow:\n");
  for (int i = 0; i < 100; ++i)
  {
    push_back(foo, (int []){i});
    if (sz != capacity(foo))
    {
      sz = capacity(foo);
      printf("capacity changed: %zu\n", sz);
    }
  }
  sz = capacity(bar);
  reserve(bar, 100);
  printf("making bar grow:\n");
  for (int i = 0; i < 100; ++i)
  {
    push_back(bar, (int []){i});
    if (sz != capacity(bar))
    {
      sz = capacity(bar);
      printf("capacity changed: %zu\n", sz);
    }
  }
  destructor(foo);
  destructor(bar);
}

int		main(void)
{
  test_vector();
  return 0;
}
