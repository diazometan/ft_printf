/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:37:55 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 14:12:55 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char *ft_specifier(t_print *all, va_list ap)
{
	long long int decimal;
	char *d;

	decimal = 0;
	if (all->size == 0)
		decimal = (int)va_arg(ap, int);
	if (all->size == 1)
		decimal = (signed char)va_arg(ap, int);
	if (all->size == 2)
		decimal = (short int)va_arg(ap, int);
	if (all->size == 3)
		decimal = (long int)va_arg(ap, long int);
	if (all->size == 4)
		decimal = (long long int)va_arg(ap, long long int);
	if (decimal < 0)
		all->flags->plus = 2;
	d = ft_itoa_base(decimal, 10);
	return (d);
}

int ft_printf_decimal(t_print *all, va_list ap)
{
	int size;
	char *d;

	size = 0;
	d = ft_specifier(all, ap);
	if (all->prec < 0)
		all->flags->zero = 0;
	if (all->flags->plus != 0)
		size = ft_output(all, d, ft_strlen(d) + 1);
	else
		size = ft_output(all, d, ft_strlen(d));
	free(d);
	return (size);
}
