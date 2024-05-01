/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:55:44 by mdraper       #+#    #+#                 */
/*   Updated: 2023/11/07 17:32:57 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		n;
	size_t		i;

	n = 0;
	i = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while (n < len && *big != '\0')
	{
		if (!(ft_strncmp(big, little, i)) && len >= i + n)
			return ((char *)big);
		n++;
		big++;
	}
	return (0);
}
