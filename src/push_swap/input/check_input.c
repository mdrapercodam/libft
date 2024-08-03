/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/09 13:41:01 by mdraper       #+#    #+#                 */
/*   Updated: 2024/04/10 12:26:58 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function checks if the string is valid with the allowed characters.
*/

int	ft_check_string(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' \
			&& str[i] != '-' && str[i] != '+')
			return (-1);
		i++;
	}
	return (1);
}

/*
This function checks if there are spaces in the string.
This is used for if we need to use ft_split.
*/

int	ft_check_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == ' ')
			return (1);
	}
	return (0);
}

/*
This function checks if there are characters after the number.
If so it will return an error.
*/

int	ft_check_char_after_digit(const char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			x = i;
		}
		while (ft_isdigit(str[i]))
			i++;
		while (str[i] != '\0')
			return (-1);
		if (x == i)
			return (-1);
	}
	return (1);
}

/*
This function checks if string is a valid integer. 
It also checks if there are characters after the integer.
*/

int	ft_check_valid_int(const char *str)
{
	int	len_str;
	int	i;

	i = 0;
	len_str = ft_strlen(str);
	if (!ft_check_char_after_digit(str))
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (len_str > 11)
			return (-1);
		else if (len_str == 11 \
			&& ((str[i] == '-' && ft_strcmp(str, "-2147483648") > 0) \
			|| (str[i] == '+' && ft_strcmp(str, "+2147483647") > 0)))
			return (-1);
	}
	else
	{
		if (len_str > 10)
			return (-1);
		else if (len_str == 10 && ft_strcmp(str, "2147483647") > 0)
			return (-1);
	}
	return (0);
}

/*
This function checks if value is already excisting in one of the nodes.
*/

int	ft_check_value(t_pslst **head, int data)
{
	t_pslst	*node;
	int		nodes;
	int		i;

	node = *head;
	nodes = ft_count_nodes(*head);
	i = 0;
	while (i != nodes)
	{
		if (data == node->data)
			return (-1);
		node = node->next;
		i++;
	}
	return (1);
}
