/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printunsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 16:29:57 by mdraper       #+#    #+#                 */
/*   Updated: 2024/03/11 12:33:42 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsigned(unsigned int n)
{
	char	res[12];
	int		j;
	int		i;

	i = 0;
	if (n == 0)
		res[i++] = '0';
	while (n > 0)
	{
		res[i++] = n % 10 + '0';
		n = n / 10;
	}
	j = i;
	while (i--)
		ft_putchar_fd(res[i], 1);
	return (j);
}
