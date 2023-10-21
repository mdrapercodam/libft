/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 16:24:34 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/18 17:54:20 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*duplicate;

	len = 0;
	while (s[len] != '\0')
		len++;
	duplicate = (char *)malloc((len + 1) * sizeof(char));
	if (!duplicate)
		return (0);
	len = 0;
	while (s[len] != '\0')
	{
		duplicate[len] = s[len];
		len++;
	}
	duplicate[len] = '\0';
	return (duplicate);
}
