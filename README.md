# stdlibc
*A simple standard C library with STL like.*

## Contents
* deque
* list
* map
* string
* vector

## Usage
There are some generic macro like _constructor_ whose work with all custom type.

> exemple:

```
#include <stdio.h>

#include "std.h"

int main(void)
{
  deque d;
  map m;

  constructor(d);
  constructor(m);

  insert(m, "deque", &d);  // insert deque into map.
  push_back(d, "42");  // push back 42 into deque.

  printf("m['%s'].front() = %s\n", "deque",
         front(*((deque *)at(m, "deque"))));

  destructor(d);
  destructor(m);
  return (0);
}
```

> results will display

```$> m['deque'].front() = 42```
