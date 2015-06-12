SOURCES =	test_deque.c

OBJECTS =	$(SOURCES:.c=.o)

TARGET =	unittest

COMPILER =	clang

REMOVE =	rm -f

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
