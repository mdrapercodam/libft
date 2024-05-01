/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:25:20 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/27 16:39:28 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = ft_strlen(src);
	if (size < 1)
		return (count);
	while (--size && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (count);
}
