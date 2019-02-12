/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:57:45 by jlesch            #+#    #+#             */
/*   Updated: 2019/02/12 14:12:33 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		flags_filler(char *str, t_print *all)
{
	int		i;

	i = 0;
	while (str[i])
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
}

void		struct_filler(char *str, t_print *all, int j)
{
	int		i;
	int		width;
	int		prec;

	prec = 0;
	width = 0;
	all->type = str[j];
	if (all->type == 'i')
		all->type = 'd';
	while (str[j])
	{
		i = 0;
		while (ft_isdigit(str[j - i]))
			i++;
		if (!(width) && i && str[j - i] != '.')
			width = ft_atoi(str + j - i + 1);
		if (!(prec) && i && str[j - i] == '.')
			prec = ft_atoi(str + j - i + 1);
		j--;
	}
	all->width = width;
	all->prec = prec;
	if (all->prec == 0)
		all->prec = -1;
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
		((str[i] == 'l' && str[i + 1] != 'l' &&
		(i == 0 || str[i - 1] != 'l')) ||
		(str[i] == 'L' && str[i + 1] != 'L' && (i == 0 || str[i - 1] != 'L'))))
			all->size = all->size < 5 ? 5 : all->size;
		i++;
	}
	if ((all->type == 'f' || all->type == 'F') && all->size != 5)
		all->size = 0;
}

void		struct_checker(t_print *all)
{
	if (all->type == 'c' || all->type == 'p' || all->type == 'n')
		all->size = 0;
	if (all->flags->space == 1 && all->flags->plus == 1)
		all->flags->space = 0;
}

int			struct_creator(char *s, int *words, t_print *all, va_list ap)
{
	int		i;
	size_t	j;
	char	*str;

	i = 0;
	j = 1;
	while (s[i] != '%' && s[i])
		write(1, &s[i++], 1);
	if (s[i] == '\0')
	{
		*words += i;
		return (i);
	}
	while (s[i + j] && !ft_is_type(s[i + j]))
		j++;
	str = ft_strsub(s, i + 1, j);
	all->flags = (t_flags *)malloc(sizeof(t_flags));
	flags_filler(str, all);
	struct_filler(str, all, j - 1);
	size_filler(str, all);
	ft_strdel(&str);
	struct_checker(all);
	*words += i;
	*words += ft_choose_function(all, ap);
/*
	printf("\nspace %d\n", all->flags->space);
	printf("minus %d\n", all->flags->minus);
	printf("plus %d\n", all->flags->plus);
	printf("zero %d\n", all->flags->zero);
	printf("sharp %d\n", all->flags->sharp);
	printf("width %d\n", all->width);
	printf("prec %d\n", all->prec);
	printf("size %d\n", all->size);
	printf("type %c\n", all->type);*/
	return (i + j + 1);
}
