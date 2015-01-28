#include <stdio.h>
#include "std.h"

static void	string_test()
{
  string	str;
  string	*s;
  int		age;

  age = 21;

// constructor of string
  std.string->constructor(&str, "Je suis ");

  printf("size: %zu\n", std.string->size(&str));
  printf("capacity: %zu\n", std.string->capacity(&str));

  printf("\n================\n\n");
  printf("change capacity to 32\n");

// resize string
  std.string->resize(&str, 28);
  printf("size: %zu\n", std.string->size(&str));
  printf("capacity: %zu\n", std.string->capacity(&str));

  printf("str[%d] = %c\n", 5, std.string->at(&str, 5));

// append string
  std.string->append(&str, "Davy ");

// push back a character
  std.string->push_back(&str, '!');

// insert a string into main string
  std.string->insert(&str, std.string->size(&str), " Et j'ai ");

  printf("%s", std.string->c_str(&str));

// int to string conversion
  s = std.to_string(age);
  printf("%s\n", s->str);

  std.string->destructor(&str);
  std.string->destructor(s);
  free(s);
}

static bool	list_unique_int(const value_type a, const value_type b)
{
  return (*((int *)a) == *((int *)b));
}

static bool	list_compare_int(const value_type a, const value_type b)
{
  return (*((int *)a) > *((int *)b));
}

static void	list_test_splice()
{
  list		mylist1, mylist2;
  iterator	it;
  iterator	end;

  std.list->constructor(&mylist1);
  std.list->constructor(&mylist2);

  // set some initial values:
  {
    int		v[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; ++i)
      std.list->push_back(&mylist1, &(v[i]));	// mylist1: 1 2 3 4
  }

  {
    int		v[] = {10, 20, 30};
    for (int i = 0; i < 3; ++i)
      std.list->push_back(&mylist2, &(v[i]));	// mylist2: 10 20 30
  }

  it = std.list->begin(&mylist1);
  it = it->forward;				// points to 2

  std.list->merge(&mylist1, &mylist2, &list_compare_int);
  /* std.list->splice(&mylist1, it, &mylist2);	// mylist1: 1 10 20 30 2 3 4 */
  /* 						// mylist2 (empty) */
  /* 						// "it" still points to 2 (the 5th element) */

  printf("mylist1 contains:");
  for (it = std.list->begin(&mylist1); it != NULL; it = it->forward)
    printf(" %d", *((int *)it->value));
  printf("\n");

  printf("mylist2 contains:");
  for (it = std.list->begin(&mylist2); it != NULL; it = it->forward)
    printf(" %d", *((int *)it->value));
  printf("\n");

  std.list->destructor(&mylist1);
  std.list->destructor(&mylist2);
}

static void	list_test_unique()
{
  list		mylist;
  int		val[] = {77, 5, 21, 41, 5, 32, 14, 32, 14, 77, 41, 53, 41, 21, 77};
  int		i;
  iterator	it;

  std.list->constructor(&mylist);

// put values in list and dump
  for (i = 0; i < 15; ++i)
  {
    printf("%d ", val[i]);
    std.list->push_back(&mylist, &(val[i]));
  }
  printf("\n");

// unique my list
  std.list->unique(&mylist, &list_unique_int);

// sort my list order by value asc
  std.list->sort(&mylist, &list_compare_int);

// reverse list
  std.list->reverse(&mylist);

// dump my list
  it = std.list->begin(&mylist);
  while (!std.list->empty(&mylist))
  {
    printf("%d ", *((int *)std.list->front(&mylist)));
    std.list->pop_front(&mylist);
  }  
  printf("\n");

  std.list->destructor(&mylist);
}

static void	deque_test()
{
  deque		mydeque;
  int		val = 10;

  std.deque->constructor(&mydeque);
  std.deque->push_back(&mydeque, &val);
  std.deque->resize(&mydeque, 10);
  printf("size: %zu\n", std.deque->size(&mydeque));
  printf("content: %d\n", *((int *)std.deque->front(&mydeque)));
  std.deque->resize(&mydeque, 5);
  printf("size: %zu\n", std.deque->size(&mydeque));
  printf("content: %d\n", *((int *)std.deque->front(&mydeque)));
  std.deque->destructor(&mydeque);
}

int		main(/*int argc, char const *argv[]*/)
{
  /* string_test(); */
  /* list_test_unique(); */
  list_test_splice();
  /* deque_test(); */
  return (EXIT_SUCCESS);
}
