##
## Makefile for std in /home/davy/Rendu/stdlibc/stdlibc
## 
## Made by davy tran
## Login   <tran_y@epitech.net>
## 
## Started on  Wed Feb  4 14:20:50 2015 davy tran
## Last update Tue Aug  4 12:10:50 2015 davy
##

SOURCES		=	lib/std.c \
			lib/string/string.c \
			lib/list/list.c \
			lib/deque/deque.c \
			lib/vector/vector.c \
			lib/map/map.c

OBJECTS		=	$(SOURCES:.c=.o)

REMOVE		=	rm -f

ARCHIVE		=	ar
GENERATOR	=	ranlib

COMPILER	=	clang

CFLAGS		+=	-Wall -Wextra -Werror -D_BSD_SOURCE -D_GNU_SOURCE
CFLAGS		+=	-Iincludes

DEBUG		=	N

ifeq ($(DEBUG), Y)
CFLAGS		+=	-g3
endif

NAME	=	libstd.a

all:		$(NAME)

$(NAME):	$(OBJECTS)
		$(ARCHIVE) rc $(NAME) $(OBJECTS)
		$(GENERATOR) $(NAME)

clean:
		$(REMOVE) $(OBJECTS)

fclean:		clean
		$(REMOVE) $(NAME)

re:		fclean all

.c.o:
		$(COMPILER) $(CFLAGS) -c -o $@ $<

.PHONY:		all debug clean fclean re
