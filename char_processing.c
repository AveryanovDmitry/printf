/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:10:44 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/17 23:10:58 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_processing(char c, t_flags flags)
{
	int i;

	i = 0;
	if (flags.width > 0)
	{
		if (flags.minus == 0)
		{
			i += f_for_width(flags.width, 1, flags.zero);
			i += write(1, &c, 1);
		}
		else
		{
			i += write(1, &c, 1);
			i += f_for_width(flags.width, 1, flags.zero);
		}
	}
	else
	{
		i += write(1, &c, 1);
	}
	return (i);
}
