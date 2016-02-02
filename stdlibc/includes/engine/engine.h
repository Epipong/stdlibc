#ifndef ENGINE_H_
# define ENGINE_H_

# include "std.h"
# include "system/system.h"

typedef struct s_engine engine;

struct    s_engine
{
  vector  systems[SYSTEM_LENGTH + 1];
};

struct s_engine_class
{
  void (*constructor)(engine *this);
  void (*destructor)(engine *this);

  void (*update)(engine *this, float datetime);
  void (*loop)(engine *this);
  void (*add_system)(engine *this, struct s_sys s);
};

extern struct s_engine_class  g_engine;

#endif /* !ENGINE_H_ */
