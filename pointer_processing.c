/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:48:00 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 12:48:08 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_in_put_part_pointer(char *pointer, t_flags flags)
{
	int char_count;

	char_count = 0;
	char_count += print_str("0x", 2);
	if (flags.precision >= 0)
	{
		char_count += f_for_width(flags.precision, ft_strlen(pointer), 1);
		char_count += print_str(pointer, flags.precision);
	}
	else
		char_count += print_str(pointer, ft_strlen(pointer));
	return (char_count);
}

int			f_for_pointer(unsigned long long ull, t_flags flags)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags.precision == 0)
	{
		char_count += print_str("0x", 2);
		return (char_count += f_for_width(flags.width, 0, 1));
	}
	pointer = f_for_ull(ull, 16);
	pointer = str_tolower(pointer);
	if ((size_t)flags.precision < ft_strlen(pointer))
		flags.precision = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_in_put_part_pointer(pointer, flags);
	char_count += f_for_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}
