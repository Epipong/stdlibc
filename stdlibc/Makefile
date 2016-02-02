##
## Makefile for std in /home/davy/Rendu/stdlibc/stdlibc
##
## Made by davy tran
## Login   <tran_y@epitech.net>
##
## Started on  Wed Feb  4 14:20:50 2015 davy tran
## Last update Tue Aug  4 12:10:50 2015 davy
##

SOURCES	= lib/std.c 										\
					lib/string/string.c 					\
					lib/list/list.c 							\
					lib/deque/deque.c 						\
					lib/vector/vector.c 					\
					lib/sdl/sdl.c									\
					lib/map/map.c									\
					lib/math/vector2.c						\
					lib/math/vector3.c						\
					lib/math/vector4.c						\
					lib/component/component.c			\
					lib/engine/engine.c						\
					lib/game_object/game_object.c	\
					lib/message/message.c					\
					lib/system/audio.c						\
					lib/system/game_logic.c				\
					lib/system/graphic.c					\
					lib/system/input.c						\
					lib/system/object_factory.c		\
					lib/system/physic.c						\
					lib/system/system.c						\
					lib/system/ui.c

OBJECTS		=	$(SOURCES:.c=.o)

REMOVE		=	rm -f

ARCHIVE		=	ar
GENERATOR	=	ranlib

COMPILER	=	clang

CFLAGS		+= -Iincludes -std=c11
CFLAGS		+= -D_BSD_SOURCE -D_GNU_SOURCE

RELEASE	= N
DEBUG		=	N
SDL			= N

ifeq ($(SDL), Y)
LFLAGS	+= -L/usr/local/lib/ -lSDL2
CFLAGS	+= -I/usr/local/include/
endif

ifeq ($(DEBUG), Y)
CFLAGS	+= -g3
endif

ifeq ($(RELEASE), Y)
CFLAGS 	+= -Wall -Wextra -Werror
endif

NAME		=	libstd.a

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
