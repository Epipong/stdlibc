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

static void	list_test()
{
  list		mylist;
  int		val = 10;

  std.list->constructor(&mylist);
  std.list->push_back(&mylist, &val);
  std.list->resize(&mylist, 10);
  printf("size: %zu\n", std.list->size(&mylist));
  printf("content: %d\n", *((int *)std.list->front(&mylist)));
  std.list->resize(&mylist, 5);
  printf("size: %zu\n", std.list->size(&mylist));
  printf("content: %d\n", *((int *)std.list->front(&mylist)));
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
  /* list_test(); */
  deque_test();
  return (EXIT_SUCCESS);
}
