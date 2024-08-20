/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:30:44 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/20 18:11:58 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"


int	main(void)
{
	struct sigaction	sa;
	
	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
		ft_putstr_fd("Error sigaction\n", 2);
	while (1)
		pause();
	return (0);
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static int	bits;
	static char	*client_msg;

	(void)info;
	(void)context;

	if (!client_msg)
		client_msg = ft_strdup("");  // Initialize the message
	if(signal == SIGUSR1)
		i |= 1 << bits;
	bits++;
	if(bits == 8)
	{
		if(i == 0)
		{
			ft_printf("%s", client_msg);
			free(client_msg);
			client_msg = NULL;
		}
		else 
			add_char_to_msg(i, client_msg);
		bits = 0;
		i = 0;
	}
}
char *add_char_to_msg(int i, char *client_msg)
{
	char *new_msg;
	int len;
	
	len = ft_strlen(client_msg);
	new_msg = malloc(sizeof(char) * (len + 1));
	if(!new_msg)
	{
		if(client_msg)
			free(client_msg);
		return NULL;
	}
	concatenate_char(client_msg, new_msg, i);
	free(client_msg);
	return(new_msg);
}
void	concatenate_char(char *src, char *dst, int i)
{
	int j;

	j = 0;
	while (dst[j])
	{
		src[j] = dst[j];
		j++;
	}
	dst[j] = (char)i;
	dst[j + 1] = '\0';
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
