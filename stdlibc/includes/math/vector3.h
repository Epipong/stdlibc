#ifndef VECTOR3_H_
# define VECTOR3_H_

# include <stdio.h>
# include <stdlib.h>

typedef struct s_vector3 vector3;

struct    s_vector3
{
  size_t  x;
  size_t  y;
  size_t  z;
};

vector3 v3(size_t x, size_t y, size_t z);
char const  *v3_to_string(vector3 m);

vector3 v3_add(vector3 a, vector3 b);
vector3 v3_sub(vector3 a, vector3 b);
vector3 v3_mul(vector3 a, vector3 b);
vector3 v3_div(vector3 a, vector3 b);
vector3 v3_mod(vector3 a, vector3 b);
vector3 v3_and(vector3 a, vector3 b);
vector3 v3_or(vector3 a, vector3 b);
vector3 v3_xor(vector3 a, vector3 b);

#endif /* !VECTOR3_H_ */
