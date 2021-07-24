/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_only_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:22:16 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 13:22:19 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags				flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

int					flag_precision(const char *format, int start,
			t_flags *flags, va_list vl)
{
	int i;

	i = start;
	i++;
	if (format[i] == '*')
	{
		flags->precision = va_arg(vl, int);
		i++;
	}
	else
	{
		flags->precision = 0;
		while (ft_isdigit(format[i]))
			flags->precision = (flags->precision * 10) + (format[i++] - '0');
	}
	return (i);
}

t_flags				flag_width(va_list vl, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(vl, int);
	if (flags.width < 0)
	{
		flags = flag_minus(flags);
		flags.width *= -1;
	}
	return (flags);
}

t_flags				flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}
