/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:25:55 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 13:54:52 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char *ft_itoa_hex(unsigned long long nbr, int base, char c)
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
		str[i] = (tmp % base < 10) ? tmp % base + '0' : tmp % base + c - 10;
		tmp /= base;
	}
	return (str);
}

static char *ft_specifier(t_print *all, va_list ap)
{
	unsigned long long hex;
	char *h;

	hex = 0;
	if (all->size == 0)
		hex = (int)va_arg(ap, unsigned int);
	if (all->size == 1)
		hex = (unsigned char)va_arg(ap, unsigned int);
	if (all->size == 2)
		hex = (unsigned short int)va_arg(ap, unsigned int);
	if (all->size == 3)
		hex = (unsigned long int)va_arg(ap, unsigned long int);
	if (all->size == 4)
		hex = (unsigned long long)va_arg(ap, unsigned long long);
	if (all->type == 'X')
		h = ft_itoa_hex(hex, 16, 'A');
	else
		h = ft_itoa_hex(hex, 16, 'a');
	return (h);
}

int ft_printf_hex(t_print *all, va_list ap)
{
	int size;
	char *h;

	size = 0;
	h = ft_specifier(all, ap);
	if (all->flags->sharp == 1)
		size = ft_output(all, h, ft_strlen(h) + 2);
	else
		size = ft_output(all, h, ft_strlen(h));
	return (size);
}
