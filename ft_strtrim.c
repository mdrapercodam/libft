/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 21:49:23 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/13 13:03:54 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_l;
	size_t	i;
	size_t	j;
	char	*res;

	s1_l = ft_strlen(s1);
	i = 0;
	j = 0;
	while (ft_strchr(set, s1[i]) != 0 && s1[i] != '\0')
		i++;
	while (ft_strchr(set, s1[s1_l - 1 - j]) != 0 && s1[s1_l - 1 - j] != '\0')
		j++;
	j = s1_l - j;
	if (i > j)
		res = malloc((1) * sizeof(char));
	else
		res = malloc((j - i + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, &s1[i], j - i + 1);
	return (res);
}
