/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:22:20 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/19 13:08:49 by cado-car         ###   ########lyon.fr   */
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
	int			sign;
	long int	arg;

	sign = 1;
	arg = (int)va_arg(fmt->ap, int);
	if (arg < 0)
	{
		sign *= -1;
		arg *= -1;
	}
	h->argument = ft_itoa(arg);
	if (h->precision > -1)
	{
		ft_fill_left_pad(&h->argument, '0', h->precision);
		h->padding = ' ';
	}
	ft_add_prefix(h, sign);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, h->padding, h->width);
	else
		ft_fill_right_pad(&h->argument, h->padding, h->width);
	h->len = ft_strlen(h->argument);
}
