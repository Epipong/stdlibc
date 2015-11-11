/*
** pair.h for pair in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_yepitech.net>
**
** Started on  Wed Feb  4 14:45:15 2015 davy tran
** Last update Wed Feb  4 19:15:18 2015 davy tran
*/

#ifndef PAIR_H_
# define PAIR_H_

# include "bits/helper.h"

typedef struct s_pair pair;

/*
** Data structure for pair.
**
** Attributes:
**  first (first_type) -- Left data.
**  second (second_type) -- Right data.
*/
struct        s_pair
{
  first_type  first;
  second_type second;
};

#endif /* !PAIR_H_ */
