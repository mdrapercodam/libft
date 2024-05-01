/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 18:35:35 by mdraper       #+#    #+#                 */
/*   Updated: 2023/11/01 18:35:43 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long nbr, int base)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr && ++i)
		nbr /= base;
	return (i);
}
