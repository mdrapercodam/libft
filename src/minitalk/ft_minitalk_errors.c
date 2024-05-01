/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_minitalk_errors.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 12:31:10 by mdraper       #+#    #+#                 */
/*   Updated: 2024/05/01 16:14:21 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_minitalk_errors(int error_nmbr)
{
	if (error_nmbr == 1)
		ft_putstr_fd("usage: ./client <server_pid> <string>\n", 2);
	else if (error_nmbr == 2)
		ft_putstr_fd("Invalid PID\n", 2);
	else if (error_nmbr == 3)
		ft_putstr_fd("Recieved other signal then expected\n", 2);
	else if (error_nmbr == 4)
		ft_putstr_fd("Kill Error\n", 2);
	else if (error_nmbr == 5)
		ft_putstr_fd("Timeout error\n", 2);
	else if (error_nmbr == 6)
		ft_putstr_fd("Sigaction error\n", 2);
	exit(EXIT_FAILURE);
}
