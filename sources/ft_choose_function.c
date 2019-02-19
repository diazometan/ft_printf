/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:01:46 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/18 20:59:54 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_choose_function(t_print *all, va_list ap)
{
	if (all->type == 'f' || all->type == 'F')
		return (ft_printf_float(all, ap));
	if (all->type == 's' || all->type == 'S')
		return (ft_printf_string(all, ap));
	if (all->type == 'c')
		return (ft_printf_char(all, ap));
	if (all->type == 'p')
		return (ft_printf_pointer(all, ap));
	if (all->type == 'x' || all->type == 'X')
		return (ft_printf_hex(all, ap));
	if (all->type == 'o')
		return (ft_printf_octal(all, ap));
	if (all->type == 'd')
		return (ft_printf_decimal(all, ap));
	if (all->type == 'u')
		return (ft_printf_unsigned(all, ap));
	if (all->type == '%')
		return (ft_printf_percent(all));
	if (all->type == 'b')
		return (ft_printf_bits(all->width, ap));
	return (0);
}
