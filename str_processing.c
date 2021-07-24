/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:14:10 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 12:14:14 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_str(char *str, int precision)
{
	int i;

	i = 0;
	while (str[i] && i < precision)
		ft_putchar(str[i++]);
	return (i);
}

static int		ft_put_part_int(char *str, t_flags flags)
{
	int i;

	i = 0;
	if (flags.precision >= 0)
	{
		i += f_for_width(flags.precision, ft_strlen(str), 0);
		i += print_str(str, flags.precision);
	}
	else
	{
		i += print_str(str, ft_strlen(str));
	}
	return (i);
}

int				str_processing(t_flags flags, char *str)
{
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.minus == 1)
		i += ft_put_part_int(str, flags);
	if (flags.precision >= 0)
		i += f_for_width(flags.width, flags.precision, 0);
	else
		i += f_for_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		i += ft_put_part_int(str, flags);
	return (i);
}
