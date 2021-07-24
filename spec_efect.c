/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_efect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:07:58 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/17 23:08:04 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		f_for_percent(t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += print_str("%", 1);
	char_count += f_for_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += print_str("%", 1);
	return (char_count);
}

int				spec_efect(t_flags flags, char c, va_list vl)
{
	int char_count;

	char_count = 0;
	if (c == 'c')
		char_count += char_processing(va_arg(vl, int), flags);
	else if (c == 's')
		char_count += str_processing(flags, va_arg(vl, char *));
	else if (c == 'd' || c == 'i')
		char_count += int_processing(va_arg(vl, int), flags);
	else if (c == 'p')
		char_count += f_for_pointer(va_arg(vl, unsigned long long), flags);
	else if (c == 'u')
		char_count += f_for_uint((unsigned int)va_arg(vl, unsigned int), flags);
	else if (c == 'x')
		char_count += f_for_hexa(va_arg(vl, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += f_for_hexa(va_arg(vl, unsigned int), 0, flags);
	else if (c == '%')
		char_count += f_for_percent(flags);
	return (char_count);
}
