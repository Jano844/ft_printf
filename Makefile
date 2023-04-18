CC  = cc
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra

SOURCE = ft_printf.c ft_putchar_fd.c ft_strchr.c ft_num_args.c ft_putnbr_fd.c ft_putstr_fd.c ft_put_unsigned_nbr_fd.c ft_puthex_fd.c

OBJECTS = $(SOURCE:.c=.o)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all : $(NAME)

.PHONY : clean fclean re all

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f $(OBJECTS) $(NAME)

re: fclean all

