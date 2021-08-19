/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:12:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/19 10:50:31 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a new string, which is the result of 
*	the concatenation of ’s’ and the char ’c’.
*	PARAMETERS
*	#1. The prefix string.
*	#2. The suffix char.
*	RETURN VALUES
*	The new string. NULL if the allocation fails.
*/

char	*ft_appendchr(char const *s, char const c)
{
	char	*ccat;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ccat = (char *)malloc((len + 2) * sizeof(char));
	if (!ccat)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ccat[i] = s[i];
		i++;
	}
	ccat[i++] = c;
	ccat[i] = '\0';
	return (ccat);
}
