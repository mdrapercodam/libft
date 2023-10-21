/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 16:40:51 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/10 13:54:05 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	find_c;
	char			*result;

	find_c = (unsigned char)c;
	result = 0;
	if (find_c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if ((unsigned char)*s == find_c)
			result = (char *)s;
		s++;
	}
	return (result);
}
