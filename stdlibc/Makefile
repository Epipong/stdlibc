SOURCES		=	source/std.c \
			lib/string/string.c \
			lib/list/list.c \
			lib/deque/deque.c

OBJECTS		=	$(SOURCES:.c=.o)

REMOVE		=	rm -f

ARCHIVE		=	ar
GENERATOR	=	ranlib

COMPILER	=	clang

CFLAGS		+=	-Wall
CFLAGS		+=	-Iinclude

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
