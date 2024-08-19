/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:17:25 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/05 12:36:56 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libraries/libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

// client

int		check_pid(char *pid_str);
void	print_error_and_exit(char *message);
void	sig_handler(int signum, siginfo_t *info, void *context);
int		char_to_binary(char c, int pid);

// server
void	sig_handler(int signum, siginfo_t *info, void *context);
void	binary_to_char(int signum, unsigned char* c);
char	*add_char_to_msg(char c, char *client_msg);

// cliente_bonus

// server_bonus

#endif