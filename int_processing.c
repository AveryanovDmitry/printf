/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:17:38 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/17 23:17:41 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		input_int(char *str_int, int minus_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (minus_i < 0 && flags.precision >= 0)
		ft_putchar('-');
	if (flags.precision >= 0)
		char_count += f_for_width(flags.precision - 1,
			ft_strlen(str_int) - 1, 1);
	char_count += print_str(str_int, ft_strlen(str_int));
	return (char_count);
}

static	int		put_int(char *str_int, int minus_i, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += input_int(str_int, minus_i, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(str_int))
		flags.precision = ft_strlen(str_int);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		char_count += f_for_width(flags.width, 0, 0);
	}
	else
		char_count += f_for_width(flags.width, ft_strlen(str_int), flags.zero);
	if (flags.minus == 0)
		char_count += input_int(str_int, minus_i, flags);
	return (char_count);
}

static	int		check_min(char **str_int, int i, t_flags flags)
{
	int count;

	count = 0;
	if (i == -2147483648 && flags.zero == 1)
		count += put_int(*str_int + 1, i, flags);
	else
		count += put_int(*str_int, i, flags);
	return (count);
}

int				int_processing(int i, t_flags flags)
{
	char	*str_int;
	int		minus_i;
	int		char_count;

	minus_i = i;
	char_count = 0;
	if (flags.precision == 0 && i == 0)
	{
		char_count += f_for_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.precision >= 0 || flags.zero == 1))
	{
		i *= -1;
		if (flags.zero == 1 && flags.precision < 0)
			print_str("-", 1);
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	str_int = ft_itoa(i);
	char_count += check_min(&str_int, minus_i, flags);
	free(str_int);
	return (char_count);
}
