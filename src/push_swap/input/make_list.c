/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 13:57:49 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function allocates memory for the new node and fills the data.
However this data is not correct and will be adjusted in the other function.
*/

static t_pslst	*ft_create_node(int data)
{
	t_pslst	*new_node;

	new_node = malloc(sizeof(t_pslst));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/*
This function first checks if the input is correct.
If so, it will create a new node.
After it adjust the addresses of the new node and other nodes if there are.
*/

int	ft_make_list(t_pslst **stk_a, int data)
{
	t_pslst	*new_node;
	t_pslst	*head;

	if (ft_check_value(stk_a, data) == -1)
		return (-1);
	new_node = ft_create_node(data);
	if (!new_node)
		return (-2);
	if (*stk_a == NULL)
	{
		*stk_a = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		head = *stk_a;
		head->prev->next = new_node;
		new_node->prev = head->prev;
		new_node->next = head;
		head->prev = new_node;
	}
	return (0);
}

/*
This function is used for the input 
and transform a string into integers.
Afterwards ft_make_list makes seperate 
nodes of the input and make it a linked list.
*/

void	ft_split_string(t_pslst **stk_a, t_pslst **stk_b, const char *str)
{
	char	**new_str;
	int		x;
	int		i;

	x = 0;
	new_str = ft_split(str, ' ');
	if (!new_str)
		ft_free_lists(stk_a, stk_b, -2);
	while (new_str[x] != NULL)
	{
		if (ft_check_valid_int(new_str[x]) == -1)
			ft_free_split(new_str, stk_a, stk_b, -1);
		i = ft_make_list(stk_a, ft_atoi(new_str[x++]));
		if (i != 0)
			ft_free_split(new_str, stk_a, stk_b, i);
	}
	ft_free_split(new_str, stk_a, stk_b, i);
}

/*
This function checks if the string is valid 
and if the string needs to be splitted.
If it not have to be splitted, it will add 
the value to the list using ft_make_list.
*/

void	ft_handle_input(t_pslst **stk_a, t_pslst **stk_b, const char *str)
{
	int	i;

	i = 0;
	if (ft_check_string(str) == -1)
		ft_free_lists(stk_a, stk_b, -1);
	if (ft_check_spaces(str) == 1)
		ft_split_string(stk_a, stk_b, str);
	else
	{
		if (ft_check_valid_int(str) == -1)
			ft_free_lists(stk_a, stk_b, -1);
		i = ft_make_list(stk_a, ft_atoi(str));
		if (i != 0)
			ft_free_lists(stk_a, stk_b, i);
	}
}
