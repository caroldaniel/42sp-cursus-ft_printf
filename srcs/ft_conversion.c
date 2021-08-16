/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:59:19 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/16 19:33:14 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
*	DESCRIPTION
*	Much like a switch case operator, the type_conversion() function takes the
*	format and holder structs that, in that moment, already hold all the 
*	information necessary to perform the placeholder's intended conversion, and
*	orients each one to its specific conversion functions.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_type_conversion(t_format *fmt, t_holder *h)
{	
	if (h->conversion == 'c')
		ft_convert_c(fmt, h);
	else if (h->conversion == 's')
		ft_convert_s(fmt, h);
	else if (h->conversion == 'p')
		ft_convert_p(fmt, h);
	else if (h->conversion == 'd' || h->conversion == 'i')
		ft_convert_d_i(fmt, h);
	else if (h->conversion == 'u')
		ft_convert_ux(fmt, h, DECIMAL_BASE);
	else if (h->conversion == 'x')
		ft_convert_ux(fmt, h, HEXADECIMAL_L_BASE);
	else if (h->conversion == 'X')
		ft_convert_ux(fmt, h, HEXADECIMAL_U_BASE);
	else if (h->conversion == '%')
		ft_convert_pct(h);
}
