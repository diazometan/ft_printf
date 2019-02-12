/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:26:08 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 13:54:53 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char *ft_itoa_octal(unsigned long long nbr, int base)
{
	char *str;
	unsigned long long tmp;
	int i;

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

static char *ft_specifier(t_print *all, va_list ap)
{
	unsigned long long octal;
	char *o;

	octal = 0;
	if (all->size == 0)
		octal = (int)va_arg(ap, unsigned int);
	if (all->size == 1)
		octal = (unsigned char)va_arg(ap, unsigned int);
	if (all->size == 2)
		octal = (unsigned short int)va_arg(ap, unsigned int);
	if (all->size == 3)
		octal = (unsigned long int)va_arg(ap, unsigned long int);
	if (all->size == 4)
		octal = (unsigned long long)va_arg(ap, unsigned long long);
	o = ft_itoa_octal(octal, 8);
	return (o);
}

int ft_printf_octal(t_print *all, va_list ap)
{
	int size;
	char *o;

	size = 0;
	o = ft_specifier(all, ap);
	if (all->flags->sharp == 1)
		size = ft_output(all, o, ft_strlen(o) + 2);
	else
		size = ft_output(all, o, ft_strlen(o));
	return (size);
}
