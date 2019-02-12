/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 12:59:42 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 21:05:17 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//в size приходит длина строки без точности

#include "../includes/printf.h"

static void	ft_put_symbol(int *size, char c)
{
	(*size)++;
	ft_putchar(c);
}

static void	ft_check_sharp(t_print *all)
{
	if (all->type == 'x' || all->type == 'p')
		ft_putstr("0x");
	else if (all->type == 'X')
		ft_putstr("0X");
	else if (all->type == 'o' || all->type == 'O')
		ft_putstr("0");
}

static void	ft_check_flags(t_print *all)
{
	if (all->flags->plus == 1)
		ft_putchar('+');
	else if (all->flags->plus == 2)
		ft_putchar('-');
	else if (all->flags->space == 1)
		ft_putchar(' ');
}

static char	*ft_precision(t_print *all, char *str)
{
	int		size;
	int		i;
	char	*tmp_str;
	char	*new_str;

	size = all->prec;
	if (all->type == 'f')
	{
		size = size + ft_strchr(str, '.') - str + 1;
		tmp_str = ft_strnew(size);
		new_str = ft_memset(tmp_str, '0', size);
		i = -1;
		while (++i < size && str[i] != '\0')
			new_str[i] = str[i];
	}
	else
	{
		i = ft_strlen(str);
		tmp_str = ft_strnew(size);
		new_str = ft_memset(tmp_str, '0', size);
		while (size >= 0 && i >= 0)
			new_str[size--] = str[i--];
	}
	free(tmp_str);
	return (new_str);
}

int			ft_output(t_print *all, char *str, int size)
{
	if (all->prec > 0 && (all->type == 'f' || (all->prec > (int)ft_strlen(str)
				&& all->type != '%' && all->type != 's')))
	{
		size = size + all->prec - (int)ft_strlen(str);
		str = ft_precision(all, str);
	}
	while (size < all->width && !all->flags->minus && !all->flags->zero)
		ft_put_symbol(&size, ' ');
	if (all->flags->sharp == 1)
		ft_check_sharp(all);
	if (all->type == 'd')
		ft_check_flags(all);
	while (size < all->width && !all->flags->minus && all->flags->zero)
		ft_put_symbol(&size, '0');
	ft_putstr(str);
	//write(1, str, ft_strlen(str));
	while (size < all->width && all->flags->minus)
		ft_put_symbol(&size, ' ');
	return (size);
}
