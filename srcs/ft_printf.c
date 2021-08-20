/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:33:12 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/20 11:58:01 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
*	LIBRARY
*	#include <stdio.h>
*	DESCRIPTION
*	The  functions in the printf() family produce output according to a format 
*	as described below.  The functions printf() and vprintf() write output to 
*	stdout, the standard output stream. 
*	PARAMETERS
*	#1. The string format in which the output will be printed.
*	... The variadic arguments passed to the format string's placeholders. In 
*	the vprintf() function, the variadic argument are already passed as a 
*	va_list type.
*	RETURN VALUES
*	Upon successful return, these functions return the number of characters 
*	printed (excluding the null byte used to end output to strings).
*/

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int	ft_vprintf(const char *format, va_list ap)
{
	t_format	*fmt;
	int			len;

	fmt = ft_initialize_format(format, ap);
	if (!fmt)
		return (0);
	while (fmt->format[fmt->i])
	{
		if (fmt->format[fmt->i] == '%')
			ft_placeholder(fmt);
		else
			fmt->len += write(1, &fmt->format[fmt->i++], 1);
	}	
	len = fmt->len;
	free(fmt);
	return (len);
}
