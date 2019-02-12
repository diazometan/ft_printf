/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:25:55 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 20:14:19 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char				*ft_itoa_hex(unsigned long long nbr, int base, char c)
{
	char				*str;
	unsigned long long	tmp;
	int					i;

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

int						ft_printf_hex(t_print *all, va_list ap)
{
	int					size;
	char				*h;
	unsigned long long	hex;

	size = 0;
	hex = ft_specifier(all, ap);
	if (hex == 0)
	{
		all->flags->sharp = 0;
		all->type = 'x';
		if (all->prec == 0)
			size = ft_output(all, "0", 1);
		else
			size = ft_output(all, "", 0);
	}
	else
	{
		if (all->type == 'X')
			h = ft_itoa_hex(hex, 16, 'A');
		else
			h = ft_itoa_hex(hex, 16, 'a');
		if (all->flags->sharp == 1)
			size = ft_output(all, h, ft_strlen(h) + 2);
		else
			size = ft_output(all, h, ft_strlen(h));
		free(h);
	}
	return (size);
}
