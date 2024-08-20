/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:32:50 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/20 18:22:31 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	byte;

	byte = 0;
	if (argc != 3)
		print_error_and_exit("You need to pass 2 arguments: PID and a message.\n");
	pid = check_pid(argv[1]);
	if (kill(pid, 0) < 0)
		return (ft_printf("Error: Invalid PID\n"));
	while (argv[2][byte])
	{
		char_to_send(argv[2][byte], pid);
		byte++;
	}
	return (0);
}

void	char_to_send(char c, int pid)
{
	static int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
			// ft_printf("envio Sig1\n");
		}
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
	int		pid;
	char	*pid_cpy;

	pid_cpy = pid_str;
	pid = 0;
	if (pid_str[0] == '+' && pid_str[1] != '\0')
		pid_str++;
	if (pid_str[0] == '-')
		print_error_and_exit("Error: PID must be a positive number.\n");
	while (*pid_str)
	{
		if (!ft_isdigit(*pid_str))
			print_error_and_exit("Error: PID must be a number.\n");
		pid_str++;
	}
	pid_str = pid_cpy;
	pid = ft_atoi(pid_str);
	// if (pid > 32768)
	// 	print_error_and_exit("Invalid PID\n");
	return (pid);
}

/*

[x] star in second
[x] static int variable - global variable to control if the signal stoped;
[x]  Takes 2 parametrer
	[x] PID
		[x] Parsing
			[x] check if there are sign + and if after is not empty
			[x] check if the there are no - sign
			[x] check if all is digit
			[x] atoi
			[x] check if the number is <= pid max
	[x] message
[x] clear the signal number with  sigemptyset to prevent error;
[]signal sending:
	[] send the size of the string - Aqui ??
		/ variavel global ? ou reallocation memory in server
	[] enconde the string into bit
		[] SIGUSR1 = '0'
		[] SIGUSR2 = '1'
		[] send the bit using kill ?
[] Synchronization
	[] Ensure the client waits appropriately between sending signals to avoid overwhelming the server.
*/