/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:57:14 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 13:54:54 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char *ft_itoa_unsigned(unsigned long long int nbr, int base)
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
	unsigned long long unsign;
	char *u;

	unsign = 0;
	if (all->size == 0)
		unsign = (int)va_arg(ap, unsigned int);
	if (all->size == 1)
		unsign = (unsigned char)va_arg(ap, unsigned int);
	if (all->size == 2)
		unsign = (unsigned short int)va_arg(ap, unsigned int);
	if (all->size == 3)
		unsign = (unsigned long int)va_arg(ap, unsigned long int);
	if (all->size == 4)
		unsign = (unsigned long long)va_arg(ap, unsigned long long);
	u = ft_itoa_unsigned(unsign, 10);
	return (u);
}

int ft_printf_unsigned(t_print *all, va_list ap)
{
	int size;
	char *u;

	size = 0;
	u = ft_specifier(all ,ap);
	if (all->prec < 0)
		all->flags->zero = 0;
	if (all->flags->plus != 0)
		size = ft_output(all, u, ft_strlen(u));
	else
		size = ft_output(all, u, ft_strlen(u));
	free(u);
	return (size);
}
