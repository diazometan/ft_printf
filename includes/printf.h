/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:55:58 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/07 18:47:48 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_print
{
	char		*flags;
	int			width;
	int			prec;
	char		size;
	char		type;
}				t_print;

#endif