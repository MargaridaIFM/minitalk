/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:32:50 by mfrancis          #+#    #+#             */
/*   Updated: 2024/07/23 00:42:46 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int main(int argc, char *argv[])
{
 (void) argc;
 (void) argv;
}

/*

[] star in second
[] static int variable - global variable here ?
[]  Takes 2 parametrer
    [] PARSING 
        [] PID
        [] message
    []signal sending:
        [] send the size of the string - Aqui ?? / variavel global ? ou reallocation memory in server
        [] enconde the string into bit
            [] SIGUSR1 = '0'
            [] SIGUSR2 = '1'
            [] send the bit using kill ?
    [] Synchronization
        [] Ensure the client waits appropriately between sending signals to avoid overwhelming the server.
*/