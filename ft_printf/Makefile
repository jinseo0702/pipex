CC = cc
CFLAG = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

SRCS = ft_memset.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putaddress.c \
	ft_putnbr.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
HEADER = libftprintf.h


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : 
	$(RM) $(OBJS) $(NAME)

re : 
	make fclean 
	make all

.PHONY: all clean fclean re
