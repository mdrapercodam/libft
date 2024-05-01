/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 09:23:00 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is called when there are:
- only two nodes in stack_a (int stack will be 1)
- only two nodes in stack_b (int stack will be 2)
- or there are two nodes in stack_a and stack_b, so four nodes in total.
(int stack will be 3).
*/

void	ft_sort_two(t_pslst **stk_a, t_pslst **stk_b, int stack)
{
	if (stack == 1)
	{
		if (ft_issorted(*stk_a, true) == 1)
			return ;
		else
			ft_sa(stk_a, 1);
	}
	if (stack == 2)
	{
		if (ft_issorted(*stk_b, false) == 1)
			return ;
		else
			ft_sb(stk_b, 1);
	}
	if (stack == 3)
	{
		ft_sort_two(stk_a, stk_b, 1);
		ft_sort_two(stk_a, stk_b, 2);
		ft_push_a(stk_a, stk_b);
	}
}

/*
This function is a helper function of ft_sort_three.
When stack = 1 selected it will go in to this function.
This function is hard coded to sort stack A in ascending order,
when it only has three nodes. This will do the job in <= 2 operations.
*/

static void	ft_sort_three_a(t_pslst **stk_a)
{
	if (ft_issorted(*stk_a, true))
		return ;
	if ((*stk_a)->data > (*stk_a)->next->data)
	{
		if ((*stk_a)->data < (*stk_a)->prev->data)
			ft_sa(stk_a, 1);
		else if ((*stk_a)->next->data < (*stk_a)->prev->data)
			ft_ra(stk_a, 1);
		else
		{
			ft_sa(stk_a, 1);
			ft_rra(stk_a, 1);
		}
	}
	else if ((*stk_a)->data < (*stk_a)->next->data)
	{
		if ((*stk_a)->data > (*stk_a)->prev->data)
			ft_rra(stk_a, 1);
		else
		{
			ft_rra(stk_a, 1);
			ft_sa(stk_a, 1);
		}
	}
}

/*
This function is a helper function of ft_sort_three.
When stack = 2 selected it will go in to this function.
This function is hard coded to sort stack B in descending order,
when it only has three nodes. This will do the job in <= 2 operations.
*/

static void	ft_sort_three_b(t_pslst **stk_b)
{
	if (ft_issorted(*stk_b, false))
		return ;
	if ((*stk_b)->data < (*stk_b)->next->data)
	{
		if ((*stk_b)->data > (*stk_b)->prev->data)
			ft_sb(stk_b, 1);
		else if ((*stk_b)->next->data > (*stk_b)->prev->data)
			ft_rb(stk_b, 1);
		else
		{
			ft_sb(stk_b, 1);
			ft_rrb(stk_b, 1);
		}
	}
	else if ((*stk_b)->data > (*stk_b)->next->data)
	{
		if ((*stk_b)->data < (*stk_b)->prev->data)
			ft_rrb(stk_b, 1);
		else
		{
			ft_rrb(stk_b, 1);
			ft_sb(stk_b, 1);
		}
	}
}

/*
This function is called when there are:
- only three nodes in stack_a (int stack will be 1)
- only three nodes in stack_b (int stack will be 2)
- or there are only six nodes in total (int stack will be 3).
*/

void	ft_sort_three(t_pslst **stk_a, t_pslst **stk_b, int stack)
{
	if (stack == 1)
		ft_sort_three_a(stk_a);
	if (stack == 2)
		ft_sort_three_b(stk_b);
	if (stack == 3)
	{
		ft_multiple_ops(stk_a, stk_b, 3, "pb");
		ft_sort_three_a(stk_a);
		ft_sort_three_b(stk_b);
		ft_push_a(stk_a, stk_b);
		ft_rotate_sort(stk_a, stk_b, true);
	}
}

/*
This function is called when all the nodes from stack B are 
pushed back to stack A. It only have to rotate before it is completely sorted
from the head. The rotating at the end is will be done efficiently looking 
at the index of the lowest node.
*/

void	ft_rotate_sort(t_pslst **stk_a, t_pslst **stk_b, bool ascending)
{
	t_pslst	*max_or_min;
	int		index;
	int		nodes;

	if (ascending == true)
	{
		max_or_min = ft_find_max_or_min((*stk_a), true);
		nodes = ft_count_nodes((*stk_a));
		index = ft_find_index((*stk_a), max_or_min);
		if ((nodes / 2) <= index)
			ft_multiple_ops(stk_a, stk_b, (nodes - index - 1), "rra");
		else
			ft_multiple_ops(stk_a, stk_b, (index + 1), "ra");
	}
	else
	{
		max_or_min = ft_find_max_or_min((*stk_b), false);
		nodes = ft_count_nodes((*stk_b));
		index = ft_find_index((*stk_b), max_or_min);
		if ((nodes / 2) < index)
			ft_multiple_ops(stk_a, stk_b, (nodes - index - 1), "rrb");
		else
			ft_multiple_ops(stk_a, stk_b, (index + 1), "rb");
	}
}
