/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:55:36 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/18 17:54:04 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_printf_null(t_print *all, int size, char *str)
{
	if (all->flags->zero == 0 && all->prec == -1)
	{
		size = ft_output(all, "", 0);
		return (size);
	}
	else if (all->flags->zero == 0 || all->prec > 0)
	{
		size = (all->prec > 0) ? all->prec : 6;
		str = ft_strsub("(null)", 0, size);
		size = ft_output(all, str, ft_strlen(str));
		free(str);
		return (size);
	}
	else if (all->width > 0 && all->prec != -1)
	{
		size = ft_output(all, "(null)", 6);
		return (size);
	}
	else
	{
		str = "";
		size = ft_output(all, str, ft_strlen(str));
	}
	return (size);
}

static int	ft_check_color_two(char *str)
{
	if (ft_strcmp(str, MAGENTA) == 0)
	{
		write(1, MAGENTA, 6);
		return (1);
	}
	else if (ft_strcmp(str, CYAN) == 0)
	{
		write(1, CYAN, 6);
		return (1);
	}
	else if (ft_strcmp(str, RESET) == 0)
	{
		write(1, RESET, 6);
		return (1);
	}
	else
		return (0);
}

static int	ft_check_color_one(char *str)
{
	if (ft_strcmp(str, RED) == 0)
	{
		write(1, RED, 6);
		return (1);
	}
	else if (ft_strcmp(str, GREEN) == 0)
	{
		write(1, GREEN, 6);
		return (1);
	}
	else if (ft_strcmp(str, YELLOW) == 0)
	{
		write(1, YELLOW, 6);
		return (1);
	}
	else if (ft_strcmp(str, BLUE) == 0)
	{
		write(1, BLUE, 6);
		return (1);
	}
	else
		return (ft_check_color_two(str));
}

int			ft_printf_string(t_print *all, va_list ap)
{
	int		size;
	char	*str;

	size = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		return (ft_printf_null(all, size, str));
	if (ft_check_color_one(str) == 1)
		return (0);
	if (all->prec == -1)
		str = "";
	if (all->prec > 0 && all->prec < (int)ft_strlen(str))
	{
		str = ft_strsub(str, 0, all->prec);
		size = ft_output(all, str, ft_strlen(str));
		free(str);
		return (size);
	}
	size = ft_output(all, str, ft_strlen(str));
	return (size);
}
