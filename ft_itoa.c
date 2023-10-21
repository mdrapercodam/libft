/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 14:01:13 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/18 17:54:00 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_helper(char *temp, int i)
{
	char	*res;

	res = ft_calloc((ft_strlen(temp) + 1), sizeof(char));
	if (!res)
		return (0);
	while (--i >= 0)
		res[ft_strlen(temp) - i - 1] = temp[i];
	return (res);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	temp[12];
	int		sign;
	int		i;

	i = 0;
	nbr = n;
	sign = 0;
	ft_bzero(temp, 12);
	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
	}
	if (nbr == 0)
		temp[i++] = '0';
	while (nbr > 0)
	{
		temp[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (sign == -1)
		temp[i++] = '-';
	return (ft_itoa_helper(temp, i));
}
