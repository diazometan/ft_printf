/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:34:12 by jlesch            #+#    #+#             */
/*   Updated: 2019/02/12 19:00:34 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			ft_is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == 'f' || c == 'F' || c == 'c' || c == 's'
		|| c == 'p' || c == 'n' || c == '%')
		return (1);
	return (0);
}

int			ft_printf(char *format, ...)
{
	int		sdvig;
	int		words;
	t_print	all;
	va_list ap;

	words = 0;
	va_start(ap, format);
	while (*format)
	{
		sdvig = struct_creator(format, &words, &all, ap);
		format += sdvig;
	}
	//printf("prec %d\n", all.flags->space);
	va_end(ap);
	return (words);
}
