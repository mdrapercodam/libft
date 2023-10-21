/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:38:56 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/18 17:46:55 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	copy_start;
	size_t			str_len;
	char			*sub_str;

	copy_start = start;
	str_len = ft_strlen(s);
	if (start > str_len)
		len = 0;
	else
		while (start--)
			s++;
	if (str_len - copy_start < len && str_len > copy_start)
		str_len = str_len - copy_start + 1;
	else
		str_len = len + 1;
	sub_str = malloc(str_len * sizeof(char));
	if (!sub_str)
		return (0);
	ft_strlcpy(sub_str, s, str_len);
	return (sub_str);
}
