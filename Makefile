# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 14:59:20 by lwyl-the          #+#    #+#              #
#    Updated: 2019/02/12 15:12:47 by lwyl-the         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

NAME_LIB = libftprintf.a

LIB = libft/libft.a

SRC =	sources/ft_itoa_base.c\
		sources/ft_final_print.c\
		sources/ft_struct.c\
		sources/ft_choose_function.c\
		sources/ft_printf_string.c\
		sources/ft_printf_char.c\
		sources/ft_printf_pointer.c\
		sources/ft_printf_hex.c\
		sources/ft_printf_octal.c\
		sources/ft_printf_decimal.c\
		sources/ft_printf_percent.c\
		sources/ft_printf_unsigned.c\
		sources/ft_simple.c

SRC_LIB =	libft/ft_putchar.c\
			libft/ft_putstr.c\
			libft/ft_strlen.c\
			libft/ft_strsub.c\
			libft/ft_atoi.c\
#OBJ = $(SRC:.c=.o)

#all: $(NAME)

#$(NAME): $(OBJ) $(LIB)
#	gcc -o $(NAME) -Llibft -lft $(OBJ)

#.c.o:
#	gcc -I includes -Ilibft -o $@ -c $<

#$(LIB):
#	cd libft && make
#	cd libft && make clean

#clean:
#	rm -f $(OBJ)

#fclean: clean
#	rm -f $(NAME)
#	cd libft && make fclean

#re: fclean all

OBJ = $(SRC:.c=.o)

OBJ_LIB = $(SRC_LIB:.c=.o)

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ) $(OBJ_LIB)
	ar rc $(NAME_LIB) $(OBJ) $(OBJ_LIB)
	ranlib $(NAME_LIB)

$(OBJ): $(SRC)
	gcc -c $(SRC) -I includes

$(OBJ_LIB): $(SRC_LIB)
	gcc -c $(SRC_LIB) -I libft/includes

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME_LIB)

re: fclean all
