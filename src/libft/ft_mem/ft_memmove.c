/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 17:21:20 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/27 15:51:54 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destptr;
	unsigned const char	*srcptr;

	destptr = (unsigned char *)dest;
	srcptr = (unsigned const char *)src;
	if (!dest && !src)
		return (0);
	if (dest < src || dest >= src + n)
		ft_memcpy(dest, src, n);
	else
	{
		while (n)
		{
			destptr[n - 1] = srcptr[n - 1];
			n--;
		}
	}
	return (dest);
}
