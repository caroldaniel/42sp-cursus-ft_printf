/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:59:03 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 19:05:46 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	The uitoa_base() converts an unsigned interger into a string, passing it to 
*	the base given as an argument.
*	PARAMETERS
*	#1. The unsigned long to convert.
*	#2. The base in which to convert the number to.
*	RETURN VALUES
*	The string representing the converted number.  
*/

#include "libft.h"

int		ft_countsize(unsigned long n, int len_base);
void	ft_convbase(unsigned long nbr, char *number, char *base, long i);

char	*ft_uitoa_base(unsigned long nbr, char *base)
{
	int		len_nbr;
	int		len_base;
	char	*number;
	
	len_base = ft_strlen(base);
	len_nbr = ft_countsize(nbr, len_base);
	number = malloc((len_nbr + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len_nbr--] = '\0';
	ft_convbase(nbr, number, base, len_nbr);
	return (number);
}

// recursively count long size
int	ft_countsize(unsigned long n, int len_base)
{
	if ((n / len_base) == 0)
		return (1);
	else
		return (1 + ft_countsize(n / len_base, len_base));
}

// recursively convert long to string
void	ft_convbase(unsigned long nbr, char *number, char *base, long i)
{
	if (nbr >= 16)
		ft_convbase((nbr / 16), number, base, (i - 1));
	number[i] = base[nbr % 16];
}
