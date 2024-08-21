/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:30:44 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/21 19:21:37 by mfrancis         ###   ########.fr       */
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
	//static char	*client_msg;

	// if (!client_msg)
	// 	client_msg = ft_strdup("");  // Initialize the message
	if(signal == SIGUSR1)
		{
			c |= (1 << bits);
	//		ft_printf("char = %d\n", c);
			//bits++;
		}
	
	if(bits++ == 7)
	{
		// ft_printf("Entrou no bits = 8:\n");
		// if(i == 0)
		// {
		// 	ft_printf("%s", client_msg);
		// 	free(client_msg);
		// 	client_msg = NULL;
		// }
		// else 
		// 	add_char_to_msg(i, client_msg);
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
	//bits++;
}
// char *add_char_to_msg(int i, char *client_msg)
// {
// 	char *new_msg;
// 	int len;
	
// 	ft_printf("Entrou no add_char_to_msg:\n");
// 	len = ft_strlen(client_msg);
// 	new_msg = malloc(sizeof(char) * (len + 2));
// 	if(!new_msg)
// 	{
// 		if(client_msg)
// 			free(client_msg);
// 		return NULL;
// 	}
// 	concatenate_char(client_msg, new_msg, i);
// 	printf("%s\n", new_msg);
// 	free(client_msg);
// 	return(new_msg);
// }
// void	concatenate_char(char *src, char *dst, int i)
// {
// 	int j;

// 	j = 0;
// 	while (dst[j])!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// 	{
// 		src[j] = dst[j];
// 		j++;
// 	}
// 	dst[j] = (char)i;
// 	dst[j + 1] = '\0';
// 	printf("%s\n", dst);
// }

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
