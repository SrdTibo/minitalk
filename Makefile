# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:13:31 by tserdet           #+#    #+#              #
#    Updated: 2022/12/16 14:42:40 by tserdet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT	=	ft_client/client.c\

SERVER	= ft_server/server.c\

FT_PRINTF = ft_printf/ft_extra_function.c ft_printf/ft_print_c.c ft_printf/ft_print_d.c \
			ft_printf/ft_print_i.c ft_printf/ft_print_modulo.c \
			ft_printf/ft_print_p.c ft_printf/ft_print_s.c ft_printf/ft_print_u.c \
			ft_printf/ft_print_x.c ft_printf/ft_print_xbis.c ft_printf/ft_printf.c\

PRINTF_OBJ	= $(FT_PRINTF:.c=.o)

SERVER_OBJ	= $(SERVER:.c=.o)

CLIENT_OBJ	= $(CLIENT:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

EXEC_SERVER	=	server

EXEC_CLIENT =	client

RM = rm -rf

all : 	$(EXEC_SERVER) $(EXEC_CLIENT)

$(EXEC_SERVER) : $(PRINTF_OBJ) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(PRINTF_OBJ) -o $(EXEC_SERVER)

$(EXEC_CLIENT) : $(PRINTF_OBJ) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(PRINTF_OBJ) -o $(EXEC_CLIENT)

clean :
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(PRINTF_OBJ)

fclean :	clean
	$(RM) $(EXEC_SERVER) $(EXEC_CLIENT)

re :		fclean all

.PHONY :	all clean fclean re
