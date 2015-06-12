#include <stdio.h>
#include <stdbool.h>
#include "std.h"

typedef struct s_unittest	unittest;

static deque	g_data = {0};

struct	s_unittest
{
  int	_errors;
  bool	(*_compare)(void *a, void *b);
  
  void	(*set_up)(unittest *this);
  void	(*tear_down)(unittest *this);
  
  void	(*assert_equal)(unittest *this, void *a, void *b);
  void	(*assert_not_equal)(unittest *this, void *a, void *b);
  void	(*assert_in)(unittest *this);
  
  void	(*test_constructor)(unittest *this);

  void	(*run)(unittest *this);
};

static bool	_compare(void *a, void *b)
{
  return (a == b);
}

static void	set_up(unittest *this)
{
  DEQUE.constructor(&g_data);
  (void)this;
}

static void	tear_down(unittest *this)
{
  DEQUE.destructor(&g_data);
  (void)this;
}

static void	assert_equal(unittest *this, void *a, void *b)
{
  if (!this->_compare(a, b))
    ++this->_errors;
}

static void	assert_not_equal(unittest *this, void *a, void *b)
{
  if (this->_compare(a, b))
    ++this->_errors;
}

static void	assert_in(unittest *this)
{

}

static void	test_constructor(unittest *this)
{

}

static void	run(unittest *this)
{
  size_t	it;
  size_t	end;

  it = (size_t)this + 7 * sizeof(this->_compare);
  end = (size_t)this + sizeof(*this) - sizeof(this->run);
  printf("%lu tests\n", (end - it) >> 3);
  while (it < end)
  {
    this->set_up(this);
    (*((void (**)(unittest *))it))(this);
    this->tear_down(this);
    it += sizeof(this->_compare);
  }
}

static unittest g_unittest = {
  0,
  &_compare,
  &set_up,
  &tear_down,
  &assert_equal,
  &assert_not_equal,
  &assert_in,
  &test_constructor,
  &run,
};

#define UNITTEST	g_unittest

int		main(void)
{
  UNITTEST.run(&UNITTEST);  
  return (0);
}
