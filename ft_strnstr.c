/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:55:44 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/10 14:25:32 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*copy_b;
	const char	*copy_l;
	size_t		n;
	size_t		i;

	copy_b = big;
	copy_l = little;
	n = 0;
	if (*copy_l == '\0')
		return ((char *)big);
	while (n < len && *big != '\0')
	{
		i = 0;
		while (copy_l[i] != '\0' && copy_l[i] == copy_b[i + n] && n + i < len)
			i++;
		if (copy_l[i] == '\0')
			return ((char *)big);
		n++;
		big++;
	}
	return (0);
}
