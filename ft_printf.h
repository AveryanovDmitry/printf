/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoyl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:35:24 by hhoyl             #+#    #+#             */
/*   Updated: 2021/01/20 16:26:59 by hhoyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	int				width;
	int				minus;
	int				zero;
	int				precision;
	int				star;
	int				type;
}					t_flags;

int					ft_printf(char *str_inpt, ...);
int					ft_putchar(char c);
int					f_count(const char *format, va_list vl);
int					char_processing(char c, t_flags flags);
int					spec_efect(t_flags flags, char c, va_list vl);
int					str_processing(t_flags flags, char *str);
int					f_for_hexa(unsigned int ui, int lower, t_flags flags);
int					f_for_pointer(unsigned long long ull, t_flags flags);
int					flag_precision(const char *format, int start,
t_flags *flags, va_list vl);
int					f_for_width(int width, int precision, int has_zero);
int					int_processing(int i, t_flags flags);
int					print_str(char *str, int precision);
int					f_for_uint(unsigned int unsi, t_flags flags);

char				*ft_u_itoa(unsigned int n);
char				*f_for_ull(unsigned long long ull, int hex);
char				*str_tolower(char *str);

t_flags				flag_width(va_list vl, t_flags flags);
t_flags				flag_digit(char c, t_flags flags);
t_flags				flag_minus(t_flags flags);

#endif
