/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:56:02 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/22 18:17:08 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Count the size of the string and return that number */
size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* #include <ctype.h>
int	main(void)
{
	char *str;
	str = NULL;
	printf("my: %lu\n", ft_strlen(str));
	printf("original: %lu\n\n", strlen(str));
} */