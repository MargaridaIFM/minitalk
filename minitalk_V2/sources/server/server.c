/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:30:44 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/22 16:30:15 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"


int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
		pause();
	return (0);
}

void	ft_sig_handler(int signal)
{
	static int	c = 0;
	static int	bits = 0;

	if(signal == SIGUSR1)
			c |= (1 << bits);
	if(bits++ == 7)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
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

/*catenate_char(char *src, char *dst, int i)

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
