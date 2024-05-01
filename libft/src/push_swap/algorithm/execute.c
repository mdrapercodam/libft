/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/20 09:07:19 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function can call an operation multiple times.
*/

int	ft_multiple_ops(t_pslst **stk_a, t_pslst **stk_b, int nmbr, char *ops)
{
	int	i;

	i = 0;
	while (i < nmbr)
	{
		if (ft_strcmp(ops, "pa") == 0)
			ft_pa(stk_a, stk_b, 1);
		if (ft_strcmp(ops, "pb") == 0)
			ft_pb(stk_a, stk_b, 1);
		if (ft_strcmp(ops, "ra") == 0)
			ft_ra(stk_a, 1);
		if (ft_strcmp(ops, "rb") == 0)
			ft_rb(stk_b, 1);
		if (ft_strcmp(ops, "rr") == 0)
			ft_rr(stk_a, stk_b, 1);
		if (ft_strcmp(ops, "rra") == 0)
			ft_rra(stk_a, 1);
		if (ft_strcmp(ops, "rrb") == 0)
			ft_rrb(stk_b, 1);
		if (ft_strcmp(ops, "rrr") == 0)
			ft_rrr(stk_a, stk_b, 1);
		i++;
	}
	return (i);
}

/*
This function is a helper function of ft_find_rotate.
It only goes in this function if the operation reverse rotate should be called.
It will calculate the number of moves it did and returns that value back 
to ft_find_rotate.
*/

static int	ft_ops_rr(t_pslst **stk_a, t_pslst **stk_b, int idx_a, int idx_b)
{
	int	moves;
	int	nodes_a;
	int	nodes_b;

	moves = 0;
	nodes_a = ft_count_nodes((*stk_a));
	nodes_b = ft_count_nodes((*stk_b));
	while (idx_a < nodes_a && idx_b < nodes_b)
	{
		idx_b++;
		idx_a++;
		moves += ft_rrr(stk_a, stk_b, 1);
	}
	while (idx_a++ < nodes_a)
		moves += ft_rra(stk_a, 1);
	while (idx_b++ < nodes_b)
		moves += ft_rrb(stk_b, 1);
	return (moves);
}

/*
This function is a helper function of ft_find_rotate.
It only goes in this function if the operation rotate and reverse rotate 
should be called.
It will calculate the number of moves it did and returns that value back 
to ft_find_rotate.
*/

static int	ft_ops_r_rr(t_pslst **stk_a, t_pslst **stk_b, int idx_a, int idx_b)
{
	int	moves;
	int	nodes_a;
	int	nodes_b;

	moves = 0;
	nodes_a = ft_count_nodes((*stk_a));
	nodes_b = ft_count_nodes((*stk_b));
	if ((nodes_b / 2) < idx_b)
	{
		moves += ft_multiple_ops(stk_a, stk_b, nodes_b - idx_b, "rrb");
		moves += ft_multiple_ops(stk_a, stk_b, idx_a, "ra");
	}
	else if ((nodes_a / 2) < idx_a)
	{
		moves += ft_multiple_ops(stk_a, stk_b, nodes_a - idx_a, "rra");
		moves += ft_multiple_ops(stk_a, stk_b, idx_b, "rb");
	}
	return (moves);
}

/*
This function is a helper function of ft_find_rotate.
It only goes in this function if the operation rotate should be called.
It will calculate the number of moves it did and returns that value back 
to ft_find_rotate.
*/

static int	ft_ops_r(t_pslst **stk_a, t_pslst **stk_b, int idx_a, int idx_b)
{
	int	moves;

	moves = 0;
	while (idx_b > 0 && idx_a > 0)
	{
		idx_b--;
		idx_a--;
		moves += ft_rr(stk_a, stk_b, 1);
	}
	while (idx_a-- > 0)
		moves += ft_ra(stk_a, 1);
	while (idx_b-- > 0)
		moves += ft_rb(stk_b, 1);
	return (moves);
}

/*
This function is calculating in what direction the rotation should go.
*/

int	ft_find_rotate(t_pslst **stk_a, t_pslst **stk_b, int idx_a, int idx_b)
{
	int	moves;
	int	nodes_a;
	int	nodes_b;

	moves = 0;
	nodes_a = ft_count_nodes((*stk_a));
	nodes_b = ft_count_nodes((*stk_b));
	if ((nodes_b / 2) < idx_b && (nodes_a / 2) <= idx_a)
		moves += ft_ops_rr(stk_a, stk_b, idx_a, idx_b);
	else if ((nodes_b / 2) < idx_b || (nodes_a / 2) < idx_a)
		moves += ft_ops_r_rr(stk_a, stk_b, idx_a, idx_b);
	else
		moves += ft_ops_r(stk_a, stk_b, idx_a, idx_b);
	return (moves);
}
