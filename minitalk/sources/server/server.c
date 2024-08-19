/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:30:44 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/05 14:49:04 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"



// void	sig_handler(int signum, siginfo_t *info, void *context);
// void bin_to_char(int signum, char* c);
// char *add_char_to_msg(char c, char *client_msg);

int	main(void)
{
	struct sigaction	sa;
	
	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
		ft_putstr_fd("Error sigaction\n", 2);
	while (1)
		pause();
	return (0);
}
void binary_to_char(int signum, unsigned char *c)
{
	ft_printf("entrou no binary to char:\n");
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2) 
		*c <<= 1;
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	ft_printf("entrou no sig_handler:\n");
	static int bits;
	static unsigned char c;
	static int pid_client;
	static char *client_msg;

	(void)context;
	bits = 0;
	pid_client = info->si_pid;
	binary_to_char(signum, &c);
	ft_printf("saiu no binary to char:\n");
	bits++;
	ft_printf("bits: %d\n", bits);
	if(bits == 8)
	{
		ft_printf("entrou no loop:\n");
		if(c)
		{
			client_msg = add_char_to_msg(c, client_msg);
			//ft_printf("%s\n", client_msg);			
		}
		else if(client_msg)
		{
			ft_printf("%s\n", client_msg);
			kill(pid_client, SIGUSR1);
			//pid_client = 0;
			free(client_msg);
			client_msg = NULL;
			return ;
		}
		bits = 0;
		c = 0;
	}
	kill(pid_client, SIGUSR2);
}
char *add_char_to_msg(char c, char *client_msg)
{
	char *new_msg;
	size_t len;
	
	len = ft_strlen(client_msg);
	new_msg = malloc(sizeof(char) * (len + 2));
	if(!new_msg)
	{
		if(client_msg)
			free(client_msg);
		return NULL;
	}
	ft_strlcpy(new_msg, &c, len + 2); 
	free(client_msg);
	return(new_msg);
}

/*
[x] start first
[x] print PID
[x] Set up signal handlers for SIGUSR1 and SIGUSR2.
	[x] use signation to handle signals asynchronously
	[x] struck signation is difinied at signal.h and ist used to work with asynchronously signals.
[x] Decode the signals to reconstruct the message.
	[x] receive the signal
	[x] read 8 bits and put the correspondent letter to a string
*/

/*
BONUS
[] send a signal back to client afer receive the message
[] Unicode Support: Handle Unicode characters in the communication ??
*/

/*
GLOBAL:
[] 2 process running on the operating system
	Process - instance of a computer program that is being executed;
[] Process ID for each process

*/
