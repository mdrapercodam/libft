/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/12 12:02:45 by mdraper       #+#    #+#                 */
/*   Updated: 2024/05/01 16:14:16 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	g_signal_server = 0;

void	ft_signal_server_received(int sig)
{
	if (sig == SIGUSR1)
		g_signal_server = 1;
	else if (sig == SIGUSR2)
		ft_printf("Every character printed!\n");
	else
		ft_minitalk_errors(3);
}

void	ft_waiting_for_signal(void)
{
	int	timeout_counter;

	timeout_counter = 0;
	while (!g_signal_server && timeout_counter < 10000)
	{
		usleep(10);
		timeout_counter++;
	}
	if (timeout_counter >= 10000)
		ft_minitalk_errors(5);
	g_signal_server = 0;
}

void	ft_send_bit(pid_t server_pid, int bit)
{
	int	temp;

	if (bit == 0)
		temp = kill(server_pid, SIGUSR1);
	else
		temp = kill(server_pid, SIGUSR2);
	if (temp == -1)
		ft_minitalk_errors(4);
}

void	ft_send_character(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		ft_send_bit(server_pid, (c >> i) & 1);
		ft_waiting_for_signal();
		usleep(42);
		i--;
	}
}

int	ft_client_minitalk(int argc, char *argv[])
{
	struct sigaction	sa;
	pid_t				server_pid;
	int					str_len;
	int					i;

	if (argc != 3)
		ft_minitalk_errors(1);
	if (ft_check_string(argv[1]) == -1)
		ft_minitalk_errors(2);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		ft_minitalk_errors(2);
	sa.sa_handler = ft_signal_server_received;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_minitalk_errors(6);
	else if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_minitalk_errors(6);
	i = 0;
	str_len = ft_strlen(argv[2]);
	while (i < str_len)
		ft_send_character(server_pid, argv[2][i++]);
	ft_send_character(server_pid, '\0');
	return (0);
}
