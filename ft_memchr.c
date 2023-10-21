/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 11:11:44 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/10 11:23:45 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		find;

	src = s;
	find = c;
	while (n--)
	{
		if (*src == find)
			return ((void *)src);
		src++;
	}
	return (0);
}
