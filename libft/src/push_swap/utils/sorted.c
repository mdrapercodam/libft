/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 11:59:54 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function checks if the stack is sorted.
You can give up if if the stack is sorted in ascending order
or in descending order. By giving true (ascending) or false (descending).
*/

int	ft_issorted(t_pslst *stack, bool ascending)
{
	t_pslst	*current;

	current = stack;
	if (ft_count_n_nodes(stack, 1) == 0)
		return (0);
	while (current->next != stack)
	{
		if (current->data > current->next->data && ascending == true)
			return (0);
		if (current->data < current->next->data && ascending == false)
			return (0);
		current = current->next;
	}
	return (1);
}

/*
This function checks if the stack is sorted.
You can give up if if the stack is sorted in ascending order
or in descending order. By giving true (ascending) or false (descending).
However it is maybe not sorted from the head node, 
so maybe the stack should rotate a bit.
*/

int	ft_check_issorted(t_pslst *stack, bool ascending)
{
	t_pslst	*max_or_min;

	if (ft_count_n_nodes(stack, 1) == 0)
		return (0);
	max_or_min = ft_find_max_or_min(stack, !ascending);
	return (ft_issorted(max_or_min, ascending));
}
