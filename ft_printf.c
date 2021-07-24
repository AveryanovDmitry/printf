/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 18:35:07 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/17 19:09:12 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int				check_specificator(char x)
{
	int		i;
	char	*y;

	i = 0;
	y = "cspdiuxX%";
	while (y[i] != '\0')
	{
		if (y[i] == x)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static t_flags			init_flags(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.star = 0;
	flags.precision = -1;
	flags.zero = 0;
	flags.width = 0;
	flags.type = 0;
	return (flags);
}

static int				flag_parse(const char *str, int i,
	t_flags *flags, va_list vl)
{
	while (str[i])
	{
		if (!check_specificator(str[i]) && !ft_isdigit(str[i])
		&& !ft_strchr("-0.*", str[i]) && str[i] != ' ')
			break ;
		if (str[i] == ' ')
			i += write(1, &str[i], 1);
		if (str[i] == '-')
			*flags = flag_minus(*flags);
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = flag_precision(str, i, flags, vl);
		if (str[i] == '*')
			*flags = flag_width(vl, *flags);
		if (ft_isdigit(str[i]))
			*flags = flag_digit(str[i], *flags);
		if (check_specificator(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static	int				parser(const char *format, va_list vl)
{
	int				i;
	int				char_count;
	t_flags			flags;

	i = 0;
	char_count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			flags = init_flags();
			i = flag_parse(format, i, &flags, vl);
			if (check_specificator(format[i]))
			{
				char_count += spec_efect(flags, format[i], vl);
			}
		}
		else
			char_count += write(1, &format[i], 1);
		i++;
	}
	return (char_count);
}

int						ft_printf(char *format, ...)
{
	va_list	vl;
	int		char_count;

	char_count = 0;
	va_start(vl, format);
	char_count = parser(format, vl);
	va_end(vl);
	return (char_count);
}
