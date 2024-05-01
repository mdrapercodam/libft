/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 12:13:23 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is rotate stack A.
Shift up all elements of the stack by 1, 
so the first element becomes the last one.
Do nothing if there is only one or no elements.
*/

int	ft_ra(t_pslst **stk_a, int print)
{
	if (ft_count_n_nodes(*stk_a, 3) < 2)
		return (0);
	*stk_a = (*stk_a)->next;
	if (print == 1)
		ft_printf("ra\n");
	return (1);
}

/*
This function is rotate stack B.
Shift up all elements of the stack by 1, 
so the first element becomes the last one.
Do nothing if there is only one or no elements.
*/

int	ft_rb(t_pslst **stk_b, int print)
{
	if (ft_count_n_nodes(*stk_b, 3) < 2)
		return (0);
	*stk_b = (*stk_b)->next;
	if (print == 1)
		ft_printf("rb\n");
	return (1);
}

/*
This function is rotate stack A and stack B.
Shift up all elements of the stack by 1, 
so the first element becomes the last one.
Do nothing if there is only one or no elements in one of the both stacks.
*/

int	ft_rr(t_pslst **stk_a, t_pslst **stk_b, int print)
{
	if (ft_count_n_nodes(*stk_a, 3) < 2 || ft_count_n_nodes(*stk_b, 3) < 2)
		return (0);
	*stk_a = (*stk_a)->next;
	*stk_b = (*stk_b)->next;
	if (print == 1)
		ft_printf("rr\n");
	return (1);
}
