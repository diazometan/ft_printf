/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:17:22 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/19 17:45:35 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		ft_return(int *words, int *i, int *j)
{
	*words += *i;
	return (*i + *j);
}

static void		struct_checker(t_print *all)
{
	if (all->type == 'c' || all->type == 'p' || all->type == 'n')
		all->size = 0;
	if (all->flags->space == 1 && all->flags->plus == 1)
		all->flags->space = 0;
	if (all->prec >= all->width)
		all->flags->zero = 0;
	if (all->type == 'D')
	{
		all->size = 3;
		all->type = 'd';
	}
	if (all->type == 'O')
	{
		all->size = 3;
		all->type = 'o';
	}
	if (all->type == 'i')
		all->type = 'd';
	if (all->type == 'F')
		all->type = 'f';
	if (all->type == 'U')
	{
		all->size = 3;
		all->type = 'u';
	}
}

static void		call_struct_function(t_print *all, char *str, int j)
{
	init_struct(all);
	flags_filler(str, all);
	struct_filler(str, all, j - 1);
	size_filler(str, all);
	ft_strdel(&str);
	struct_checker(all);
	if (all->type == 'C')
		all->type = 'c';
}

static int		ft_for_upper(char *s, t_print *all, int *j, int *words)
{
	char		*str;
	int			i;
	int			size;

	i = 0;
	init_struct(all);
	while (s[i] && s[i] != '%')
		i++;
	if (!(str = ft_strsub(s, i, *j + i)))
		exit(1);
	flags_filler(str, all);
	struct_filler(str, all, *j - 1);
	ft_strdel(&str);
	size = i;
	while (s[i] && s[i] != '%')
		i++;
	if (!(str = ft_strsub(s, *j + size, 1)))
		exit(1);
	i = size + *j;
	size += ft_output(all, str, 1);
	ft_strdel(&str);
	*words += size;
	return (i + 1);
}

int				struct_creator(char *s, int *words, t_print *all, va_list ap)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	j = 1;
	while (s[i] != '%' && s[i])
		write(1, &s[i++], 1);
	if (s[i] == '\0')
	{
		*words += i;
		return (i);
	}
	while (s[i + j] && !ft_is_type(s[i + j]) && !(ft_is_upp(s[i + j])))
		j++;
	if (s[i + j] == '\0')
		return (ft_return(words, &i, &j));
	if (ft_is_upp(s[i + j]))
		return (ft_for_upper(s, all, &j, words));
	if (!(str = ft_strsub(s, i + 1, j)))
		exit(1);
	call_struct_function(all, str, j);
	*words += i;
	*words += ft_choose_function(all, ap);
	return (i + j + 1);
}
