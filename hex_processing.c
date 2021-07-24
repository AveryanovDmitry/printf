/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:02:55 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 13:02:57 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

static int		input_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.precision >= 0)
		char_count += f_for_width(flags.precision - 1, ft_strlen(hexa) - 1, 1);
	char_count += print_str(hexa, ft_strlen(hexa));
	return (char_count);
}

static int		put_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += input_hexa(hexa, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(hexa))
		flags.precision = ft_strlen(hexa);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		char_count += f_for_width(flags.width, 0, 0);
	}
	else
		char_count += f_for_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += input_hexa(hexa, flags);
	return (char_count);
}

int				f_for_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.precision == 0 && ui == 0)
	{
		char_count += f_for_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = f_for_ull((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = str_tolower(hexa);
	char_count += put_hexa(hexa, flags);
	free(hexa);
	return (char_count);
}
