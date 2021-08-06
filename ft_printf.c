/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:33:12 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/04 23:00:20 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <stdio.h>
*	DESCRIPTION
*	The  functions in the printf() family produce output according to a format 
*	as described below.  The functions printf() and vprintf() write output to 
*	stdout, the standard output stream; fprintf() and vf‐printf() write output 
*	to the given output stream; sprintf(), snprintf(), vsprintf() and 
*	vsnprintf() write to the character string str.
*	PARAMETERS
*	#1. The string format in which the output will be printed.
*	... The variadic arguments passed to the format string's placeholders.
*	RETURN VALUES
*	Upon successful return, these functions return the number of characters 
*	printed (excluding the null byte used to end output to strings).
*/

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	
	if (format == NULL)
		return (0);
	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}

int ft_vprintf(const char *format, va_list ap)
{
	t_format	*fmt;
	int			len;
	
	fmt = ft_initialize_format(format, ap);
	while (fmt->format[fmt->i] != '\0')
	{
		if (fmt->format[fmt->i] == '%')
			ft_placeholder(fmt);
		else
		{
			ft_putchar(fmt->format[fmt->i]);
			fmt->i++;
			fmt->len++;
		}
	}	
	len = fmt->len;
	va_end(ap);
	free(ap);
	return (len);
}
