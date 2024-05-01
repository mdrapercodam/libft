/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/14 10:59:10 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is doing the execution to push the most efficient node (with 
the lowest number of moves) to stack B. However it doesn't know what kind
of operations it should do, only the number of moves that is allowed.
So it uses the same logic for finding the cheapest node, but instead of 
calculating you will do the real operations. To make sure the program is 
working well, it will decrement the number of moves to 0. If it is not 0
it will free the stacks and return that there is an error in the code.
*/

void	ft_push_b(t_pslst **stk_a, t_pslst **stk_b, t_pslst *push, int moves)
{
	int	idx_a;
	int	idx_b;

	idx_a = ft_find_index((*stk_a), push);
	idx_b = ft_find_position((*stk_b), push->data, false);
	if (moves > 1)
		moves -= ft_find_rotate(stk_a, stk_b, idx_a, idx_b);
	if (moves == 1)
		moves -= ft_pb(stk_a, stk_b, 1);
	if (moves != 0)
		ft_free_lists(stk_a, stk_b, -3);
}

/*
This function is pushing every node of stack B to stack A. 
It is everytime pushing the top node of stack B, to save some calculation,
because stack B is already sorted in descending order.
Before the top node will be pushed it will use the same logic as before.
So first search where that node should be placed in stack A.
Second count the moves of this operation.
As last it is doing the operation.
*/

void	ft_push_a(t_pslst **stk_a, t_pslst **stk_b)
{
	int	nodes_a;
	int	nodes_b;
	int	idx_a;
	int	moves;

	nodes_a = ft_count_nodes((*stk_a));
	nodes_b = ft_count_nodes((*stk_b));
	while (nodes_b > 0)
	{
		idx_a = ft_find_position((*stk_a), (*stk_b)->data, true);
		moves = ft_count_moves(stk_a, stk_b, 0, idx_a);
		if (moves > 1)
			moves -= ft_find_rotate(stk_a, stk_b, idx_a, 0);
		nodes_b--;
		nodes_a++;
		if (moves == 1)
			moves -= ft_pa(stk_a, stk_b, 1);
		if (moves != 0)
			ft_free_lists(stk_a, stk_b, -3);
	}
}

/*
This function is checking if there is only a small amount of nodes is in 
the stack(s).
If it is, it will go in to one of the functions in the sort_x file.
*/

void	ft_sort_small(t_pslst **stk_a, t_pslst **stk_b, int nds_a, int nds_b)
{
	if (ft_issorted((*stk_a), true) && nds_b == 0)
		return ;
	if (nds_a == 2)
		ft_sort_two(stk_a, stk_b, 1);
	else if (nds_a == 3)
		ft_sort_three(stk_a, stk_b, 1);
	else if (ft_check_issorted((*stk_a), true))
		ft_rotate_sort(stk_a, stk_b, true);
	else if (nds_a == 6)
		ft_sort_three(stk_a, stk_b, 3);
	if (nds_b == 2)
		ft_sort_two(stk_a, stk_b, 2);
	else if (nds_b == 3)
		ft_sort_three(stk_a, stk_b, 2);
}

/*
This function is the algorithm. This algorithm is called the Turk Algorithm.
It first pushes two nodes to stack B (if there are more then three nodes)
and after it calculates the most efficient node to push to B. It is doing 
this by calculating for every node in stack A number of moves to push it to B.
Stack B have to pushed in descending order (from high to low).
When all the nodes are pushed to B (till there are three left in A). It will
push all the nodes back in to stack A.
*/

void	ft_algorithm(t_pslst **stk_a, t_pslst **stk_b)
{
	t_pslst	*push_node;
	int		nodes_a;
	int		nodes_b;
	int		operations;

	nodes_a = ft_count_nodes(*stk_a);
	ft_sort_small(stk_a, stk_b, nodes_a, 0);
	if (nodes_a > 3 && !ft_issorted(*stk_a, true))
	{
		ft_multiple_ops(stk_a, stk_b, 2, "pb");
		nodes_a -= 2;
	}
	while (nodes_a > 3 && !ft_check_issorted((*stk_a), true))
	{
		operations = ft_cheapest(stk_a, stk_b, &push_node);
		ft_push_b(stk_a, stk_b, push_node, operations);
		nodes_a--;
	}
	nodes_b = ft_count_nodes(*stk_b);
	ft_sort_small(stk_a, stk_b, nodes_a, nodes_b);
	if (ft_count_n_nodes((*stk_b), 1) > 0)
		ft_push_a(stk_a, stk_b);
	if (!ft_issorted((*stk_a), true))
		ft_rotate_sort(stk_a, stk_b, true);
}
