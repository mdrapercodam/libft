/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 13:48:27 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is counting the number of nodes in the stack.
*/

int	ft_count_nodes(t_pslst *stack)
{
	t_pslst	*current;
	int		count;

	current = stack;
	count = 0;
	if (stack == NULL)
		return (count);
	while (1)
	{
		count++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (count);
}

/*
This function is counting the number of nodes in the stack,
till the (n) number that is requested.
*/

int	ft_count_n_nodes(t_pslst *stack, int n)
{
	t_pslst	*current;
	int		count;

	current = stack;
	count = 0;
	if (stack == NULL)
		return (count);
	while (count < n)
	{
		count++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (count);
}
