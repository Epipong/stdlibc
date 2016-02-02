#ifndef VECTOR2_H_
# define VECTOR2_H_

# include <stdio.h>
# include <stdlib.h>

typedef struct s_vector2 vector2;

struct    s_vector2
{
  size_t  x;
  size_t  y;
};

vector2 v2(size_t x, size_t y);
char const  *v2_to_string(vector2 m);

vector2 v2_add(vector2 a, vector2 b);
vector2 v2_sub(vector2 a, vector2 b);
vector2 v2_mul(vector2 a, vector2 b);
vector2 v2_div(vector2 a, vector2 b);
vector2 v2_mod(vector2 a, vector2 b);
vector2 v2_and(vector2 a, vector2 b);
vector2 v2_or(vector2 a, vector2 b);
vector2 v2_xor(vector2 a, vector2 b);

#endif /* !VECTOR2_H_ */
