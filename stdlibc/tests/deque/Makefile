##
## Makefile for unittest in /home/davy/Templates/stdlibc/stdlibc
## 
## Made by davy
## Login   <tran_y@epitech.net>
## 
## Started on  Fri Jun 26 16:17:23 2015 davy
## Last update Mon Jun 29 10:13:37 2015 davy
##

SOURCES =	test_deque.c

OBJECTS =	$(SOURCES:.c=.o)

TARGET =	unittest.out

COMPILER =	clang

REMOVE =	rm -f

CFLAGS +=	-Wall -Wextra -Werror -D_BSD_SOURCE -D_GNU_SOURCE -std=c99
CFLAGS =	-I ../../includes/

LIBS =		../../libstd.a

all:		$(TARGET)

$(TARGET):	$(OBJECTS)
		$(COMPILER) -o $(TARGET) $(OBJECTS) $(LIBS)

clean:
		$(REMOVE) $(OBJECTS)

fclean:		clean
		$(REMOVE) $(TARGET)

re:		fclean all

.c.o:
		$(COMPILER) $(CFLAGS) -c -o $@ $<

.PHONY:		all clean fclean re
