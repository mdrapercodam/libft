/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 12:07:25 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is pushing the top node of src to be the top node of dest.
This function can be used to push for the node from stack A to stack B 
or from stack B to stack A.
*/

static void	ft_push(t_pslst **dest, t_pslst **src, int ndest, int nsrc)
{
	t_pslst	*node;

	node = *src;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	if (nsrc == 1)
		*src = NULL;
	else
		*src = node->next;
	if (ndest == 0)
	{
		node->next = node;
		node->prev = node;
		*dest = node;
	}
	else
	{
		node->next = (*dest);
		node->prev = (*dest)->prev;
		(*dest)->prev->next = node;
		(*dest)->prev = node;
		*dest = node;
	}
}

/*
This function is push the top node of stack B to stack A.
Do nothing if stack B is empty.
*/

int	ft_pa(t_pslst **stk_a, t_pslst **stk_b, int print)
{
	int	nodes_a;
	int	nodes_b;

	nodes_a = ft_count_n_nodes(*stk_a, 1);
	nodes_b = ft_count_n_nodes(*stk_b, 2);
	if (nodes_b == 0)
		return (0);
	ft_push(stk_a, stk_b, nodes_a, nodes_b);
	if (print == 1)
		ft_printf("pa\n");
	return (1);
}

/*
This function is push the top node of stack A to stack B.
Do nothing if stack A is empty.
*/

int	ft_pb(t_pslst **stk_a, t_pslst **stk_b, int print)
{
	int	nodes_a;
	int	nodes_b;

	nodes_a = ft_count_n_nodes(*stk_a, 2);
	nodes_b = ft_count_n_nodes(*stk_b, 1);
	if (nodes_a == 0)
		return (0);
	ft_push(stk_b, stk_a, nodes_b, nodes_a);
	if (print == 1)
		ft_printf("pb\n");
	return (1);
}
