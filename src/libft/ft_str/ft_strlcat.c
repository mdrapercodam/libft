/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 14:17:08 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/27 16:39:11 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;
	size_t	count;

	i = 0;
	len_dest = ft_strlen(dest);
	if (size < len_dest)
		return (size + ft_strlen(src));
	count = ft_strlen(src) + len_dest;
	while (src[i] && len_dest < size - 1 && size != 0)
		dest[len_dest++] = src[i++];
	dest[len_dest] = '\0';
	return (count);
}
