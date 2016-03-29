#ifndef SORA_ANIMATION_H_
# define SORA_ANIMATION_H_

# include "std.h"

typedef struct s_sora_animation sora_animation;

struct  s_sora_animation
{
  map   animations;
};

void sora_ctor(sora_animation *this);
void sora_dtor(sora_animation *this);

#endif /* !SORA_ANIMATION_H_ */
