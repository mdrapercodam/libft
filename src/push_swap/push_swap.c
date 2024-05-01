/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 13:51:06 by mdraper       #+#    #+#                 */
/*   Updated: 2024/05/01 16:09:22 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The main function to call push_swap.
*/

int	ft_push_swap(int argc, char const *argv[])
{
	t_pslst	*stk_a;
	t_pslst	*stk_b;
	int		i;

	stk_a = NULL;
	stk_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	i = 1;
	while (argc != i)
		ft_handle_input(&stk_a, &stk_b, argv[i++]);
	ft_algorithm(&stk_a, &stk_b);
	if (ft_issorted(stk_a, true))
		ft_free_lists(&stk_a, &stk_b, 0);
	else
		ft_free_lists(&stk_a, &stk_b, 0);
	return (0);
}
