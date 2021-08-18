/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:39:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/17 08:05:11 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		h->argument = ft_strdup("0x0");
	else
	{
		number = ft_uitoa_base((unsigned long)ptr, HEXADECIMAL_L_BASE);
		h->argument = ft_strjoin(PTR_HEX_L_PREFIX, number);
		free(number);
	}
	h->len += ft_strlen(h->argument);
}
