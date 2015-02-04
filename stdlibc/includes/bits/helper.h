/*
** helper.h for helper in /home/davy/Rendu/stdlibc/stdlibc
** 
** Made by davy tran
** Login   <tran_y@epitech.net>
** 
** Started on  Wed Feb  4 14:54:13 2015 davy tran
** Last update Wed Feb  4 19:15:39 2015 davy tran
*/

#ifndef GLOBAL_H_
# define GLOBAL_H_

# include <stdlib.h>
# include <stdbool.h>

typedef void *	InputIterator;
typedef void *	pointer;
typedef void *	value_type;
typedef char *	key_type;
typedef void *	first_type;
typedef void *	second_type;

typedef size_t	size_type;

typedef bool	(*Predicate)(const value_type val);
typedef bool	(*Compare)(const value_type a, const value_type b);
typedef int	(*key_compare)(const value_type a, const value_type b);
typedef int	(*value_compare)(const value_type a, const value_type b);
typedef bool	(*BinaryPredicate)(const value_type a, const value_type b);

#endif /* !GLOBAL_H_ */
