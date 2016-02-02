#include "component/component.h"

static void constructor(component *this)
{
}

static void destructor(component *this)
{
}

struct s_component_class	g_component = {
  &constructor,
  &destructor
};
