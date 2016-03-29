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

int               test_engine()
{
  engine          e;
  audio           a;
  input           i;
  graphic         g;
  texture_manager tm;

  constructor(e);
  constructor(tm);
  add_system(e, a);
  add_system(e, i);
  add_system(e, g);
  loop(e);
  destructor(e);
  destructor(tm);
  return 0;
}

int		main(void)
{
  return test_engine();
}
