/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 08:40:32 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is calculating the number of moves to push the node to stack B.
If the position it should be pushed is on the lowerhand of the stack, then it 
should reverse rotate, otherwise it should just rotate. 
But the index of that node in stack A also matters, because you can rotate at
the same time. This function is calculating it all!
It is calculating one more move for the push.
*/

int	ft_count_moves(t_pslst **stk_a, t_pslst **stk_b, int pos, int idx)
{
	int		nodes_a;
	int		nodes_b;
	int		moves;

	moves = 0;
	nodes_a = ft_count_nodes((*stk_a));
	nodes_b = ft_count_nodes((*stk_b));
	if ((nodes_b / 2) < pos && (nodes_a / 2) <= idx)
	{
		if ((nodes_b - pos) >= (nodes_a - idx))
			moves = nodes_b - pos;
		else if ((nodes_b - pos) < (nodes_a - idx))
			moves = nodes_a - idx;
		return (++moves);
	}
	if ((nodes_b / 2) < pos)
		moves = nodes_b - pos + idx;
	else if ((nodes_a / 2) < idx)
		moves = nodes_a - idx + pos;
	else if (pos < idx)
		moves = idx;
	else if (pos >= idx)
		moves = pos;
	return (++moves);
}

/*
This function is calculating for every node how many operations it will take to
push that node to stack B. It will remember only the most efficient one (so the
one with the lowest amount of moves).
To achieve this it uses the function ft_find_position and ft_count_moves.
Long story short: 
- ft_find_position search on what index of B it should be pushed.
- ft_count_moves calculates the number of moves.
It returns the number of operations of the most efficient node,
and push remembers which node is the most efficient to push.
*/

int	ft_cheapest(t_pslst **stk_a, t_pslst **stk_b, t_pslst **push_node)
{
	t_pslst	*current;
	int		cheapest;
	int		idx_a;
	int		moves;

	current = (*stk_a);
	idx_a = 0;
	cheapest = INT32_MAX;
	while (1)
	{
		moves = ft_find_position((*stk_b), current->data, false);
		moves = ft_count_moves(stk_a, stk_b, moves, idx_a);
		if (moves < cheapest)
		{
			cheapest = moves;
			(*push_node) = current;
			if (moves <= 2)
				return (cheapest);
		}
		idx_a++;
		current = current->next;
		if (current == (*stk_a))
			break ;
	}
	return (cheapest);
}
