/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 12:25:46 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is printing the stack.
If the list is empty, it prints that the stack is empty.
Otherwise it prints the address of the previous node, 
the data of the current node and address of the next node.
*/

void	ft_print_stack(t_pslst *head)
{
	t_pslst	*current;

	current = head;
	if (head == NULL)
	{
		ft_printf("List is empty\n");
		return ;
	}
	while (1)
	{
		ft_printf("Prev: %p\t\t", current->prev);
		ft_printf("Data: %d \t", current->data);
		ft_printf("Next: %p\n", current->next);
		current = current->next;
		if (current == head)
			break ;
	}
}

/*
This function is to print the contents of both stacks.
For better visualization it print which stack will be printed
and if that stack is sorted, or not.
*/

void	ft_print_stacks(t_pslst *stk_a, t_pslst *stk_b)
{
	if (ft_issorted(stk_a, true))
		ft_printf("\n--- Print stack A --- [sorted! (asc)]\n");
	else
		ft_printf("\n--- Print stack A --- [not sorted]\n");
	ft_print_stack(stk_a);
	if (ft_issorted(stk_b, false))
		ft_printf("\n--- Print stack B --- [sorted! (desc)]\n");
	else
		ft_printf("\n--- Print stack B --- [not sorted]\n");
	ft_print_stack(stk_b);
}
