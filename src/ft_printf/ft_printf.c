/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:12:05 by mdraper       #+#    #+#                 */
/*   Updated: 2024/03/11 12:33:30 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_type(const char *str, va_list par)
{
	int	val;

	val = 0;
	if (*str == 'c')
		val = val + ft_printchar(va_arg(par, int));
	else if (*str == 's')
		val = val + ft_printstring(va_arg(par, char *));
	else if (*str == 'd' || *str == 'i')
		val = val + ft_printdigit(va_arg(par, int));
	else if (*str == 'u')
		val = val + ft_printunsigned(va_arg(par, unsigned int));
	else if (*str == 'x')
		val = val + ft_printhexadecimal(va_arg(par, unsigned int), 'a');
	else if (*str == 'X')
		val = val + ft_printhexadecimal(va_arg(par, unsigned int), 'A');
	else if (*str == 'p')
		val = val + ft_printpointer(va_arg(par, unsigned long));
	return (val);
}

int	ft_printf(const char *str, ...)
{
	int		val;
	va_list	par;

	val = 0;
	va_start(par, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				return (-1);
			else if (ft_strchr("cspdiuxX", *str))
				val = val + check_type(str, par);
			else if (*str == '%')
				val = val + ft_printchar('%');
		}
		else
			val = val + ft_printchar(*str);
		if (*str)
			str++;
	}
	va_end(par);
	return (val);
}
