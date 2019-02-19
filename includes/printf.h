/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:55:58 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/19 14:38:50 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define INF		(1.0L / 0)
# define INF_M		(-1.0L / 0)

typedef struct			s_flags
{
	int					minus;
	int					plus;
	int					space;
	int					sharp;
	int					zero;
	int					noll;
}						t_flags;

typedef struct			s_float
{
	int					len_pre;
	int					len_after;
	unsigned long long	flo;
	long double			doub;
	int					spec;
	char				*str;
}						t_float;

typedef struct			s_filler
{
	int					width;
	int					prec;
	int					flaq;
}						t_filler;

typedef struct			s_print
{
	t_flags				*flags;
	t_filler			*filler;
	t_float				*floa;
	int					width;
	int					prec;
	int					size;
	char				type;
}						t_print;

int						ft_is_upp(char c);
int						ft_is_type(char c);
void					flags_filler(char *str, t_print *all);
void					struct_filler(char *str, t_print *all, int j);
void					size_filler(char *str, t_print *all);
int						struct_creator(char *s, int *words,
								t_print *all, va_list ap);
void					init_struct(t_print *all);

char					*ft_itoa_base(long long int nbr, int base);
int						ft_str_int(long long int nbr);
int						ft_output(t_print *all, char *str, int size);
int						ft_choose_function(t_print *all, va_list ap);

int						ft_printf_string(t_print *all, va_list ap);
int						ft_printf_char(t_print *all, va_list ap);
int						ft_printf_pointer(t_print *all, va_list ap);
int						ft_printf_hex(t_print *all, va_list ap);
int						ft_printf_octal(t_print *all, va_list ap);
int						ft_printf_decimal(t_print *all, va_list ap);
int						ft_printf_unsigned(t_print *all, va_list ap);
int						ft_printf_percent(t_print *all);
int						ft_printf_float(t_print *all, va_list ap);
int						ft_printf_bits(int count, va_list ap);

int						ft_printf(char *format, ...);

#endif
