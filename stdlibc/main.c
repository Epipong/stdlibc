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
  printf("size: %lu\n", size(foo));
  sz = capacity(bar);
  printf("making bar grow:\n");
  printf("bar.content -> %p\n", bar.content);
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
  //test_vector();
  deque  l;
  vector v;

  constructor(l);
  constructor(v);
  push_back(l, "toto");
  push_back(l, "titi");
  push_back(l, "tutu");
  push_back(v, put(4, int));
  push_back(v, put(67, int));
  push_back(v, put(32, int));
  foreach(row, l)
    printf("%s\n", row->value);
  foreach(row, v) // through vector as iterator
    printf("%d\n", get(row, int));
  for (int i = size(v) - 1; i != -1; --i) // through vector as array
    printf("%d\n", get(v.content[i], int));
  destructor(l);
  destructor(v);
  return 0;
}
