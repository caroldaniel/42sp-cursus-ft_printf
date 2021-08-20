/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:16:37 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/20 19:12:47 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
*	LIBRARY
*	#include <stdio.h>
*	DESCRIPTION
*	The  placeholder() function manages whatever comes after the '%' char in the
*	printf()'s family functions. It calls the initialize() function for the 
*	format struct, as well as the parse() function that will eventually convert
*	the argument passed to the va_list into the holder struct. At the end, it
*	will print to the screen the converted string of the respective argument.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	RETURN VALUES
*	-
*/

void	ft_placeholder(t_format *fmt)
{
	t_holder	*h;

	fmt->i++;
	h = ft_initialize_holder();
	ft_parse(fmt, h);
	if (h->conversion)
	{
		ft_type_conversion(fmt, h);
		fmt->len += write(1, h->argument, h->len);
		free(h->argument);
	}
	free(h->prefix);
	free(h);
}
