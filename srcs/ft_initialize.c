/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:26:01 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/20 19:46:32 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	FT_INITIALIZE_FORMAT
*	--------------------
*	DESCRIPTION
*	Initialize the format struct with the string given and the va_list variable,
*	setting the initial values of len and the counter i to 0.
*	PARAMETERS
*	#1. The string format in which the output will be printed.
*	#2. The variadic arguments list
*	RETURN VALUES
*	The new, inilialized variable struct format.
*	
*	FT_INITIALIZE_HOLDER
*	--------------------
*	DESCRIPTION
*	Initialize the holder struct that will retain the information of the 
*	placeholders flags and conversions. For the mandatory part, that means only 
*	the conversion variable.
*	PARAMETERS
*	-
*	RETURN VALUES
*	The new, inilialized variable struct holder.

*/

#include "libftprintf.h"

t_format	*ft_initialize_format(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (NULL);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->len = 0;
	return (fmt);
}

t_holder	*ft_initialize_holder(void)
{
	t_holder	*h;

	h = malloc(sizeof(t_holder));
	if (!h)
		return (NULL);
	h->left_justify = 0;
	h->prefix = ft_strdup("");
	h->padding = ' ';
	h->width = 0;
	h->precision = -1;
	h->conversion = '\0';
	h->argument = NULL;
	h->len = 0;
	return (h);
}
