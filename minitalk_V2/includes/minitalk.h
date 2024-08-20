/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:17:25 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/20 18:19:13 by mfrancis         ###   ########.fr       */
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
void char_to_send(char c, int pid);
void	print_error_and_exit(char *message);
int	check_pid(char *pid_str);


// server
void	sig_handler(int signal, siginfo_t *info, void *context);
char *add_char_to_msg(int i, char *client_msg);
void	concatenate_char(char *src, char *dst, int i);


// cliente_bonus

// server_bonus

#endif