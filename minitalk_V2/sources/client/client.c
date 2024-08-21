/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:32:50 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/21 19:18:03 by mfrancis         ###   ########.fr       */
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
	if (pid <= 0)
		return (ft_printf("Error: Invalid PID\n"));
	while (argv[2][byte])
	{
//		ft_printf("Entrou no while do client:\n");
		char_to_send(argv[2][byte], pid);
		byte++;
	}
	return (0);
}

void	char_to_send(unsigned char c, int pid)
{
	int	bit;
//	ft_printf("char: %c\n", c);

	bit = 0;
	while (bit <= 7)
	{
//		ft_printf("Entrou no loop bits:\n");
//		ft_printf("%d\n", bit);
		if (c & (1 << bit))
		{
			kill(pid, SIGUSR1);
//			ft_printf("envio Sig1\n");
		}
		else
		{
			kill(pid, SIGUSR2);
//			ft_printf("envio Sig2\n");
		}
		//c = c >> 1;
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
	int		pid;
	int i;

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