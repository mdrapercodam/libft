/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 13:01:49 by mdraper       #+#    #+#                 */
/*   Updated: 2023/11/01 18:36:43 by mdraper       ########   odam.nl         */
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

void	ft_putnbr_fd(int n, int fd)
{
	char	res[13];
	int		i;

	i = ft_numlen(n, 10);
	res[i] = '\0';
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
	ft_putstr_fd(res, fd);
}
