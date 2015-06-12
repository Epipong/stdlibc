SOURCES =	test_deque.c

OBJECTS =	$(SOURCES:.c=.o)

TARGET =	unittest

COMPILER =	clang

REMOVE =	rm -f

all:		$(TARGET)

$(TARGET):	$(OBJECTS)
		$(COMPILER) -o $(TARGET) $(OBJECTS)

clean:
		$(REMOVE) $(OBJECTS)

fclean:		clean
		$(REMOVE) $(TARGET)

re:		fclean all

.PHONY:		all clean fclean re
