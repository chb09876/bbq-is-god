NAME = libft.a
CC = gcc
AFLAGS = rc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJECTS = $(SRCS:.c=.o)
HEADER = libft.h
all : $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

$(NAME) : $(OBJECTS)
	ar $(AFLAGS) $@ $?
%.o : %c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY : all clean fclean re
