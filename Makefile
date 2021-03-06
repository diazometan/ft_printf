# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 14:59:20 by lwyl-the          #+#    #+#              #
#    Updated: 2019/02/19 18:26:06 by lwyl-the         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC =	sources/ft_itoa_base.c\
		sources/ft_final_print.c\
		sources/ft_struct_one.c\
		sources/ft_struct_two.c\
		sources/ft_choose_function.c\
		sources/ft_printf_string.c\
		sources/ft_printf_char.c\
		sources/ft_printf_pointer.c\
		sources/ft_printf_hex.c\
		sources/ft_printf_octal.c\
		sources/ft_printf_decimal.c\
		sources/ft_printf_percent.c\
		sources/ft_printf_unsigned.c\
		sources/ft_printf_float.c\
		sources/ft_printf_bits.c\
		sources/ft_printf.c

SRC_LIB =	libft/ft_putchar.c\
			libft/ft_putstr.c\
			libft/ft_strlen.c\
			libft/ft_strsub.c\
			libft/ft_atoi.c\
			libft/ft_isdigit.c\
			libft/ft_memset.c\
			libft/ft_strchr.c\
			libft/ft_strdel.c\
			libft/ft_strdup.c\
			libft/ft_strcmp.c\
			libft/ft_strnew.c

OBJ = $(SRC:.c=.o)

OBJ_LIB = $(SRC_LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_LIB) $(OBJ)
	ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	ranlib $(NAME)

.c.o:
	gcc $(FLAGS) -I includes -I libft/includes -o $@ -c $<

clean:
	rm -rf $(OBJ)
	cd libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd libft && make fclean

re: fclean all
