/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:55:58 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 18:57:18 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define LONG_MIN -9223372036854775808U

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			sharp;
	int			zero;
}				t_flags;

typedef struct	s_print
{
	t_flags		*flags;
	int			width;
	int			prec;
	int			size;
	char		type;
}				t_print;

int				ft_is_type(char c);
void			flags_filler(char *str, t_print *all);
void			struct_filler(char *str, t_print *all, int j);
void			size_filler(char *str, t_print *all);
void			struct_checker(t_print *all);
int				struct_creator(char *s, int *words, t_print *all, va_list ap);

char 			*ft_itoa_base(long long int nbr, int base);
int				ft_output(t_print *all, char *str, int size);
int				ft_choose_function(t_print *all, va_list ap);

int				ft_printf_string(t_print *all, va_list ap);
int				ft_printf_char(t_print *all, va_list ap);
int				ft_printf_pointer(t_print *all, va_list ap);
int				ft_printf_hex(t_print *all, va_list ap);
int				ft_printf_octal(t_print *all, va_list ap);
int				ft_printf_decimal(t_print *all, va_list ap);
int				ft_printf_unsigned(t_print *all, va_list ap);
int				ft_printf_percent(t_print *all);

int				ft_printf(char *format, ...);

#endif
