/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:26:08 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/15 15:25:32 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char					*ft_itoa_octal(unsigned long long nbr, int base)
{
	char					*str;
	unsigned long long		tmp;
	int						i;

	tmp = nbr;
	i = 1;
	while ((tmp = tmp / base) >= 1)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	tmp = nbr;
	while (i--)
	{
		str[i] = tmp % base + '0';
		tmp /= base;
	}
	return (str);
}

static unsigned long long	ft_specifier(t_print *all, va_list ap)
{
	if (all->size == 0)
		return (va_arg(ap, unsigned int));
	if (all->size == 1)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (all->size == 2)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (all->size == 3)
		return ((unsigned long int)va_arg(ap, unsigned long int));
	return (va_arg(ap, unsigned long long));
}

static int					ft_printf_null(t_print *all)
{
	int						size;

	size = 0;
	if (all->flags->sharp == 0 && all->prec == -1)
		size = ft_output(all, "", 0);
	else
	{
		all->flags->sharp = 0;
		size = ft_output(all, "0", 1);
	}
	return (size);
}

int							ft_printf_octal(t_print *all, va_list ap)
{
	int						size;
	char					*o;
	unsigned long long		octal;

	size = 0;
	octal = ft_specifier(all, ap);
	if (all->prec != 0)
		all->flags->zero = 0;
	if (octal == 0)
		size = ft_printf_null(all);
	else
	{
		if (all->flags->sharp && all->prec > 1)
			all->prec--;
		o = ft_itoa_octal(octal, 8);
		if (all->flags->sharp == 1)
			size = ft_output(all, o, ft_strlen(o) + 1);
		else
			size = ft_output(all, o, ft_strlen(o));
		free(o);
	}
	return (size);
}
