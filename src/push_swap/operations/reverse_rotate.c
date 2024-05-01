/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 12:15:43 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is rotate stack A.
Shift up all elements of the stack by 1, 
so the last element becomes the first one.
Do nothing if there is only one or no elements in the stack.
*/

int	ft_rra(t_pslst **stk_a, int print)
{
	if (ft_count_n_nodes(*stk_a, 3) < 2)
		return (0);
	*stk_a = (*stk_a)->prev;
	if (print == 1)
		ft_printf("rra\n");
	return (1);
}

/*
This function is rotate stack B.
Shift up all elements of the stack by 1, 
so the last element becomes the first one.
Do nothing if there is only one or no elements in the stack.
*/

int	ft_rrb(t_pslst **stk_b, int print)
{
	if (ft_count_n_nodes(*stk_b, 3) < 2)
		return (0);
	*stk_b = (*stk_b)->prev;
	if (print == 1)
		ft_printf("rrb\n");
	return (1);
}

/*
This function is rotate stack A and stack B.
Shift up all elements of the stack by 1, 
so the last element becomes the first one.
Do nothing if there is only one or no elements in one of the both stacks.
*/

int	ft_rrr(t_pslst **stk_a, t_pslst **stk_b, int print)
{
	if (ft_count_n_nodes(*stk_a, 3) < 2 || ft_count_n_nodes(*stk_b, 3) < 2)
		return (0);
	*stk_a = (*stk_a)->prev;
	*stk_b = (*stk_b)->prev;
	if (print == 1)
		ft_printf("rrr\n");
	return (1);
}
