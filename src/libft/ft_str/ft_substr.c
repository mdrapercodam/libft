/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:38:56 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/31 14:57:22 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			str_len;
	char			*sub_str;

	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	else if (len > str_len - start)
		len = str_len - start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (0);
	while (start-- && len != 0)
		s++;
	ft_strlcpy(sub_str, s, len + 1);
	return (sub_str);
}
