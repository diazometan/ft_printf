/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:57:14 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/15 16:13:27 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char					*ft_itoa_unsigned(unsigned long long nbr, int base)
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

int							ft_printf_unsigned(t_print *all, va_list ap)
{
	int						size;
	char					*u;
	unsigned long long		unsign;

	size = 0;
	unsign = ft_specifier(all, ap);
	u = ft_itoa_unsigned(unsign, 10);
	if (all->prec != 0)
		all->flags->zero = 0;
	if (unsign == 0 && all->prec == -1)
		size = ft_output(all, "", 0);
	else
	{
		size = ft_output(all, u, ft_strlen(u));
		free(u);
	}
	return (size);
}
