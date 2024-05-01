/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 12:50:14 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/27 14:55:02 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destptr;
	unsigned const char	*srcptr;

	destptr = (unsigned char *)dest;
	srcptr = (unsigned const char *)src;
	if (!dest && !src)
		return (0);
	while (n--)
		*destptr++ = *srcptr++;
	return (dest);
}
