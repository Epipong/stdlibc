#ifndef GLOBAL_H_
# define GLOBAL_H_

# include <stdlib.h>
# include <stdbool.h>

typedef void *	InputIterator;
typedef void *	pointer;
typedef void *	value_type;
typedef void *	key_type;
typedef void *	value_compare;

typedef size_t	size_type;

typedef bool	(*Predicate)(const value_type val);
typedef bool	(*Compare)(const value_type a, const value_type b);
typedef bool	(*key_compare)(const value_type a, const value_type b);
typedef bool	(*BinaryPredicate)(const value_type a, const value_type b);

#endif /* !GLOBAL_H_ */
