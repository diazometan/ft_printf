/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:07:30 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/19 17:43:45 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int				ft_special_symbol(t_print *all)
{
	int					size;

	size = 0;
	if (all->floa->spec == 1)
	{
		if (all->flags->plus != 0 || all->flags->space != 0)
			size = ft_output(all, "inf", 4);
		else
			size = ft_output(all, "inf", 3);
	}
	else
		size = ft_output(all, "nan", 3);
	return (size);
}

static char				*ft_round_float(char *str, int last)
{
	int					i;

	i = last;
	if (str[last] < '5')
		str[last] = '\0';
	else
	{
		str[last] = '\0';
		last--;
		while (str[last] == '9')
		{
			str[last] = '0';
			last--;
			if (str[last] == '.')
				str[last - 1]++;
		}
		if (str[last != '.'])
			str[last]++;
	}
	return (str);
}

static char				*ft_itoa_float(t_print *all, int i, int j)
{
	char				*str;
	unsigned long long	tmp;

	if (!(str = (char *)malloc(sizeof(char) * (all->floa->len_pre + 1 +
						all->floa->len_after + 1 + 1))))
		exit(1);
	tmp = all->floa->flo;
	while (i--)
	{
		str[i] = tmp % 10 + '0';
		tmp /= 10;
	}
	str[all->floa->len_pre] = '.';
	all->floa->doub = all->floa->doub - all->floa->flo;
	while (i <= all->floa->len_after)
	{
		all->floa->doub = all->floa->doub * 10.0;
		all->floa->flo = (unsigned long long)all->floa->doub;
		str[++(all->floa->len_pre)] = '0' + all->floa->flo;
		all->floa->doub = all->floa->doub - all->floa->flo;
		i++;
	}
	str[j + 1 + all->floa->len_after + 1] = '\0';
	str = ft_round_float(str, ft_strlen(str) - 1);
	return (str);
}

static void				ft_specifier(t_print *all, va_list ap)
{
	if (all->size == 0)
		all->floa->doub = (double)va_arg(ap, double);
	else
		all->floa->doub = (long double)va_arg(ap, long double);
	if (all->floa->doub == INF || all->floa->doub == -INF)
	{
		if (all->floa->doub == -INF)
			all->flags->plus = 2;
		all->floa->spec = 1;
		return ;
	}
	if ((double)all->floa->doub != (double)all->floa->doub)
	{
		all->floa->spec = 2;
		return ;
	}
	if (all->floa->doub < 0)
	{
		all->flags->plus = 2;
		all->floa->doub = (-1) * all->floa->doub;
		all->floa->flo = (unsigned long long)all->floa->doub;
	}
	else
		all->floa->flo = (unsigned long long)all->floa->doub;
}

int						ft_printf_float(t_print *all, va_list ap)
{
	int					j;
	int					size;

	size = 0;
	ft_specifier(all, ap);
	if (all->floa->spec != 0)
		size = ft_special_symbol(all);
	else
	{
		all->floa->len_pre = ft_str_int(all->floa->flo);
		j = all->floa->len_pre;
		all->floa->len_after = (all->prec == 0) ? 6 : all->prec;
		all->floa->str = ft_itoa_float(all, all->floa->len_pre, j);
		if (all->flags->plus != 0 || all->flags->space != 0)
			size = ft_output(all, all->floa->str,
							ft_strlen(all->floa->str) + 1);
		else
			size = ft_output(all, all->floa->str, ft_strlen(all->floa->str));
		free(all->floa->str);
	}
	return (size);
}
