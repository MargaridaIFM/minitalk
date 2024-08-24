/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:32:50 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/22 18:41:26 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	byte;

	byte = 0;
	if (argc != 3)
		print_error_and_exit(
			"You need to pass 2 arguments: PID and a message.\n");
	pid = check_pid(argv[1]);
	if (pid <= 0)
		return (ft_printf("Error: Invalid PID\n"));
	while (argv[2][byte])
	{
		char_to_send(argv[2][byte], pid);
		byte++;
	}
	return (0);
}

void	char_to_send(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

void	print_error_and_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

int	check_pid(char *pid_str)
{
	int	pid;
	int	i;

	pid = 0;
	i = 0;
	while (pid_str[i])
	{
		if (!ft_isdigit(pid_str[i]))
			print_error_and_exit("Error: PID must be just numbers.\n");
		i++;
	}
	pid = ft_atoi(pid_str);
	return (pid);
}

/* in main:
		char_to_send('\0', pid);
*/
/*
[x] star in second
[x]  Takes 2 parametrer
	[x] PID
		[x] Parsing
			[x] check if all is digit
			[x] atoi
	[x] message
[]signal sending:
	[] enconde the string into bit
		[] SIGUSR1 = '1'
		[] SIGUSR2 = increment the bits
		[] send the bit using kill
[] Synchronization
	[] Ensure the client waits appropriately between sending signals
		to avoid overwhelming the server.
*/