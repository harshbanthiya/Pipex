NAME = pipex
CC = gcc  
CFLAGS = -Wall -Werror -Wextra -c
RM = rm -f

HEADER = ft_pipex.h

SRCS = ft_pipex.c \
	   pipex_utils.c \
	   pipex_utils2.c \
	   main.c

OBJS = $(SRCS:.c=.o)

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) -o pipex $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re
