/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:16:44 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 15:20:16 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_printf_char(t_print *all, va_list ap)
{
	int	size;
	int	c;

	c = (unsigned char)va_arg(ap, int);
	size = 1;
	while (size < all->width && !all->flags->minus)
	{
		if (all->flags->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		size++;
	}
	ft_putchar(c);
	while (size < all->width && all->flags->minus)
	{
		ft_putchar(' ');
		size++;
	}
	return (size);
}
