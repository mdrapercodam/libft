/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 12:11:05 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is swap the top two nodes of a stack.
*/

static void	ft_swap(t_pslst **stack, int nodes)
{
	t_pslst	*node_1;
	t_pslst	*node_2;

	node_1 = *stack;
	node_2 = node_1->next;
	if (nodes == 2)
		*stack = node_2;
	else
	{
		node_2->next->prev = node_1;
		node_1->prev->next = node_2;
		node_2->prev = node_1->prev;
		node_1->prev = node_2;
		node_1->next = node_2->next;
		node_2->next = node_1;
		*stack = node_2;
	}
}

/*
This function is swap the top two nodes of stack A.
Do nothing if there is only one or no elements.
*/

int	ft_sa(t_pslst **stk_a, int print)
{
	int	nodes_a;

	nodes_a = ft_count_n_nodes(*stk_a, 3);
	if (nodes_a < 2)
		return (0);
	ft_swap(stk_a, nodes_a);
	if (print == 1)
		ft_printf("sa\n");
	return (1);
}

/*
This function is swap the top two nodes of stack B.
Do nothing if there is only one or no elements.
*/

int	ft_sb(t_pslst **stk_b, int print)
{
	int	nodes_b;

	nodes_b = ft_count_n_nodes(*stk_b, 3);
	if (nodes_b < 2)
		return (0);
	ft_swap(stk_b, nodes_b);
	if (print == 1)
		ft_printf("sb\n");
	return (1);
}

/*
This function is swap the top two nodes of stack A and stack B.
Do nothing if there is only one or no elements in one of the both stacks.
*/

int	ft_ss(t_pslst **stk_a, t_pslst **stk_b, int print)
{
	int	nodes_a;
	int	nodes_b;

	nodes_a = ft_count_n_nodes(*stk_a, 3);
	nodes_b = ft_count_n_nodes(*stk_b, 3);
	if (nodes_a < 2 || nodes_b < 2)
		return (0);
	ft_swap(stk_a, nodes_a);
	ft_swap(stk_b, nodes_b);
	if (print == 1)
		ft_printf("ss\n");
	return (1);
}
