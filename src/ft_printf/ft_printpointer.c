/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printpointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 17:10:51 by mdraper       #+#    #+#                 */
/*   Updated: 2024/03/11 12:33:36 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printpointer(unsigned long n)
{
	char			res[23];
	int				i;
	int				j;

	i = 0;
	if (n == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	while (n > 0)
	{
		if (n % 16 >= 10)
			res[i++] = n % 16 + 'a' - 10;
		else
			res[i++] = n % 16 + '0';
		n = n / 16;
	}
	res[i++] = 'x';
	res[i++] = '0';
	j = i;
	while (i--)
		ft_putchar_fd(res[i], 1);
	return (j);
}
