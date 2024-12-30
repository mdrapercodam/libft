/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/29 11:57:47 by mdraper       #+#    #+#                 */
/*   Updated: 2024/12/30 11:46:20 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_free_int(int **value)
{
	if (!value || !*value)
		return ;
	free(*value);
	*value = NULL;
}
