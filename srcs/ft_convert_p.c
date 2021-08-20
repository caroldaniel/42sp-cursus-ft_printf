/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:39:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/20 19:46:15 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static char	*ft_nullset(t_holder *h);

/*
*	DESCRIPTION
*	Converts the variadic argument into a string representing its pointer
*	location in hexadecimal value, returning it into the holder's 'argument' 
*	variable.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_convert_p(t_format *fmt, t_holder *h)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		number = ft_nullset(h);
	else
		number = ft_uitoa_base((unsigned long)ptr, HEXADECIMAL_L_BASE);
	h->argument = ft_strjoin(PTR_HEX_L_PREFIX, number);
	free(number);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, ' ', h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
}

static char	*ft_nullset(t_holder *h)
{
	char	*number;

	if (h->precision > -1)
	{
		number = (char *)malloc((h->precision + 1) * sizeof(char));
		if (!number)
			return (NULL);
		ft_memset(number, '0', (size_t)h->precision);
		number[h->precision] = '\0';
	}
	else
		number = ft_strdup("0");
	return (number);
}
