/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:32:50 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/05 12:48:27 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

static int	control_reception;

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					pid;
	int					byte;

    byte = 0;
	if (argc != 3)
		print_error_and_exit("You need to pass 2 arguments: PID and a message.\n");
	pid = check_pid(argv[1]);
	//ft_printf("PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa,
			NULL) == - 1)
		print_error_and_exit("Error sisgnation\n");
	while (argv[2][byte])
	{
		ft_printf("While antes da conversao %d:\n", byte);
        char_to_binary(argv[2][byte], pid);
        byte++;
	
	}
    char_to_binary('\0', pid);
	return (0);
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

void	print_error_and_exit(char *message)
{
	ft_putstr_fd(message, 2);
	exit(1);
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	idx;

	(void)context;
	(void)info;
	control_reception = 1;
	idx = 0;
	if (signum == SIGUSR2)
		idx++;
	else if (signum == SIGUSR1)
		ft_printf("Num of bytes: %d\n", idx / 8);
}

int	char_to_binary(char c, int pid)
{
    int idx;
	int bit_idx;
	
	bit_idx = 7;
	ft_printf("Char: %c\n", c);
	ft_printf("bit_idx fora: %d\n", bit_idx);
	
	while(bit_idx >= 0)
	{
		ft_printf("bit_idx dentro loop: %d\n", bit_idx);
		idx = 0;
		
		if((c >> bit_idx) & 1)
		{
			kill(pid, SIGUSR1);
			ft_printf("envio Sig1\n");
		}
		else
		{
			kill(pid, SIGUSR2);
			ft_printf("envio Sig2\n");
		}
		while(control_reception == 0)
		{
			if(idx == 50)
			{
				print_error_and_exit("Error: No response from the process.\n");
			}
			idx++;
			usleep(100);
		}
		control_reception = 0;
		bit_idx--;
	}
	return(0);
}
/*
int	get_pid_max(void) {
	FILE *fp;
	char *line = NULL;
	int pid_max;

	fp = popen("at /proc/sys/kernel/pid_max"c, "r");
	if (fp == NULL) {
		perror("Erro ao abrir o pipe");
		exit(EXIT_FAILURE);
	}

	// Lê uma linha da saída do comando usando get_next_line
	if (get_next_line(fp, &line) == 0) {
		perror("Erro ao ler o valor de pid_max");
		pclose(fp);
		free(line);
		exit(EXIT_FAILURE);
	}

	// Fecha o pipe
	pclose(fp);

	// Converte a string lida para um inteiro
	pid_max = atoi(line);

	// Libera a memória alocada para a linha
	free(line);

	return (pid_max);
}

*/
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