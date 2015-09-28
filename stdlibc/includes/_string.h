/*
** _string.h for string in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_yepitech.net>
**
** Started on  Wed Feb  4 14:44:34 2015 davy tran
** Last update Fri Sep 25 16:08:31 2015 davy
*/

#ifndef M_STRING_H_
# define M_STRING_H_

# include <stdlib.h>
# include <stdbool.h>

# include "iterator.h"

# define NPOS		(size_t)-1
# define ALLOC_LENGTH	16
# define BUFFER_LENGTH	16

# ifndef STRING_CLASS
#  define STRING_CLASS

typedef struct s_string string;

/*
** Data structure for string pseudo class.
**
** Attributes:
**	str (char *) -- String data.
**	size (size_type) Size of string data's bytes.
**	length (size_type) -- Size of string data stopped by '\0'.
*/
struct		s_string
{
  char		*str;
  size_type	size;
  size_type	length;
};

struct		s_string_class
{
  void		(*constructor)(string *this);
  void		(*destructor)(string *this);

  void		*(*begin)(string *this);
  void		*(*end)(string *this);

  size_t	(*size)(string *this);
  void		(*resize)(string *this, size_t n);
  size_t	(*capacity)(string *this);
  void		(*clear)(string *this);
  bool		(*empty)(string *this);

  char		(*at)(string *this, size_t pos);

  char const	*(*append)(string *this, char const *str);
  void		(*push_back)(string *this, char c);
  char const	*(*assign)(string *this, char const *str, size_t n);
  char const	*(*insert)(string *this, size_t pos, char const *str);
  char const	*(*erase)(string *this, size_t pos, size_t len);
  char const	*(*replace)(string *this, size_t pos, size_t len, char const *str);
  void		(*swap)(string *this, string *str);

  char const	*(*c_str)(string *this);
  size_t	(*copy)(string *this, char* s, size_t len, size_t pos);
  size_t	(*find)(string *this, char const *str, size_t pos);
  char const	*(*substr)(string *this, size_t pos, size_t len);
  int		(*compare)(string *this, char const *str);
};

extern struct s_string_class	g_string;

# endif /* !STRING_CLASS */

string		*to_string(int val);

#endif /* !M_STRING_H_ */
