/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_null.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 14:40:08 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function is freeing every node in the stack.
It also put the values to NULL.
*/

static void	ft_free_stack(t_pslst **stack, int nmbr_nodes)
{
	t_pslst	*current;
	t_pslst	*next;

	current = *stack;
	while (nmbr_nodes-- > 0)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
	*stack = NULL;
}

/*
This function is freeing stack A and stack B.
It also exit the whole program if there is an error.
*/

void	ft_free_lists(t_pslst **stk_a, t_pslst **stk_b, int err)
{
	int	nmbr_stk_a;
	int	nmbr_stk_b;

	nmbr_stk_a = ft_count_nodes(*stk_a);
	nmbr_stk_b = ft_count_nodes(*stk_b);
	if (nmbr_stk_a > 0)
		ft_free_stack(stk_a, nmbr_stk_a);
	if (nmbr_stk_b > 0)
		ft_free_stack(stk_b, nmbr_stk_b);
	if (err < 0)
	{
		if (err == -1)
			ft_putstr_fd("Error\n", 2);
		if (err == -2)
			ft_putstr_fd("Malloc Error\n", 2);
		if (err == -3)
			ft_printf("Error in code!\n");
		exit(EXIT_FAILURE);
	}
	else if (err == 1)
	{
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
}

/*
This function is used for freeing the memory when the function split is used.
*/

void	ft_free_split(char **split, t_pslst **stk_a, t_pslst **stk_b, int err)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	if (split != NULL)
	{
		free(split);
		split = NULL;
	}
	if (err != 0)
		ft_free_lists(stk_a, stk_b, err);
}
