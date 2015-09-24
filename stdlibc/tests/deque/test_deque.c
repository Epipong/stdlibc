/*
** test_deque.c for test_deque in /home/davy/Templates/stdlibc/stdlibc
**
** Made by davy
** Login   <davy@epitech.net>
**
** Started on  Sat Jun 13 21:32:37 2015 davy
** Last update Thu Sep 24 17:52:11 2015 davy
*/

#define _GENERIC

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "std.h"

typedef struct s_unittest	unittest;

static deque	g_test = {0};
static bool	g_ok = true;

struct	s_unittest
{
  int	_errors_current;
  int	_errors_max;
  bool	(*_compare)(void *a, void *b);

  void	(*set_up)(unittest *this);
  void	(*tear_down)(unittest *this);

  void	(*assert_equal)(unittest *this, void *first, void *second);
  void	(*assert_not_equal)(unittest *this, void *first, void *second);
  void	(*assert_true)(unittest *this, void *expr);
  void	(*assert_false)(unittest *this, void *expr);
  void	(*assert_list_equal)(unittest *this, list *list1, list *list2);
  void	(*assert_in)(unittest *this, void *member, list *container);
  void	(*assert_not_in)(unittest *this, void *member, list *container);

  int   __start__;
  void	(*test_push_back)(unittest *this);
  void	(*test_push_front)(unittest *this);
  void	(*test_at)(unittest *this);
  void	(*test_front)(unittest *this);
  void	(*test_back)(unittest *this);
  void	(*test_assign)(unittest *this);
  void	(*test_pop_back)(unittest *this);
  void	(*test_pop_front)(unittest *this);
  int	__end__;

  void	(*run)(unittest *this);
};

static bool	_compare_pointer(void *a, void *b)
{
  return (a == b);
}

static bool	_compare_integer(void *a, void *b)
{
  bool		is_equal;

  is_equal = *((int *)a) == *((int *)b);
  return (is_equal);
}

static bool	_compare_deque(void *a, void *b)
{
  iterator	it1;
  iterator	it2;

  it1 = begin(*((deque *)a));
  it2 = begin(*((deque *)b));
  while (it1 != NULL)
  {
    if (!_compare_integer(it1->value, it2->value))
      return (false);
    INCREMENT_IT(it1);
    INCREMENT_IT(it2);
  }
  return (true);
}

static void	_start(char const *function, int line)
{
  fprintf(stdout, "\tRun %s: line %d", function, line);
  g_ok = true;
}

static void	_end(void)
{
  fprintf(stdout, "%s\n", g_ok ? " [\033[32mok\033[0m]" : "");
  g_ok = true;
}

static void	set_up(unittest *this)
{
  constructor(g_test);
  this->_compare = _compare_pointer;
}

static void	tear_down(unittest *this)
{
  destructor(g_test);
}

static void	assert_equal(unittest *this, void *first, void *second)
{
  if (!this->_compare(first, second))
  {
    ++this->_errors_current;
    g_ok = false;
  }
  ++this->_errors_max;
  assert(this->_compare(first, second));
}

static void	assert_not_equal(unittest *this, void *first, void *second)
{
  if (this->_compare(first, second))
  {
    ++this->_errors_current;
    g_ok = false;
  }
  ++this->_errors_max;
}

static void	assert_true(unittest *this, void *expr)
{
  bool		is_true;

  is_true = *((bool *)expr);
  if (!is_true)
  {
    ++this->_errors_current;
    g_ok = false;
    fprintf(stdout, " %p is %s", expr, is_true ? "true" : "false");
  }
  ++this->_errors_max;
}

static void	assert_false(unittest *this, void *expr)
{
  bool		is_false;

  is_false = !(*((bool *)expr));
  if (is_false)
  {
    ++this->_errors_current;
    g_ok = false;
    fprintf(stdout, " %p is %s", expr, is_false ? "true" : "false");
  }
  ++this->_errors_max;
}

static void	assert_list_equal(unittest *this, list *list1, list *list2)
{
  ++this->_errors_max;
}

static void	assert_in(unittest *this, void *member, list *list2)
{
  ++this->_errors_max;
}

static void	assert_not_in(unittest *this, void *member, list *list2)
{
  ++this->_errors_max;
}

static void	test_push_back(unittest *this)
{
  int		data;
  size_type	sizes[2] = {0, 1};

  _start(__FUNCTION__, __LINE__ - 5);
  data = 1;
  push_back(g_test, &data);
  sizes[0] = DEQUE.size(&g_test);
  this->_compare = _compare_integer;
  this->assert_equal(this, sizes, sizes + 1);
  _end();
}

static void	test_push_front(unittest *this)
{
  int		data;
  size_type	sizes[2] = {0, 1};

  _start(__FUNCTION__, __LINE__ - 5);
  data = 1;
  push_front(g_test, &data);
  sizes[0] = DEQUE.size(&g_test);
  this->_compare = _compare_integer;
  this->assert_equal(this, sizes, sizes + 1);
  _end();
}

