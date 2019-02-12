/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:55:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 13:56:02 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int ft_printf_string(t_print *all, va_list ap)
{
    int size;
	char *str;

	size = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (all->prec != 0 && all->prec < (int)ft_strlen(str))
	{
		str = ft_strsub(str, 0, all->prec);
		size = ft_output(all, str, ft_strlen(str));
		free(str);
		return (size);
	}
	return (ft_output(all, str, ft_strlen(str)));
}
