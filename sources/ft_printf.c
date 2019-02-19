/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:34:12 by jlesch            #+#    #+#             */
/*   Updated: 2019/02/19 17:46:16 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		init_struct(t_print *all)
{
	all->prec = 0;
	all->size = 0;
	all->type = 0;
	all->width = 0;
	all->flags->minus = 0;
	all->flags->noll = 0;
	all->flags->plus = 0;
	all->flags->sharp = 0;
	all->flags->space = 0;
	all->flags->zero = 0;
	all->filler->flaq = 0;
	all->filler->prec = 0;
	all->filler->width = 0;
	all->floa->spec = 0;
}

int			ft_is_type(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == 'f' || c == 'F' || c == 'c' || c == 's' || c == 'D' || c == 'O' ||
		c == 'p' || c == 'n' || c == 'U' || c == '%' || c == 'S' || c == 'b' ||
		c == 'C')
		return (1);
	return (0);
}

int			ft_is_upp(char c)
{
	if (c >= 'A' && c <= 'Z' && c != 'F' && c != 'U' && c != 'D' &&
		c != 'X' && c != 'O' && c != 'S' && c != 'L' && c != 'C')
		return (1);
	if ((c >= 33 && c <= 41 && c != '%' && c != '#') || (c >= 123 && c <= 126))
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
	all.flags = (t_flags *)malloc(sizeof(t_flags));
	all.filler = (t_filler *)malloc(sizeof(t_filler));
	all.floa = (t_float *)malloc(sizeof(t_float));
	va_start(ap, format);
	while (*format)
	{
		sdvig = struct_creator(format, &words, &all, ap);
		format += sdvig;
	}
	va_end(ap);
	free(all.flags);
	free(all.filler);
	free(all.floa);
	return (words);
}
