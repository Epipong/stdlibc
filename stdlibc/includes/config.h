#ifndef CONFIG_H_
# define CONFIG_H_

# include <SFML/Window.h>

/*
** Video mode setting.
*/
# define WIDTH 856
# define HEIGHT 480
# define BITSPERPIXEL 32

/*
** Render window setting.
*/
# define TITLE "Test"
# define STYLE (sfTitlebar | sfResize | sfClose)
# define FRAMERATE_LIMIT 60

/*
** Resources path.
*/
# define RESOURCES_PATH "resources/"

# define AUDIO_PATH "audio/"
# define DRAWABLE_PATH "drawable/"

/*
** Drawable resource.
*/
enum e_texture {
  SORA_SPRITE_SHEET,
  TEXTURE_COUNT
};

struct s_texture_filename {
  enum e_texture  id;
  char const      *filename;
};

extern struct s_texture_filename g_texture_filename[];

#endif /* !CONFIG_H_ */
