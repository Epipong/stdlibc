#ifdef GENERIC

# include "math/vector2.h"
# include "math/vector3.h"
# include "math/vector4.h"

# include "sdl.h"
# include "std.h"

# include "component/component.h"
# include "engine/engine.h"
# include "game_object/game_object.h"
# include "message/message.h"

# include "system/audio.h"
# include "system/game_logic.h"
# include "system/graphic.h"
# include "system/input.h"
# include "system/object_factory.h"
# include "system/physic.h"
# include "system/system.h"
# include "system/ui.h"

# define foreach(row, array)  \
  for (iterator (row) = begin(array); (row) != NULL; (row) = (row)->forward)

/*
** Generic common function.
*/

# define constructor(x)                           \
  _Generic((x),                                   \
    string: STRING.constructor,                   \
    list: LIST.constructor,                       \
    deque: DEQUE.constructor,                     \
    map: MAP.constructor,                         \
    vector: VECTOR.constructor,                   \
    SDL: g_sdl.constructor,                       \
    component: g_component.constructor,           \
    engine: g_engine.constructor,                 \
    game_object: g_game_object.constructor,       \
    message: g_message.constructor,               \
    audio: g_audio.constructor,                   \
    game_logic: g_game_logic.constructor,         \
    graphic: g_graphic.constructor,               \
    input: g_input.constructor,                   \
    object_factory: g_object_factory.constructor, \
    physic: g_physic.constructor,                 \
    ui: g_ui.constructor                          \
  )(&x)

# define destructor(x)                            \
  _Generic((x),                                   \
    string: STRING.destructor,                    \
    list: LIST.destructor,                        \
    deque: DEQUE.destructor,                      \
    map: MAP.destructor,                          \
    vector: VECTOR.destructor,                    \
    SDL: g_sdl.destructor,                        \
    component: g_component.destructor,            \
    engine: g_engine.destructor,                  \
    game_object: g_game_object.destructor,        \
    message: g_message.destructor,                \
    audio: g_audio.destructor,                    \
    game_logic: g_game_logic.destructor,          \
    graphic: g_graphic.destructor,                \
    input: g_input.destructor,                    \
    object_factory: g_object_factory.destructor,  \
    physic: g_physic.destructor,                  \
    ui: g_ui.destructor                           \
  )(&x)

# define new(x)                                       \
  if (((x) = calloc(sizeof(*(x)), 1)))                \
    _Generic((x),                                     \
      string *: STRING.constructor,                   \
      list *: LIST.constructor,                       \
      deque *: DEQUE.constructor,                     \
      map *: MAP.constructor,                         \
      vector *: VECTOR.constructor,                   \
      SDL *: g_sdl.constructor,                       \
      component *: g_component.constructor,           \
      engine *: g_engine.constructor,                 \
      game_object *: g_game_object.constructor,       \
      message *: g_message.constructor,               \
      audio *: g_audio.constructor,                   \
      game_logic *: g_game_logic.constructor,         \
      graphic *: g_graphic.constructor,               \
      input *: g_input.constructor,                   \
      object_factory *: g_object_factory.constructor, \
      physic *: g_physic.constructor,                 \
      ui *: g_ui.constructor)(x);                     \
  else                                                \
    abort()

# define delete(x)                                  \
  _Generic((x),                                     \
    string *: STRING.destructor,                    \
    list *: LIST.destructor,                        \
    deque *: DEQUE.destructor,                      \
    map *: MAP.destructor,                          \
    vector *: VECTOR.destructor,                    \
    SDL *: g_sdl.destructor,                        \
    component *: g_component.destructor,            \
    engine *: g_engine.destructor,                  \
    game_object *: g_game_object.destructor,        \
    message *: g_message.destructor,                \
    audio *: g_audio.destructor,                    \
    game_logic *: g_game_logic.destructor,          \
    graphic *: g_graphic.destructor,                \
    input *: g_input.destructor,                    \
    object_factory *: g_object_factory.destructor,  \
    physic *: g_physic.destructor,                  \
    ui *: g_ui.destructor)(x);                      \
  free((x))

# define begin(x)         \
  _Generic((x),           \
    string: STRING.begin, \
    list: LIST.begin,     \
    deque: DEQUE.begin,   \
    map: MAP.begin,       \
    vector: VECTOR.begin  \
  )(&x)

# define end(x)         \
  _Generic((x),         \
    string: STRING.end, \
    list: LIST.end,     \
    deque: DEQUE.end,   \
    map: MAP.end,       \
    vector: VECTOR.end  \
  )(&x)

# define empty(x)         \
  _Generic((x),           \
    deque: DEQUE.empty,   \
    list: LIST.empty,     \
    map: MAP:empty,       \
    string: STRING.empty, \
    vector: VECTOR.empty  \
  )(&x)

# define size(x)          \
  _Generic((x),           \
    string: STRING.size,  \
    list: LIST.size,      \
    deque: DEQUE.size,    \
    map: MAP.size,        \
    vector: VECTOR.size   \
  )(&x)

# define max_size(x)        \
  _Generic((x),             \
    list: LIST.max_size,    \
    deque: DEQUE.max_size,  \
    map: MAP.max_size,      \
    vector: VECTOR.max_size \
  )(&x)

# define resize(x)          \
  _Generic((x),             \
    string: STRING.resize,  \
    deque: DEQUE.resize,    \
    vector: VECTOR.resize   \
  )(&x)

# define capacity(x)          \
  _Generic((x),               \
    vector: VECTOR.capacity,  \
    string: STRING.capacity   \
  )(&x)

