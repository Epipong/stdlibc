#ifndef VECTOR4_H_
# define VECTOR4_H_

# include <stdio.h>
# include <stdlib.h>

typedef struct s_vector4 vector4;

struct    s_vector4
{
  size_t  x;
  size_t  y;
  size_t  z;
  size_t  w;
};

vector4 v4(size_t x, size_t y, size_t z, size_t w);
char const  *v4_to_string(vector4 m);

vector4 v4_add(vector4 a, vector4 b);
vector4 v4_sub(vector4 a, vector4 b);
vector4 v4_mul(vector4 a, vector4 b);
vector4 v4_div(vector4 a, vector4 b);
vector4 v4_mod(vector4 a, vector4 b);
vector4 v4_and(vector4 a, vector4 b);
vector4 v4_or(vector4 a, vector4 b);
vector4 v4_xor(vector4 a, vector4 b);

#endif /* !VECTOR4_H_ */
