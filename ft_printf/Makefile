NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC	= ft_extra_function.c ft_print_c.c ft_print_d.c ft_printf.c\
	  ft_print_i.c ft_print_modulo.c ft_print_p.c ft_print_s.c\
	  ft_print_u.c ft_print_x.c ft_print_xbis.c\

OBJ	= $(SRC:.c=.o)

all : 		$(NAME)
	
$(NAME) : 	$(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean :	clean
	rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
