/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:24:30 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 13:24:34 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_for_width(int width, int precision, int zero)
{
	int char_count;

	char_count = 0;
	while (width - precision > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}
