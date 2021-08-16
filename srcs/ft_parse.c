/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:38:09 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/16 19:33:27 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
*	DESCRIPTION
*	The parse() function will take the format string from the index in which the
*	placeholder begins, and will attempt to analyze and organize its flags and 
*	conversors into a struct of type t_holder, using other parsing subfunctions.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	RETURN VALUES
*	it returns the t_holder variable that holds all the information about that
*	particular placeholder.
*/

t_holder	*ft_parse(t_format *fmt)
{
	t_holder	*h;

	h = ft_initialize_holder();
	ft_parse_conversion(fmt, h);
	return (h);
}

void	ft_parse_conversion(t_format *fmt, t_holder *h)
{
	if (ft_strchr(HOLDER_CONVERSION, fmt->format[fmt->i]))
		h->conversion = fmt->format[fmt->i];
	fmt->i++;
}
