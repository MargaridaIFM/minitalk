/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:30:44 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/22 18:15:10 by mfrancis         ###   ########.fr       */
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

	if (signal == SIGUSR1)
		c |= (1 << bits);
	if (bits++ == 7)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}
/* void	ft_sig_handler(int signal)
{
	static int	c;
	static int	bits;
	static char	*client_msg;

	if (!client_msg)
		client_msg = ft_strdup("");
	if (signal == SIGUSR1)
	{
		c |= (1 << bits);
	}
	if (bits++ == 7)
	{
		if (c)
			client_msg = add_char_to_msg(c, client_msg);
		else if(c =='\0')
		{
			ft_printf("%s\n", client_msg);
			free(client_msg);
			client_msg = NULL;
		}
		bits = 0;
		c = 0;
	}
}
char	*add_char_to_msg(int c, char *client_msg)
{
	char	*new_msg;
	size_t	len;

	len = ft_strlen(client_msg);
	new_msg = malloc(sizeof(char) * (len + 2));
	if (!new_msg)
	{
		if (client_msg)
			free(client_msg);
		return (NULL);
	}
	ft_strlcpy(new_msg, client_msg, len + 1);
	new_msg[len] = (char)c;
	new_msg[len + 1] = '\0';
	free(client_msg);
	return (new_msg);
} */
/*
[x] start first
[x] print PID
[x] Set up signal handlers for SIGUSR1 and SIGUSR2.
	[x] use signalto handle signals
[x] Decode the signals to reconstruct the message.
	[x] receive the signal
	[x] read 8 bits and put the correspondent letter to a string
*/