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
#include <unistd.h>

#include "generic.h"

# include "math/vector2.h"
# include "math/vector3.h"
# include "math/vector4.h"

static int	intcmp(int *a, int *b) { return (*a - *b); }

static void test_vector()
{
  size_type sz;
  vector    foo;
  vector    bar;

  constructor(foo);
  constructor(bar);
  sz = capacity(foo);
  printf("making foo grow:\n");
  for (int i = 0; i < 100; ++i)
  {
    push_back(foo, put(i, int));
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
    push_back(bar, put(i, int));
    if (sz != capacity(bar))
    {
      sz = capacity(bar);
      printf("capacity changed: %zu\n", sz);
    }
  }
  destructor(foo);
  destructor(bar);
}

int test_math_vector()
{
  vector3 m = v3(5, 3, 2);
  vector3 n = add(m, v3(9, 4, 2));
  printf("%s\n", to_string(m));
  printf("%s\n", to_string(n));
  m = mul(m, n);
  printf("%s\n", to_string(m));
  m = sub(v3(2, 1, 6), v3(9, 4, 2));
  printf("%s\n", to_string(m));
  m = xor(m, n);
  printf("%s\n", to_string(m));
  return 0;
}

int       test_engine()
{
  engine  e;
  audio   a;
  input   i;
  graphic g;

  constructor(e);
  add_system(e, a);
  add_system(e, i);
  add_system(e, g);
  //loop(e);
  destructor(e);
  return 0;
}

int		main(void)
{
  //test_vector();
  return test_engine();
  //return test_math_vector();
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
  foreach(row, v) // through vector as an iterator
    printf("%d\n", get(row, int));
  for (int i = size(v) - 1; i != -1; --i) // through vector as an array
    printf("%d\n", get(v.content[i], int));
  destructor(l);
  destructor(v);
  return 0;
}
