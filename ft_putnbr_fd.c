/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 13:01:49 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/15 18:08:18 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res[12];
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (nbr > 0)
	{
		res[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	while (i--)
		write(fd, &res[i], 1);
}
