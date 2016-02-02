#include <string.h>

#include "math/vector.h"
#include "math/vector3.h"

vector3   v3(size_t x, size_t y, size_t z)
{
  vector3 m = {.x = x, .y = y, .z = z};
  return (m);
}

char const    *v3_to_string(vector3 m)
{
  static char buff[BUFFER_LENGTH + 1];

  memset(buff, 0, BUFFER_LENGTH);
  sprintf(buff, "(%ld, %ld, %ld)", m.x, m.y, m.z);
  return (buff);
}

vector3   v3_add(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x + b.x,
               .y = a.y + b.y,
               .z = a.z + b.z};
  return (m);
}

vector3   v3_sub(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x - b.x,
               .y = a.y - b.y,
               .z = a.z - b.z};
  return (m);
}

vector3   v3_mul(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x * b.x,
               .y = a.y * b.y,
               .z = a.z * b.z};
  return (m);
}

vector3   v3_div(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x / b.x,
               .y = a.y / b.y,
               .z = a.z / b.z};
  return (m);
}

vector3   v3_mod(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x % b.x,
               .y = a.y % b.y,
               .z = a.z % b.z};
  return (m);
}

vector3   v3_and(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x & b.x,
               .y = a.y & b.y,
               .z = a.z & b.z};
  return (m);
}

vector3   v3_or(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x | b.x,
               .y = a.y | b.y,
               .z = a.z | b.z};
  return (m);
}

vector3   v3_xor(vector3 a, vector3 b)
{
  vector3 m = {.x = a.x ^ b.x,
               .y = a.y ^ b.y,
               .z = a.z ^ b.z};
  return (m);
}
