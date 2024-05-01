/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 21:49:23 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/30 15:47:41 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*res;

	first = 0;
	last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[first]) && s1[first])
		first++;
	while (ft_strchr(set, s1[last]) && last > first)
		last--;
	res = ft_substr(s1, first, last - first + 1);
	if (!res)
		return (0);
	return (res);
}
