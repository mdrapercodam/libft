/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 20:15:40 by mdraper       #+#    #+#                 */
/*   Updated: 2024/03/11 16:53:29 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
These two functions are already inside the libft library.
*/

/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		res = malloc(0);
		if (!res)
			return (NULL);
		return (res);
	}
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}
*/

int	ft_pos(char *str, int c)
{
	int	pos;

	pos = 0;
	if (!str)
		return (-1);
	while (str[pos] != '\0')
	{
		if ((unsigned char)str[pos] == (unsigned char)c)
			return (pos + 1);
		pos++;
	}
	return (-1);
}

char	*ft_gnl_strdup(char *str)
{
	char	*rem;
	int		pos;
	int		i;

	i = 0;
	pos = ft_pos(str, '\n');
	rem = ft_calloc((ft_strlen(str) - pos + 1), sizeof(char));
	if (!rem || !str)
		return (NULL);
	while (str[pos] != '\0' && BUFFER_SIZE > pos)
		rem[i++] = str[pos++];
	if (ft_strlen(rem) == 0)
		return (ft_fn(&rem), NULL);
	return (rem);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	size_nl;
	char	*output;

	len_s1 = ft_strlen(s1);
	size_nl = 0;
	if (ft_pos(s2, '\n') == -1)
		size_nl = ft_strlen(s2);
	else
		size_nl = ft_pos(s2, '\n');
	output = ft_calloc((len_s1 + size_nl + 1), sizeof(char));
	if (!output)
		return (ft_fn(&s1), NULL);
	len_s1 = 0;
	if (s1)
	{
		while (s1[len_s1] != '\0')
		{
			output[len_s1] = s1[len_s1];
			len_s1++;
		}
	}
	while (*s2 && size_nl-- > 0)
		output[len_s1++] = *s2++;
	return (ft_fn(&s1), output);
}
