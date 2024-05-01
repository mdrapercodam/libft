/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 13:04:44 by mdraper       #+#    #+#                 */
/*   Updated: 2023/10/15 21:29:38 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	memory_check(char **res, char *str, int words)
{
	int	i;

	i = 0;
	if (!res)
		return (0);
	if (!str)
	{
		while (i < words)
			free(res[i++]);
		free(res);
		return (0);
	}
	return (1);
}

static int	ft_splitter(char const *s, char c, char **res, int count)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		count = 0;
		while (s[i] && s[i] != c)
		{
			count++;
			i++;
		}
		if (count != 0)
		{
			res[words] = malloc((count + 1) * sizeof(char));
			if (memory_check(res, res[words], words) == 0)
				return (0);
			ft_strlcpy(res[words++], &s[i - count], count + 1);
		}
		if (s[i])
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**res;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	res = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!res)
		return (0);
	if (ft_splitter(s, c, res, count) == 0)
		return (0);
	return (res);
}
