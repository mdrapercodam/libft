/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 16:20:23 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function can find the lowest or highest number in the stack.
It returns the pointer of that node.
*/

t_pslst	*ft_find_max_or_min(t_pslst *stack, bool max)
{
	t_pslst	*pntr;
	t_pslst	*current;

	current = stack;
	pntr = current;
	while (1)
	{
		if (pntr->data < current->data && max == true)
			pntr = current;
		if (pntr->data > current->data && max == false)
			pntr = current;
		if (current->next == stack)
			break ;
		current = current->next;
	}
	return (pntr);
}

/*
This is a helper function of ft_find_position.
This function is searching in what position the number should be placed.
But only if the number is lowest in the stack.
To find the next lowest number, the function ft_find_max_or_min is used.
The return value is later used to know how many rotates you should do,
to get the stack on the right position to push the number to the other stack.
*/

static int	ft_find_pos_min(t_pslst *stack, int nmbr, bool asc)
{
	t_pslst	*ptr_min;
	int		pos;

	pos = 0;
	ptr_min = ft_find_max_or_min(stack, false);
	if (nmbr > ptr_min->data)
		return (-1);
	else if (nmbr < ptr_min->data)
	{
		while (stack != ptr_min->next && asc == false)
		{
			stack = stack->next;
			pos++;
		}
		while (stack != ptr_min && asc == true)
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
}

/*
This is a helper function of ft_find_position.
This function is searching in what position the number should be placed.
But only if the number is highest in the stack.
To find the next highest number, the function ft_find_max_or_min is used.
The return value is later used to know how many rotates you should do,
to get the stack on the right position to push the number to the other stack.
*/

static int	ft_find_pos_max(t_pslst *stack, int nmbr, bool asc)
{
	t_pslst	*ptr_max;
	int		pos;

	pos = 0;
	ptr_max = ft_find_max_or_min(stack, true);
	if (nmbr < ptr_max->data)
		return (-1);
	else if (nmbr > ptr_max->data)
	{
		while (stack != ptr_max && asc == false)
		{
			stack = stack->next;
			pos++;
		}
		while (stack != ptr_max->next && asc == true)
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
}

/*
This function is searching in what position the number should be placed.
It also handles if the number is the lowest or highest number in the stack.
For these cases it uses the ft_find_pos_min and ft_find_pos_max funstions.
The return value is later used to know how many rotates you should do,
to get the stack on the right position to push the number to the other stack.
*/

int	ft_find_position(t_pslst *stack, int nmbr, bool asc)
{
	t_pslst	*current;
	int		pos;

	current = stack;
	pos = ft_find_pos_min(stack, nmbr, asc);
	if (pos != -1)
		return (pos);
	pos = ft_find_pos_max(stack, nmbr, asc);
	if (pos != -1)
		return (pos);
	pos = 0;
	while (1)
	{
		if (nmbr > current->data && nmbr < current->prev->data && asc == false)
			return (pos);
		if (nmbr < current->data && nmbr > current->prev->data && asc == true)
			return (pos);
		pos++;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (pos);
}

/*
This function finds the index of the push node.
But be carefull that you give the right stack, or it could give problems!
*/

int	ft_find_index(t_pslst *stack, t_pslst *node)
{
	int	index;
	int	nodes;

	index = 0;
	nodes = ft_count_nodes(stack);
	while (stack != node && nodes--)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}
