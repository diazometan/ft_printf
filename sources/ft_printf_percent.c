/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:27:50 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 15:25:08 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_printf_percent(t_print *all)
{
	int	size;

	size = 1;
	while (size < all->width && !all->flags->minus)
	{
		if (all->flags->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		size++;
	}
	ft_putchar('%');
	while (size < all->width && all->flags->minus)
	{
		ft_putchar(' ');
		size++;
	}
	return (size);
}
