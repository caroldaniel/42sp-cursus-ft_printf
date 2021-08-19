/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:26:53 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/19 11:38:08 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	The strdup() function allocates sufficient memory for a copy of the string 
*	s1, up until a 'n' total bytesm, does the copy, and returns a pointer to it.
*	PARAMETERS
*	#1. The string to duplicate.
*	#2. The number of bytes to duplicate
*	RETURN VALUES
*	The strdup() function returns the pointer to the copy of s1.
*/

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	int		size;
	char	*ptr;

	if (!s1)
		return (NULL);
	size = ft_strlen((char *)s1);
	if ((size_t)size > n)
		size = n;
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
