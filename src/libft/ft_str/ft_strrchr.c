/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 16:40:51 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/27 13:10:33 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	if ((unsigned char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			result = (char *)s;
		s++;
	}
	return (result);
}
