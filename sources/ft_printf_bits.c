/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:08:34 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/18 19:46:53 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void			ft_bits(char a)
{
	int				i;
	char			b;

	i = 0;
	while (i < 8)
	{
		b = '0' + ((a >> (7 - i)) & 1);
		write(1, &b, 1);
		i++;
	}
}

int					ft_printf_bits(int count, va_list ap)
{
	long double		*a;
	void			*str;
	int				size;

	size = 8 * count + 3 * (count - 1);
	str = va_arg(ap, void *);
	while (count > 0)
	{
		count--;
		ft_bits(((char *)str)[count]);
		if (count != 0)
			write(1, "   ", 3);
	}
	return (size);
}
