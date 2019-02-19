/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:08:45 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/14 15:19:31 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char					*ft_itoa_pointer(unsigned long long nbr, int base)
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
		str[i] = (tmp % base < 10) ? tmp % base + '0' : tmp % base + 'a' - 10;
		tmp /= base;
	}
	return (str);
}

int							ft_printf_pointer(t_print *all, va_list ap)
{
	char					*p;
	unsigned long long		point;
	int						size;

	point = (unsigned long long int)va_arg(ap, void *);
	if (point == 0 && all->prec == -1)
	{
		size = ft_output(all, "0x", 2);
		return (size);
	}
	p = ft_itoa_pointer(point, 16);
	all->flags->sharp = 1;
	size = ft_output(all, p, ft_strlen(p) + 2);
	free(p);
	return (size);
}
