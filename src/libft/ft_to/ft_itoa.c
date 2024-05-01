/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 14:01:13 by mdraper       #+#    #+#                 */
/*   Updated: 2023/11/01 18:36:34 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_numlen(long nbr, int base)
// {
// 	int	i;

// 	i = 0;
// 	if (nbr <= 0)
// 		i++;
// 	while (nbr && ++i)
// 		nbr /= base;
// 	return (i);
// }

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = ft_numlen(n, 10);
	res = (char *)ft_calloc((i + 1), sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
		res[0] = '-';
	if (n == 0)
		res[0] = '0';
	while (n)
	{
		if (n > 0)
			res[--i] = n % 10 + '0';
		else
			res[--i] = n % 10 * -1 + '0';
		n /= 10;
	}
	return (res);
}
