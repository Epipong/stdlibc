#include <string.h>

#include "math/vector.h"
#include "math/vector2.h"

vector2   v2(size_t x, size_t y)
{
  vector2 m = {.x = x, .y = y};
  return (m);
}

char const    *v2_to_string(vector2 m)
{
  static char buff[BUFFER_LENGTH + 1];

  memset(buff, 0, BUFFER_LENGTH);
  sprintf(buff, "(%ld, %ld)", m.x, m.y);
  return (buff);
}

vector2   v2_add(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x + b.x,
               .y = a.y + b.y};
  return (m);
}

vector2   v2_sub(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x - b.x,
               .y = a.y - b.y};
  return (m);
}

vector2   v2_mul(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x * b.x,
               .y = a.y * b.y};
  return (m);
}

vector2   v2_div(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x / b.x,
               .y = a.y / b.y};
  return (m);
}

vector2   v2_mod(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x % b.x,
               .y = a.y % b.y};
  return (m);
}

vector2   v2_and(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x & b.x,
               .y = a.y & b.y};
  return (m);
}

vector2   v2_or(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x | b.x,
               .y = a.y | b.y};
  return (m);
}

vector2   v2_xor(vector2 a, vector2 b)
{
  vector2 m = {.x = a.x ^ b.x,
               .y = a.y ^ b.y};
  return (m);
}
