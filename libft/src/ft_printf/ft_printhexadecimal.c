/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhexadecimal.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 16:31:13 by mdraper       #+#    #+#                 */
/*   Updated: 2024/03/11 12:33:33 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexadecimal(unsigned long n, int hex)
{
	char	res[21];
	int		i;
	int		j;

	i = 0;
	if (n == 0)
		res[i++] = '0';
	while (n > 0)
	{
		if (n % 16 >= 10)
			res[i++] = n % 16 + hex - 10;
		else
			res[i++] = n % 16 + '0';
		n = n / 16;
	}
	j = i;
	while (i--)
		ft_putchar_fd(res[i], 1);
	return (j);
}
