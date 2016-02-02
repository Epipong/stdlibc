#include <string.h>

#include "math/vector.h"
#include "math/vector4.h"

vector4   v4(size_t x, size_t y, size_t z, size_t w)
{
  vector4 m = {.x = x, .y = y, .z = z, .w = w};
  return (m);
}

char const    *v4_to_string(vector4 m)
{
  static char buff[BUFFER_LENGTH + 1];

  memset(buff, 0, BUFFER_LENGTH);
  sprintf(buff, "(%ld, %ld, %ld, %ld)", m.x, m.y, m.z, m.w);
  return (buff);
}

vector4   v4_add(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x + b.x,
               .y = a.y + b.y,
               .z = a.z + b.z,
               .w = a.w + b.w};
  return (m);
}

vector4   v4_sub(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x - b.x,
               .y = a.y - b.y,
               .z = a.z - b.z,
               .w = a.w - b.w};
  return (m);
}

vector4   v4_mul(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x * b.x,
               .y = a.y * b.y,
               .z = a.z * b.z,
               .w = a.w * b.w};
  return (m);
}

vector4   v4_div(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x / b.x,
               .y = a.y / b.y,
               .z = a.z / b.z,
               .w = a.w / b.w};
  return (m);
}

vector4   v4_mod(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x % b.x,
               .y = a.y % b.y,
               .z = a.z % b.z,
               .w = a.w % b.w};
  return (m);
}

vector4   v4_and(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x & b.x,
               .y = a.y & b.y,
               .z = a.z & b.z,
               .w = a.w & b.w};
  return (m);
}

vector4   v4_or(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x | b.x,
               .y = a.y | b.y,
               .z = a.z | b.z,
               .w = a.w | b.w};
  return (m);
}

vector4   v4_xor(vector4 a, vector4 b)
{
  vector4 m = {.x = a.x ^ b.x,
               .y = a.y ^ b.y,
               .z = a.z ^ b.z,
               .w = a.w ^ b.w};
  return (m);
}
