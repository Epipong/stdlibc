#stdlibc
*A simple standard C library.*

##Contents
* deque
* list
* map
* string
* vector

###deque
*Double ended queue*

Members functions

constructor | Construct deque container
------------|---
destructor  | Deque destructor

Iterators:

begin | Return iterator to beginning
------|---
end   | Return iterator to end


size     | Return size
---------|---
max_size | Return maximum size
resize   | Change size
empty    | Test whether container is empty


at       | Access element
---------|---
front    | Access first element
back     | Access last element


assign     | Assign container content
-----------|---
push_back  | Add element at the end
push_front | Add element at the beginning
pop_back   | Delete last element
pop_front  | Delete first element
insert     | Insert elements
erase      | Erase elements
swap       | Swap content
clear      | Clear content
