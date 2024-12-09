/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 16:48:46 by mdraper       #+#    #+#                 */
/*   Updated: 2024/12/09 16:49:02 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char ***str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	if (str[0])
	{
		while (str[0][i])
		{
			free(str[0][i]);
			str[0][i] = NULL;
			i++;
		}
		free(str[0]);
		str[0] = NULL;
	}
}
