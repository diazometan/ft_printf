/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:27:29 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/12 18:53:18 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char				*ft_itoa_base(long long int nbr, int base)
{
	char			*str;
	long long int	tmp;
	int				i;
	int				sign;

	if (nbr < 0)
		if (nbr == LONG_MIN)
			return (ft_strdup("9223372036854775808"));
	tmp = (nbr < 0) ? -nbr : nbr;
	sign = (nbr < 0 && base == 10) ? -1 : 0;
	i = 1;
	while ((tmp = tmp / base) >= 1)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	tmp = (nbr < 0) ? -nbr : nbr;
	while (i--)
	{
		str[i] = (tmp % base < 10) ? tmp % base + '0' : tmp % base + 'A' - 10;
		tmp /= base;
	}
	return (str);
}
