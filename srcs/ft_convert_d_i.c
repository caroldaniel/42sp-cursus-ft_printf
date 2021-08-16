/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:22:20 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/16 19:35:46 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
*	DESCRIPTION
*	Converts the variadic argument into a decimal number string, returning it
*	into the holder's 'argument' variable.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_convert_d_i(t_format *fmt, t_holder *h)
{
	char	*number;
	int		arg;

	number = NULL;
	arg = (int)va_arg(fmt->ap, int);
	number = ft_itoa(arg);
	h->argument = ft_strdup(number);
	h->len = ft_strlen(h->argument);
	free(number);
}
