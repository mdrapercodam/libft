/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_count.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 18:53:47 by mdraper       #+#    #+#                 */
/*   Updated: 2024/05/03 18:59:23 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_count(const char *s, int c)
{
	int	count;

	count = 0;
	if ((unsigned char)c == '\0')
		return (ft_strlen(s));
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			count++;
		s++;
	}
	return (count);
}
