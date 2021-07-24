/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_unsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:57:50 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 12:57:57 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_put_part_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.precision >= 0)
		char_count += f_for_width(flags.precision - 1,
		ft_strlen(unsi_int) - 1, 1);
	char_count += print_str(unsi_int, ft_strlen(unsi_int));
	return (char_count);
}

static int	ft_put_part_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(unsi_int))
		flags.precision = ft_strlen(unsi_int);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		char_count += f_for_width(flags.width, 0, 0);
	}
	else
		char_count += f_for_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_uint(unsi_int, flags);
	return (char_count);
}

int			f_for_uint(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		char_count;

	char_count = 0;
	unsi = (unsigned int)(4294967295 + 1
				+ unsi);
	if (flags.precision == 0 && unsi == 0)
	{
		char_count += f_for_width(flags.width, 0, 0);
		return (char_count);
	}
	unsi_int = ft_u_itoa(unsi);
	char_count += ft_put_part_uint(unsi_int, flags);
	free(unsi_int);
	return (char_count);
}
