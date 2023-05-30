NAME = libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS			=	ft_putchar.c\
					ft_putstr.c\
					ft_putdec.c\
					ft_putnbr.c\
					ft_puthex.c\
					ft_printf.c\
					ft_putnbr_unsigned.c\
					ft_itoa.c\
					ft_itoa_unsigned.c\

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@ar rcs $(NAME) $(OBJS)

%.o: %.c
	gcc -c $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus