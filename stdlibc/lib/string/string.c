#include <string.h>
#include <stdio.h>
#include "_string.h"

static void		constructor(string *this, char const *s)
{
  if (this != NULL)
    memset(this, 0, sizeof(*this));
  g_string.assign(this, s);
}

static void		destructor(string *this)
{
  if (this != NULL)
  {
    if (this->str != NULL)
      free(this->str);
    this->str = NULL;
    this->size = 0;
  }
}

static void		*begin(string *this)
{
  return (this->str);
}

static void		*end(string *this)
{
  return (this->str != NULL ? 
	  this->str + strlen(this->str) : NULL);
}

static size_t		size(string *this)
{
  return (this->str != NULL ? strlen(this->str) : 0);
}

static void		resize(string *this, size_t n)
{
  size_t		len;

  if (n < (len = g_string.size(this)))
    this->str[n] = '\0';
  this->size = 0;
  while (this->size <= n)
    this->size += ALLOC_LENGTH;
  if ((this->str = realloc(this->str, this->size)) == NULL)
    this->size = 0;
  else if (len == 0)
    memset(this->str, 0, this->size);
}

static size_t		capacity(string *this)
{
  return (this->size);
}

static void		clear(string *this)
{
  if (this->str != NULL)
    memset(this->str, 0, this->size);
}

static bool		empty(string *this)
{
  return (this->str == NULL || g_string.size(this));
}

static char		at(string *this, size_t pos)
{
  return (this->str != NULL && pos < g_string.size(this) ? 
	  this->str[pos] : '\0');
}

static char const	*append(string *this, char const *str)
{
  if (str == NULL)
    return (this->str);
  if (g_string.size(this) + strlen(str) >= g_string.capacity(this))
    g_string.resize(this, g_string.size(this) + strlen(str));
  return (this->str != NULL ? strcat(this->str, str) : NULL);
}

static void		push_back(string *this, char c)
{
  char const		tmp[] = {c, '\0'};

  g_string.append(this, tmp);
}

static char const	*assign(string *this, char const *str)
{
  if (str == NULL)
    return (this->str);
  g_string.clear(this);
  return (g_string.append(this, str));
}

static char const	*insert(string *this, size_t pos, char const *str)
{
  char			*tmp;

  if (str == NULL)
    return (this->str);
  else if (g_string.size(this) + strlen(str) > g_string.capacity(this))
    g_string.resize(this, g_string.size(this) + strlen(str));
  if (g_string.size(this) < pos)
    return (strcpy(this->str + pos, str));
  if ((tmp = strdup(this->str + pos)) != NULL)
  {
    strcpy(this->str + pos, str);
    strcpy(this->str + pos + strlen(str), tmp);
    free(tmp);
    return (this->str);
  }
  return (NULL);
}

static char const	*erase(string *this, size_t pos, size_t len)
{
  size_t		size;

  if (this->str == NULL || g_string.size(this) < pos)
    return (this->str != NULL ? this->str : NULL);
  if ((size = strlen(this->str + pos)) < len)
    len = size;
  memset(this->str + pos, 0, len);
  return (strcat(this->str + pos, this->str + pos + len));
}

static char const	*replace(string *this, size_t pos, size_t len, char const *str)
{
  g_string.erase(this, pos, len);
  return (g_string.insert(this, pos, str));
}

static void		swap(string *this, string *str)
{
  this->str = (char *)((size_t)this->str ^ (size_t)str->str);
  str->str = (char *)((size_t)str->str ^ (size_t)this->str);
  this->str = (char *)((size_t)this->str ^ (size_t)str->str);
}

static char const	*c_str(string *this)
{
  return (this->str);
}

static size_t		copy(string *this, char* s, size_t len, size_t pos)
{
  size_t		size;

  if (s == NULL || this->size < pos)
    return (NPOS);
  if ((size = strlen(this->str + pos)) < len)
    len = size;
  strncpy(s, this->str + pos, len);
  return (len);
}

static size_t		find(string *this, char const *str, size_t pos)
{
  char			*tmp;

  if (g_string.size(this) < pos || str == NULL)
    return (NPOS);
  if ((tmp = strstr(this->str + pos, str)) != NULL)
    return ((size_t)(tmp - this->str));
  return (NPOS);
}

static char const	*substr(string *this, size_t pos, size_t len)
{
  if (g_string.size(this) < pos)
    return (NULL);
  return (strndup(this->str + pos, len));
}

static int		compare(string *this, char const *str)
{
  return (strcmp(this->str, str));
}

struct s_string_class	g_string = {
  &constructor, 
  &destructor, 
  &begin, 
  &end, 
  &size, 
  &resize, 
  &capacity, 
  &clear, 
  &empty, 
  &at, 
  &append, 
  &push_back, 
  &assign, 
  &insert, 
  &erase, 
  &replace, 
  &swap, 
  &c_str, 
  &copy, 
  &find, 
  &substr, 
  &compare
};

string		*to_string(int val)
{
  char		buff[BUFFER_LENGTH + 1];
  string	*str;

  if ((str = malloc(sizeof(*str))) == NULL)
    return (NULL);
  memset(buff, 0, sizeof(buff));
  sprintf(buff, "%d", val);
  g_string.constructor(str, buff);
  return (str);
}
