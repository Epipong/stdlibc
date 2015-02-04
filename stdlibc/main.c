/*
** main.c for main in /home/davy/Rendu/stdlibc/stdlibc
** 
** Made by davy tran
** Login   <davy@epitech.net>
** 
** Started on  Wed Feb  4 19:14:15 2015 davy tran
** Last update Wed Feb  4 19:14:40 2015 davy tran
*/

#include <stdio.h>
#include "std.h"

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

  LIST.constructor(&mylist1);
  LIST.constructor(&mylist2);

  // set some initial values:
  {
    int		v[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; ++i)
      LIST.push_back(&mylist1, &(v[i]));	// mylist1: 1 2 3 4
  }

  {
    int		v[] = {10, 20, 30};
    for (int i = 0; i < 3; ++i)
      LIST.push_back(&mylist2, &(v[i]));	// mylist2: 10 20 30
  }

  it = LIST.begin(&mylist1);
  INCREMENT_IT(it);				// points to 2

  LIST.merge(&mylist1, &mylist2, &list_compare_int);
  /* LIST.splice(&mylist1, it, &mylist2);	// mylist1: 1 10 20 30 2 3 4 */
  /* 						// mylist2 (empty) */
  /* 						// "it" still points to 2 (the 5th element) */

  printf("mylist1 contains:");
  for (it = LIST.begin(&mylist1); it != NULL; it = it->forward)
    printf(" %d", *((int *)it->value));
  printf("\n");

  printf("mylist2 contains:");
  for (it = LIST.begin(&mylist2); it != NULL; it = it->forward)
    printf(" %d", *((int *)it->value));
  printf("\n");

  LIST.destructor(&mylist1);
  LIST.destructor(&mylist2);
}

static void	list_test_unique()
{
  list		mylist;
  int		val[] = {77, 5, 21, 41, 5, 32, 14, 32, 14, 77, 41, 53, 41, 21, 77};
  int		i;
  iterator	it;

  LIST.constructor(&mylist);

// put values in list and dump
  for (i = 0; i < 15; ++i)
  {
    printf("%d ", val[i]);
    LIST.push_back(&mylist, &(val[i]));
  }
  printf("\n");

// unique my list
  LIST.unique(&mylist, &list_unique_int);

// sort my list order by value asc
  LIST.sort(&mylist, &list_compare_int);

// reverse list
  LIST.reverse(&mylist);

// dump my list
  it = LIST.begin(&mylist);
  while (!LIST.empty(&mylist))
  {
    printf("%d ", *((int *)LIST.front(&mylist)));
    LIST.pop_front(&mylist);
  }  
  printf("\n");

  LIST.destructor(&mylist);
}

static void	deque_test()
{
  deque		mydeque;
  int		val = 10;

  DEQUE.constructor(&mydeque);
  DEQUE.push_back(&mydeque, &val);
  DEQUE.resize(&mydeque, 10);
  printf("size: %zu\n", DEQUE.size(&mydeque));
  printf("content: %d\n", *((int *)DEQUE.front(&mydeque)));
  DEQUE.resize(&mydeque, 5);
  printf("size: %zu\n", DEQUE.size(&mydeque));
  printf("content: %d\n", *((int *)DEQUE.front(&mydeque)));
  DEQUE.destructor(&mydeque);
}

static void	map_test()
{
  map		foo;
  int		age = 21;
  char		buff[2] = {'\0', '\0'};

  MAP.constructor(&foo, NULL);

  for (char c = 'a'; c <= 'z'; ++c)
  {
    buff[0] = c;
    MAP.insert(&foo, (pair){buff, &age});
  }

  for (p_iterator it = MAP.begin(&foo); it != NULL; INCREMENT_IT(it))
    printf("\"%s\": %d\n", ((char *)it->first), *((int *)it->second));

  MAP.destructor(&foo);
}

int		main(/*int argc, char const *argv[]*/)
{
  /* list_test_unique(); */
  /* list_test_splice(); */
  /* deque_test(); */
  map_test();
  return (EXIT_SUCCESS);
}
