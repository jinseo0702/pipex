CC = cc
CFLAG = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = src/pipex.c \
	   src/is_path.c \
	   src/process.c

OBJS = $(SRCS:.c=.o)
NAME = pipex
LIB = pipex.a


all : $(NAME)

$(NAME) : $(LIB)
	make -C libft/
	make -C ft_printf/
	$(CC) $(CFLAG) -o $@ $^ -L libft/ -lft -L ft_printf/ -lftprintf

$(LIB) : $(OBJS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
clean :
	make clean -C libft/
	make clean -C ft_printf/
	$(RM) $(OBJS)

fclean : 
	make fclean -C libft/
	make fclean -C ft_printf/
	$(RM) $(OBJS) $(NAME) $(LIB)

re : 
	make fclean
	make all

.PHONY: all clean fclean re
