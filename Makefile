NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O2 
MAKE_LIB = ar -rcs

 SRCS = main.c #/*$(wildcard *.c)
OBJS = $(SRCS:.c=.o)
EXCLUDED_FILES = base.c \
				old_base.c


SRCS := $(filter-out $(EXCLUDED_FILES), $(SRCS))

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean :
	rm -f $(OBJS) $(ARCHIVE)

fclean : clean
	rm -f $(NAME)
	

re : fclean all

.PHONY : all clean fclea re