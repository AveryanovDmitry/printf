/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ull_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:31:44 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 13:31:48 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*lalala(unsigned long long save, int hex,
char *r, int count)
{
	while (save != 0)
	{
		if ((save % hex) < 10)
			r[count - 1] = (save % hex) + 48;
		else
			r[count - 1] = (save % hex) + 55;
		save /= hex;
		count--;
	}
	return (r);
}

char		*f_for_ull(unsigned long long ull, int hex)
{
	char				*r;
	unsigned long long	save;
	int					count;

	r = 0;
	count = 0;
	save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= hex;
		count++;
	}
	if (!(r = malloc(sizeof(char) * (count + 1))))
		return (0);
	r[count] = '\0';
	r = lalala(save, hex, r, count);
	return (r);
}
