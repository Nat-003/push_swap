NAME        = push_swap

# Compiler and Flags
CC          = cc
# CFLAGS      = -Wall -Wextra -Werror -I.

# Source Files
# We list them explicitly to be safe, but include the 'operation' subdirectory
SRCS        = main.c \
              parser.c \
              utils.c \
              ft_split.c \
              disorder.c \
              bench.c \
              simple.c \
              radix.c \
              medium.c \
              operation/push_op.c \
              operation/reverse_rotate_op.c \
              operation/rotate_op.c \
              operation/swap_op.c

# Object Files
# This replaces the .c extension with .o
OBJS        = $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

# Standard clean rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re