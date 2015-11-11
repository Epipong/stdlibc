/*
** helper.h for helper in /home/davy/Rendu/stdlibc/stdlibc
**
** Made by davy tran
** Login   <tran_y@epitech.net>
**
** Started on  Wed Feb  4 14:54:13 2015 davy tran
** Last update Wed Sep 30 15:42:55 2015 davy
*/

#ifndef GLOBAL_H_
# define GLOBAL_H_

# include <stdlib.h>
# include <stdbool.h>

typedef void *  pointer;
typedef void *  value_type;
typedef void *  key_type;
typedef void *  first_type;
typedef void *  second_type;

typedef size_t  size_type;

typedef bool  (*Predicate)(const value_type val);
typedef bool  (*Compare)(const value_type a, const value_type b);
typedef int   (*key_compare)(const value_type a, const value_type b);
typedef int   (*value_compare)(const value_type a, const value_type b);
typedef bool  (*BinaryPredicate)(const value_type a, const value_type b);

/*
** Use to swap 2 pointers with XOR operator method
*/
# define SWAP_PTR(a, b)                           \
{                                                 \
  (a) = (void *)((size_t)((a)) ^ (size_t)((b)));  \
  (b) = (void *)((size_t)((b)) ^ (size_t)((a)));  \
  (a) = (void *)((size_t)((a)) ^ (size_t)((b)));  \
}

# define SWAP_NBR(a, b) \
{                       \
  (a) ^= (b);           \
  (b) ^= (a);           \
  (a) ^= (b);           \
}

#endif /* !GLOBAL_H_ */
