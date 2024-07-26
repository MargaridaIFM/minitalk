/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:30:44 by mfrancis          #+#    #+#             */
/*   Updated: 2024/07/26 15:44:08 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/minitalk.h"
#include <minitalk.h>


void	sig_handler(int signum, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;
	

    // malloc(sizeof(char));

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
		ft_putstr_fd("Error sigaction\n", 2);
	while (1)
		pause();
	return (0);
}
// void bin_to_char(int signum, char* c)
// {
// /**
//  * if (signum == SIGUSR1) *c = (*c << 1) | 1;
//  * else if (signum == SIGUSR2) *c <<= 1;
// */
// }

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)signum;
	printf("\nSignal handler function called %d\n", signum);
}

/*
[x] start first
[x] print PID
[] Set up signal handlers for SIGUSR1 and SIGUSR2.
	[] use signation to handle signals asynchronously
	[] struck signation is difinied at signal.h and ist used to work with asynchronously signals.
[] Decode the signals to reconstruct the message.
	[] receive the signal
	[] read 8 bits and put the correspondent letter to a string
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