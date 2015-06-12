#include <stdio.h>
#include <stdbool.h>
#include "std.h"

typedef struct s_unittest	unittest;

static deque	g_data = {0};

enum	e_error_type
{
  NUMBER_CURRENT_ERROR,
  NUMBER_MAX_ERROR,
};

static int	g_errors[] = {
  0,
  0,
};

struct	s_unittest
{
  bool	(*_compare)(void *a, void *b);
  
  void	(*set_up)(unittest *this);
  void	(*tear_down)(unittest *this);
  
  void	(*assert_equal)(unittest *this, void *a, void *b);
  void	(*assert_not_equal)(unittest *this, void *a, void *b);
  void	(*assert_in)(unittest *this);
  
  void	(*test_push_back)(unittest *this);
  void	(*test_push_front)(unittest *this);
  void	(*test_at)(unittest *this);

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
  DEQUE.constructor(&g_data);
  this->_compare = compare_pointer;
}

static void	tear_down(unittest *this)
{
  DEQUE.destructor(&g_data);
  this->_compare = compare_pointer;
}

static void	assert_equal(unittest *this, void *a, void *b)
{
  if (!this->_compare(a, b))
    ++g_errors[NUMBER_CURRENT_ERROR];
  ++g_errors[NUMBER_MAX_ERROR];
}

static void	assert_not_equal(unittest *this, void *a, void *b)
{
  if (this->_compare(a, b))
    ++g_errors[NUMBER_CURRENT_ERROR];
  ++g_errors[NUMBER_MAX_ERROR];
}

static void	assert_in(unittest *this)
{
  ++g_errors[NUMBER_MAX_ERROR];
}

static void	test_push_back(unittest *this)
{
  int		data;
  size_type	sizes[2] = {0, 1};

  data = 1;
  DEQUE.push_back(&g_data, &data);
  sizes[0] = DEQUE.size(&g_data);
  this->_compare = compare_integer;
  this->assert_equal(this, sizes, sizes + 1);
}

static void	test_push_front(unittest *this)
{
  int		data;
  size_type	sizes[2] = {0, 1};

  data = 1;
  DEQUE.push_front(&g_data, &data);
  sizes[0] = DEQUE.size(&g_data);
  this->_compare = compare_integer;
  this->assert_equal(this, sizes, sizes + 1);
}

static void	test_at(unittest *this)
{
  int		data;
  int		res;

  data = 1;
  DEQUE.push_front(&g_data, &data);

  // valid
  this->assert_equal(this, DEQUE.at(&g_data, 0), &data);

  // invalid
  this->assert_not_equal(this, DEQUE.at(&g_data, 1), &data);
  this->assert_equal(this, DEQUE.at(&g_data, 1), NULL);
}

static void	run(unittest *this)
{
  size_t	it;
  size_t	end;
  size_t	size;

  it = (size_t)this + 6 * sizeof(this->_compare);
  end = (size_t)this + sizeof(*this) - sizeof(this->run);
  size = (end - it) >> 3;
  printf("Run %lu test%c.\n", size,
	 size > 1 ? 's' : '\0');
  while (it < end)
  {
    this->set_up(this);
    (*((void (**)(unittest *))it))(this);
    this->tear_down(this);
    it += sizeof(this->_compare);
  }
  printf("Finished with %d of %d error%c.\n", g_errors[NUMBER_CURRENT_ERROR],
	   g_errors[NUMBER_MAX_ERROR],
	   g_errors[NUMBER_CURRENT_ERROR] > 1 ? 's' : '\0');
}

static unittest g_unittest = {
  &compare_pointer,
  &set_up,
  &tear_down,
  &assert_equal,
  &assert_not_equal,
  &assert_in,
  &test_push_back,
  &test_push_front,
  &test_at,
  &run,
};

#define UNITTEST	g_unittest

int		main(void)
{
  UNITTEST.run(&UNITTEST);  
  return (0);
}
