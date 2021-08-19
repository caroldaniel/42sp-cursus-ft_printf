/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:22:20 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/19 14:59:15 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static void	ft_convert_d_i_width(t_holder *h, int sign);

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
		h->argument = ft_uitoa_base(-arg, DECIMAL_BASE);
	}
	else
		h->argument = ft_uitoa_base(arg, DECIMAL_BASE);
	if (h->precision > -1)
	{
		ft_fill_left_pad(&h->argument, '0', h->precision);
		h->padding = ' ';
	}
	ft_convert_d_i_width(h, sign);
	h->len = ft_strlen(h->argument);
}

static void	ft_convert_d_i_width(t_holder *h, int sign)
{
	if (h->padding == '0')
	{
		if (!h->left_justify)
			ft_fill_left_pad(&h->argument, h->padding, h->width);
		else
			ft_fill_right_pad(&h->argument, ' ', h->width);	
		if (sign == 0)
			h->argument[0] = '-';
		if (ft_strchr(h->prefix, '+'))
			h->argument[0] = '+';
		if (ft_strchr(h->prefix, ' '))
			h->argument[0] = ' ';
	}
	else if (h->padding == ' ')
	{
		ft_add_prefix(h, sign);
		if (!h->left_justify)
			ft_fill_left_pad(&h->argument, h->padding, h->width);
		else
			ft_fill_right_pad(&h->argument, ' ', h->width);	
	}
}
