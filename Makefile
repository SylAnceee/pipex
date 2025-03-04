NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c execution.c execution2.c
OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a
INF = infile

all: tag $(INF) $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(OBJS) $(LIB) -o $@

$(LIB):
	@make -C ./libft

$(INF):
	@touch $@

tag:
	@echo "$(BGreen)"
	@echo "██████╗ ██╗██████╗ ███████╗██╗  ██╗"
	@echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝"
	@echo "██████╔╝██║██████╔╝█████╗   ╚███╔╝ "
	@echo "██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ "
	@echo "██║     ██║██║     ███████╗██╔╝ ██╗"
	@echo "╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝"

clean:
	@make clean -C ./libft
	@rm -rf $(OBJS)

fclean:
	@make fclean -C ./libft
	@rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all bonus tag clean fclean re