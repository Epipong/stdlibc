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
