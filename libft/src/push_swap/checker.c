/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/23 17:07:44 by mdraper       #+#    #+#                 */
/*   Updated: 2024/05/01 16:08:02 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
To finish the execution you need to press "CTRL + D"
*/

void	ft_checker_error(t_pslst **stk_a, t_pslst **stk_b, int i, char *line)
{
	ft_fn(&line);
	if (i == 1)
		ft_free_lists(stk_a, stk_b, 1);
	else if (i == 0)
	{
		ft_printf("KO\n");
		ft_free_lists(stk_a, stk_b, 0);
		exit(EXIT_SUCCESS);
	}
	else if (i == -1)
		ft_free_lists(stk_a, stk_b, -1);
	else if (i == -2)
		ft_free_lists(stk_a, stk_b, -2);
}

int	ft_check_input(t_pslst **stk_a, t_pslst **stk_b, const char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (ft_sa(stk_a, 0));
	if (ft_strcmp(str, "sb\n") == 0)
		return (ft_sb(stk_b, 0));
	if (ft_strcmp(str, "ss\n") == 0)
		return (ft_ss(stk_a, stk_b, 0));
	if (ft_strcmp(str, "pa\n") == 0)
		return (ft_pa(stk_a, stk_b, 0));
	if (ft_strcmp(str, "pb\n") == 0)
		return (ft_pb(stk_a, stk_b, 0));
	if (ft_strcmp(str, "ra\n") == 0)
		return (ft_ra(stk_a, 0));
	if (ft_strcmp(str, "rb\n") == 0)
		return (ft_rb(stk_b, 0));
	if (ft_strcmp(str, "rr\n") == 0)
		return (ft_rr(stk_a, stk_b, 0));
	if (ft_strcmp(str, "rra\n") == 0)
		return (ft_rra(stk_a, 0));
	if (ft_strcmp(str, "rrb\n") == 0)
		return (ft_rrb(stk_b, 0));
	if (ft_strcmp(str, "rrr\n") == 0)
		return (ft_rrr(stk_a, stk_b, 0));
	return (-1);
}

char	*ft_read_line(t_pslst **stk_a, t_pslst **stk_b)
{
	char	*line;
	int		result;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		result = ft_check_input(stk_a, stk_b, line);
		if (result == -1)
			ft_checker_error(stk_a, stk_b, -1, line);
		ft_fn(&line);
	}
	return (line);
}

int	ft_checker_push_swap(int argc, char const *argv[])
{
	t_pslst	*stk_a;
	t_pslst	*stk_b;
	int		i;
	char	*line;

	stk_a = NULL;
	stk_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	i = 1;
	while (argc != i)
		ft_handle_input(&stk_a, &stk_b, argv[i++]);
	line = ft_read_line(&stk_a, &stk_b);
	if (ft_issorted(stk_a, true) == 1 && ft_count_n_nodes(stk_b, 1) == 0)
		ft_checker_error(&stk_a, &stk_b, 1, line);
	else
		ft_checker_error(&stk_a, &stk_b, 0, line);
	return (0);
}