# define clear(x)         \
  _Generic((x),           \
    string: STRING.clear, \
    list: LIST.clear,     \
    deque: DEQUE.clear,   \
    map: MAP.clear,       \
    vector: VECTOR.clear  \
  )(&x)

# define at(x, y, type)   \
  *((type *)(_at(x, y)))

# define _at(x, y)        \
  _Generic((x),           \
    string: STRING.at,    \
    deque: DEQUE.at,      \
    map: MAP.at,          \
    vector: VECTOR.at     \
  )(&x, y)

# define assign(x, y, z)    \
  _Generic((x),             \
    string: STRING.assign,  \
    list: LIST.assign,      \
    deque: DEQUE.assign,    \
    vector: VECTOR.assign   \
  )(&x, y, z)

# define insert(x, y, z)    \
  _Generic((x),             \
    string: STRING.insert,  \
    list: LIST.insert,      \
    deque: DEQUE.insert,    \
    map: MAP.insert,        \
    vector: VECTOR.insert   \
  )(&x, y, z)

# define push_front(x, y)   \
  _Generic((x),             \
    list: LIST.push_front,  \
    deque: DEQUE.push_front \
  )(&x, y)

# define push_back(x, y)      \
  _Generic((x),               \
    string: STRING.push_back, \
    list: LIST.push_back,     \
    deque: DEQUE.push_back,   \
    vector: VECTOR.push_back  \
  )(&x, y)

# define pop_front(x)       \
  _Generic((x),             \
    list: LIST.pop_front,   \
    deque: DEQUE.pop_front  \
  )(&x)

# define pop_back(x)        \
  _Generic((x),             \
    list: LIST.pop_back,    \
    deque: DEQUE.pop_back,  \
    vector: VECTOR.pop_back \
  )(&x)

# define front(x)         \
  _Generic((x),           \
    list: LIST.front,     \
    deque: DEQUE.front,   \
    vector: VECTOR.front  \
  )(&x)

# define back(x)        \
  _Generic((x),         \
    list: LIST.back,    \
    deque: DEQUE.back,  \
    vector: VECTOR.back \
  )(&x)

# define reserve(x, y)      \
  _Generic((x),             \
    vector: VECTOR.reserve  \
  )(&x, y)

/*
** GUI generic function.
*/

# define create_window(x, y, z, w)  g_sdl.create_window(&x, y, z, w)
# define get_window_surface(x)      g_sdl.get_window_surface(&x)
# define fill_rect(x, y, z)         g_sdl.fill_rect(&x, y, z)
# define update_window_surface(x)   g_sdl.update_window_surface(&x)
# define delay(x)                   g_sdl.delay(x)
# define get_error(x)               g_sdl.get_error()

# define update(x, y, z)                      \
  _Generic((x),                               \
    audio: g_audio.update,                    \
    game_logic: g_game_logic.update,          \
    graphic: g_graphic.update,                \
    input: g_input.update,                    \
    object_factory: g_object_factory.update,  \
    physic: g_physic.update,                  \
    ui: g_ui.update                           \
  )(&x, y, z)

# define loop(x) \
  _Generic((x), engine: g_engine.loop)(&x)

# define add_system(x, y) g_engine.add_system(&x, sys(y), sizeof(y))
# define sys(x) _system(sys_type(x), system)

# define sys_type(x)                \
  _Generic((x),                     \
    audio:          AUDIO,          \
    game_logic:     GAME_LOGIC,     \
    graphic:        GRAPHIC,        \
    input:          INPUT,          \
    object_factory: OBJECT_FACTORY, \
    physic:         PHYSIC,         \
    ui:             UI              \
  )

/*
** Math generic function.
*/

# define add(x, y)    \
  _Generic((x),       \
    vector2: v2_add,  \
    vector3: v3_add,  \
    vector4: v4_add   \
  )(x, y)

# define sub(x, y)    \
  _Generic((x),       \
    vector2: v2_sub,  \
    vector3: v3_sub,  \
    vector4: v4_sub   \
  )(x, y)

# define mul(x, y)    \
  _Generic((x),       \
    vector2: v2_mul,  \
    vector3: v3_mul,  \
    vector4: v4_mul   \
  )(x, y)

# define div(x, y)    \
  _Generic((x),       \
    vector2: v2_div,  \
    vector3: v3_div,  \
    vector4: v4_div   \
  )(x, y)

# define mod(x, y)    \
  _Generic((x),       \
    vector2: v2_mod,  \
    vector3: v3_mod,  \
    vector4: v4_mod   \
  )(x, y)

# define and(x, y)    \
  _Generic((x),       \
    vector2: v2_and,  \
    vector3: v3_and,  \
    vector4: v4_and   \
  )(x, y)

# define or(x, y)     \
  _Generic((x),       \
    vector2: v2_or,   \
    vector3: v3_or,   \
    vector4: v4_or    \
  )(x, y)

# define xor(x, y)    \
  _Generic((x),       \
    vector2: v2_xor,  \
    vector3: v3_xor,  \
    vector4: v4_xor   \
  )(x, y)

/*
** Others
*/

# define get(x, type)  (*((type *)(x)->value))
# define put(x, type)  ((type []){x})
# define value(x)      ((x)->value)

# define to_string(x)       \
  _Generic((x),             \
    vector2: v2_to_string,  \
    vector3: v3_to_string,  \
    vector4: v4_to_string,  \
    default: to_string      \
  )(x)

#endif /* !GENERIC */
