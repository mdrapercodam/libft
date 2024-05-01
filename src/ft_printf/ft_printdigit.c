/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printdigit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 16:28:37 by mdraper       #+#    #+#                 */
/*   Updated: 2024/03/11 12:33:27 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printdigit(int n)
{
	long	nbr;
	int		i;

	nbr = n;
	i = 0;
	if (nbr <= 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	return (i);
}