static void	test_at(unittest *this)
{
  int		data;
  int		res;

  _start(__FUNCTION__, __LINE__ - 5);
  data = 1;
  push_front(g_test, &data);
  this->assert_equal(this, at(g_test, 0), &data);
  this->assert_not_equal(this, at(g_test, 1), &data);
  this->assert_equal(this, at(g_test, 1), NULL);
  _end();
}

static void	test_front(unittest *this)
{
  int		datas[] = {52, 12, 74, 64};
  int		res;

  _start(__FUNCTION__, __LINE__ - 5);
  push_back(g_test, datas);
  push_back(g_test, &(datas[1]));
  push_back(g_test, &(datas[2]));
  push_back(g_test, &(datas[3]));
  this->_compare = _compare_integer;
  this->assert_equal(this, front(g_test), datas);
  _end();
}

static void	test_back(unittest *this)
{
  int		datas[] = {52, 12, 74, 64};
  int		res;

  _start(__FUNCTION__, __LINE__ - 5);
  push_back(g_test, datas);
  push_back(g_test, &(datas[1]));
  push_back(g_test, &(datas[2]));
  push_back(g_test, &(datas[3]));
  this->_compare = _compare_integer;
  this->assert_equal(this, back(g_test), &(datas[3]));
  _end();
}

static void	test_assign(unittest *this)
{
  deque		d;
  int		datas[] = {52, 12, 74, 64};

  constructor(d);
  _start(__FUNCTION__, __LINE__ - 6);
  push_back(d, datas);
  push_back(d, &(datas[1]));
  push_back(d, &(datas[2]));
  push_back(d, &(datas[3]));
  DEQUE.assign(&g_test, begin(d), end(d)->forward);
  this->_compare = _compare_deque;
  this->assert_equal(this, &g_test, &d);
  this->_compare = _compare_integer;
  this->assert_equal(this, (int []){DEQUE.size(&g_test)}, (int []){4});
  this->assert_equal(this, at(g_test, 0), (int []){52});
  this->assert_equal(this, at(g_test, 1), (int []){12});
  _end();
  destructor(d);
}

static void	test_pop_back(unittest *this)
{
  int		datas[] = {52, 12, 74, 64};

  _start(__FUNCTION__, __LINE__ - 4);
  push_back(g_test, datas);
  push_back(g_test, datas + 1);
  push_back(g_test, datas + 2);
  push_back(g_test, datas + 3);
  this->_compare = _compare_integer;
  this->assert_equal(this, (int []){DEQUE.size(&g_test)}, (int []){4});
  pop_back(g_test);
  pop_back(g_test);
  this->assert_not_equal(this, (int []){DEQUE.size(&g_test)}, (int []){4});
  this->assert_equal(this, (int []){DEQUE.size(&g_test)}, (int []){2});
  this->assert_equal(this, at(g_test, 0), (int []){52});
  this->assert_equal(this, at(g_test, 1), (int []){12});
  _end();
}

static void	test_pop_front(unittest *this)
{
  int		datas[] = {52, 12, 74, 64};

  _start(__FUNCTION__, __LINE__ - 4);
  push_back(g_test, datas);
  push_back(g_test, datas + 1);
  push_back(g_test, datas + 2);
  push_back(g_test, datas + 3);
  this->_compare = _compare_integer;
  this->assert_equal(this, (int []){DEQUE.size(&g_test)}, (int []){4});
  pop_front(g_test);
  pop_front(g_test);
  this->assert_not_equal(this, (int []){DEQUE.size(&g_test)}, (int []){4});
  this->assert_equal(this, (int []){DEQUE.size(&g_test)}, (int []){2});
  this->assert_equal(this, at(g_test, 0), (int []){74});
  this->assert_equal(this, at(g_test, 1), (int []){64});
  _end();
}

static void	run(unittest *this)
{
  size_t	it;
  size_t	end;
  size_t	size;

  it = (size_t)(&this->__start__) + sizeof(this);
  end = (size_t)(&this->__end__);
  size = (end - it) / sizeof(this);
  fprintf(stdout, "Run %lu test%c in %s file.\n", size,
	  size > 1 ? 's' : '\0', __FILE__);
  while (it < end)
  {
    this->set_up(this);
    (*((void (**)(unittest *))it))(this);
    this->tear_down(this);
    it += sizeof(this);
  }
  fprintf(stdout, "Finished with %d error%c of %d.\n", this->_errors_current,
	  this->_errors_current > 1 ? 's' : '\0',
	  this->_errors_max);
}

static unittest g_unittest = {
  0,
  0,
  &_compare_pointer,
  &set_up,
  &tear_down,
  &assert_equal,
  &assert_not_equal,
  &assert_true,
  &assert_false,
  &assert_list_equal,
  &assert_in,
  &assert_not_in,
  0,
  &test_push_back,
  &test_push_front,
  &test_at,
  &test_front,
  &test_back,
  &test_assign,
  &test_pop_back,
  &test_pop_front,
  0,
  &run,
};

#define UNITTEST	g_unittest

int		main(void)
{
  UNITTEST.run(&UNITTEST);
  return (0);
}
