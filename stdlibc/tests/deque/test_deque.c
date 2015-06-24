/*
** test_deque.c for test_deque in /home/davy/Templates/stdlibc/stdlibc
**
** Made by davy
** Login   <davy@epitech.net>
**
** Started on  Sat Jun 13 21:32:37 2015 davy
** Last update Wed Jun 24 11:21:17 2015 davy
*/

#include <stdio.h>
#include <stdbool.h>
#include "std.h"

typedef struct s_unittest	unittest;

static deque	g_test = {0};

struct	s_unittest
{
  int	_errors_current;
  int	_errors_max;

  bool	(*_compare)(void *a, void *b);

  void	(*set_up)(unittest *this);
  void	(*tear_down)(unittest *this);

  void	(*assert_equal)(unittest *this, void *a, void *b);
  void	(*assert_not_equal)(unittest *this, void *a, void *b);
  void	(*assert_in)(unittest *this);

  int   __start__;

  void	(*test_push_back)(unittest *this);
  void	(*test_push_front)(unittest *this);
  void	(*test_at)(unittest *this);
  void	(*test_front)(unittest *this);

  int	__end__;

  void	(*run)(unittest *this);
};

static bool	compare_pointer(void *a, void *b)
{
  return (a == b);
}

static bool	compare_integer(void *a, void *b)
{
  return (*((int *)a) == *((int *)b));
}

static void	set_up(unittest *this)
{
  DEQUE.constructor(&g_test);
  this->_compare = compare_pointer;
}

static void	tear_down(unittest *this)
{
  DEQUE.destructor(&g_test);
  this->_compare = compare_pointer;
}

static void	assert_equal(unittest *this, void *a, void *b)
{
  if (!this->_compare(a, b))
    ++this->_errors_current;
  ++this->_errors_max;
}

static void	assert_not_equal(unittest *this, void *a, void *b)
{
  if (this->_compare(a, b))
    ++this->_errors_current;
  ++this->_errors_max;
}

static void	assert_in(unittest *this)
{
  ++this->_errors_max;
}

static void	test_push_back(unittest *this)
{
  int		data;
  size_type	sizes[2] = {0, 1};

  fprintf(stdout, "\tRun %s: l%d", __FUNCTION__, __LINE__ - 5);
  data = 1;
  DEQUE.push_back(&g_test, &data);
  sizes[0] = DEQUE.size(&g_test);
  this->_compare = compare_integer;

  this->assert_equal(this, sizes, sizes + 1);
}

static void	test_push_front(unittest *this)
{
  int		data;
  size_type	sizes[2] = {0, 1};

  fprintf(stdout, "\tRun %s: l%d", __FUNCTION__, __LINE__ - 5);
  data = 1;
  DEQUE.push_front(&g_test, &data);
  sizes[0] = DEQUE.size(&g_test);
  this->_compare = compare_integer;
  this->assert_equal(this, sizes, sizes + 1);
}

static void	test_at(unittest *this)
{
  int		data;
  int		res;

  fprintf(stdout, "\tRun %s: l%d", __FUNCTION__, __LINE__ - 5);
  data = 1;
  DEQUE.push_front(&g_test, &data);
  this->assert_equal(this, DEQUE.at(&g_test, 0), &data);
  this->assert_not_equal(this, DEQUE.at(&g_test, 1), &data);
  this->assert_equal(this, DEQUE.at(&g_test, 1), NULL);
}

static void	test_front(unittest *this)
{
  int		datas[] = {52, 12, 74, 64};
  int		res;

  fprintf(stdout, "\tRun %s: l%d", __FUNCTION__, __LINE__ - 5);
  DEQUE.push_back(&g_test, &(datas[0]));
  DEQUE.push_back(&g_test, &(datas[1]));
  DEQUE.push_back(&g_test, &(datas[2]));
  this->_compare = compare_integer;
  this->assert_equal(this, DEQUE.front(&g_test), &(datas[0]));
}

static void	run(unittest *this)
{
  size_t	it;
  size_t	end;
  size_t	size;

  it = (size_t)(&this->__start__) + sizeof(this);
  end = (size_t)(&this->__end__);
  size = (end - it) >> 3;
  fprintf(stdout, "Run %lu test%c.\n", size,
	  size > 1 ? 's' : '\0');
  while (it < end)
  {
    this->set_up(this);
    (*((void (**)(unittest *))it))(this);
    this->tear_down(this);
    it += sizeof(this);
  }
  fprintf(stdout, "Finished with %d of %d error%c.\n", this->_errors_current,
	  this->_errors_max,
	  this->_errors_current > 1 ? 's' : '\0');
}

static unittest g_unittest = {
  0,
  0,
  &compare_pointer,
  &set_up,
  &tear_down,
  &assert_equal,
  &assert_not_equal,
  &assert_in,
  0,
  &test_push_back,
  &test_push_front,
  &test_at,
  &test_front,
  0,
  &run,
};

#define UNITTEST	g_unittest

int		main(void)
{
  UNITTEST.run(&UNITTEST);
  return (0);
}
