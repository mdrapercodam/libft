/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdraper <mdraper@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 12:45:41 by mdraper       #+#    #+#                 */
/*   Updated: 2024/05/01 16:14:26 by mdraper       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(char recieved_char, int bit_index)
{
	int	i;

	i = bit_index - 1;
	while (i >= 0)
	{
		ft_printf("%d", (recieved_char >> i) & 1);
		i--;
	}
	ft_printf("\n");
}

void	ft_send_signal_to_client(pid_t client_pid, int signal)
{
	if (signal == 0)
	{
		if (kill(client_pid, SIGUSR1) == -1)
			ft_minitalk_errors(4);
	}
	else if (signal == 1)
	{
		if (kill(client_pid, SIGUSR2) == -1)
			ft_minitalk_errors(4);
	}
	else
		ft_minitalk_errors(2);
}

char	ft_signal_to_bit(int sig)
{
	char	bit;

	bit = 0;
	if (sig == SIGUSR1)
		bit = 0;
	else if (sig == SIGUSR2)
		bit = 1;
	else
		ft_minitalk_errors(3);
	return (bit);
}

void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid = 0;
	static char		recieved_char = 0;
	static int		bit_index = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		bit_index = 0;
		recieved_char = 0;
		client_pid = info->si_pid;
	}
	bit_index++;
	recieved_char = (recieved_char << 1) | ft_signal_to_bit(sig);
	if (bit_index == 8)
	{
		ft_printf("%c", recieved_char);
		if (recieved_char == '\0')
			ft_send_signal_to_client(client_pid, 1);
		bit_index = 0;
		recieved_char = 0;
	}
	ft_send_signal_to_client(client_pid, 0);
}

int	ft_server_minitalk(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = ft_signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_minitalk_errors(6);
	else if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_minitalk_errors(6);
	while (1)
		pause();
	return (0);
}
