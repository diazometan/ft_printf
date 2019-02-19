/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:57:45 by jlesch            #+#    #+#             */
/*   Updated: 2019/02/19 18:32:26 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		flags_filler(char *str, t_print *all)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (all->flags->space != 1)
			all->flags->space = str[i] == ' ' ? 1 : 0;
		if (all->flags->minus != 1)
			all->flags->minus = str[i] == '-' ? 1 : 0;
		if (all->flags->plus != 1)
			all->flags->plus = str[i] == '+' ? 1 : 0;
		if (all->flags->sharp != 1)
			all->flags->sharp = str[i] == '#' ? 1 : 0;
		if ((i == 0 && str[i] == '0') ||
			(i != 0 && str[i] == '0' && str[i - 1] != '.' &&
			(str[i - 1] < '0' || str[i - 1] > '9')))
			all->flags->zero = 1;
		if (all->flags->zero != 1)
			all->flags->zero = 0;
		i++;
	}
	all->flags->noll = -1;
}

static int	ft_minus_prec(t_print *all, int prec, int flaq, char *str)
{
	int i;

	i = 0;
	if ((all->type == 'x' || all->type == 'X' || all->type == 'o' ||
	all->type == 'O' || all->type == 'u' || all->type == 'U' ||
	all->type == 'p' || all->type == 's' || all->type == 'd'
	|| all->type == 'D' || all->type == 'i' || all->type == 'f' ||
		all->type == 'F')
	&& prec == 0 && (flaq || ft_strchr(str, '.')))
		return (1);
	while (str[i])
		i++;
	i--;
	while (i >= 0 && str[i] != '.')
		i--;
	if (i >= 0 && str[i] == '.' && (str[i + 1] < '0' || str[i + 1] > '9'))
		return (1);
	return (0);
}

static void	ft_width_check(t_print *all, char *s, int j)
{
	if (!(all->filler->width) && j == 0 && ft_isdigit(s[j]))
		all->filler->width = ft_atoi(s + j);
	all->width = all->filler->width;
	if (ft_minus_prec(all, all->filler->prec, all->filler->flaq, s))
		all->filler->prec = -1;
	all->prec = all->filler->prec;
}

void		struct_filler(char *s, t_print *all, int j)
{
	int	k;

	k = j;
	all->type = s[j];
	while (k > 0 && s[k] != '.')
		k--;
	if (s[k] == '.' && ft_isdigit(s[k + 1]))
	{
		all->filler->prec = ft_atoi(s + k + 1);
		all->filler->flaq = 1;
	}
	while (j > 0)
	{
		while (j > 0 && !(ft_isdigit(s[j])))
			j--;
		while (j > 0 && (ft_isdigit(s[j])))
			j--;
		if (!(all->filler->width) && j == 0 && ft_isdigit(s[j]))
			all->filler->width = ft_atoi(s + j);
		else if (!(all->filler->width) && ft_isdigit(s[j + 1]) && s[j] != '.')
			all->filler->width = ft_atoi(s + j + 1);
		j--;
	}
	ft_width_check(all, s, j);
}

void		size_filler(char *str, t_print *all)
{
	int		i;

	i = 0;
	all->size = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			all->size = all->size < 1 ? 1 : all->size;
		if (str[i] == 'h' && str[i + 1] != 'h' && (i == 0 || str[i - 1] != 'h'))
			all->size = all->size < 2 ? 2 : all->size;
		if (str[i] == 'l' && str[i + 1] != 'l' && (i == 0 || str[i - 1] != 'l'))
			all->size = all->size < 3 ? 3 : all->size;
		if ((str[i] == 'l' && str[i + 1] == 'l')
			|| str[i] == 'j' || str[i] == 'z')
			all->size = all->size < 4 ? 4 : all->size;
		if ((all->type == 'f' || all->type == 'F') &&
		(str[i] == 'L' && str[i + 1] != 'L' && (i == 0 || str[i - 1] != 'L')))
			all->size = all->size < 5 ? 5 : all->size;
		i++;
	}
	if ((all->type == 'f' || all->type == 'F') && all->size != 5)
		all->size = 0;
}
