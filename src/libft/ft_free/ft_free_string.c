/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/09 16:48:20 by mdraper       #+#    #+#                 */
/*   Updated: 2024/12/09 16:48:31 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_string(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}
