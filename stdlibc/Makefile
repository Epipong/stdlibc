##
## Makefile for std in /home/davy/Rendu/stdlibc/stdlibc
## 
## Made by davy tran
## Login   <tran_y@epitech.net>
## 
## Started on  Wed Feb  4 14:20:50 2015 davy tran
## Last update Wed Feb  4 19:13:57 2015 davy tran
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

CFLAGS		+=	-Wall
CFLAGS		+=	-Iincludes

NAME	=	libstd.a

all:		$(NAME)

debug:		CFLAGS += -g3
debug:		re

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
