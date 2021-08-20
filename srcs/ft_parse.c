/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:38:09 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/20 19:46:37 by cado-car         ###   ########lyon.fr   */
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

#include <stdio.h>

void	*ft_parse(t_format *fmt, t_holder *h)
{
	ft_parse_flags(fmt, h);
	ft_parse_width(fmt, h);
	ft_parse_precision(fmt, h);
	ft_parse_conversion(fmt, h);
	if (!h->conversion && (ft_strchr(HOLDER_ALL, fmt->format[fmt->i])))
		ft_parse(fmt, h);
	return (h);
}

void	ft_parse_flags(t_format *fmt, t_holder *h)
{
	char	*temp;

	if (!h->prefix)
		h->prefix = ft_strdup("");
	while (ft_strchr(HOLDER_ALL_FLAGS, fmt->format[fmt->i]))
	{
		if (fmt->format[fmt->i] == HOLDER_JUSTIFY)
			h->left_justify = 1;
		if (ft_strchr(HOLDER_PREFIX, fmt->format[fmt->i]))
		{
			temp = h->prefix;
			h->prefix = ft_appendchr(temp, fmt->format[fmt->i]);
			free(temp);
		}
		if (fmt->format[fmt->i] == HOLDER_PAD)
			h->padding = HOLDER_PAD;
		fmt->i++;
	}
}

void	ft_parse_width(t_format *fmt, t_holder *h)
{
	int	width;

	width = h->width;
	if (fmt->format[fmt->i] == HOLDER_STAR)
	{
		width = (int)va_arg(fmt->ap, int);
		if (width < 0)
		{
			h->left_justify = 1;
			width *= -1;
		}
		fmt->i++;
	}
	else if (ft_isdigit(fmt->format[fmt->i]))
	{
		width = 0;
		while (ft_isdigit(fmt->format[fmt->i]))
		{
			width = (width * 10) + (fmt->format[fmt->i] - '0');
			fmt->i++;
		}
	}
	h->width = width;
}

void	ft_parse_precision(t_format *fmt, t_holder *h)
{
	int	precision;

	precision = h->precision;
	if (fmt->format[fmt->i] == HOLDER_PRECISION)
	{
		fmt->i++;
		if (fmt->format[fmt->i] == HOLDER_STAR)
		{
			precision = (int)va_arg(fmt->ap, int);
			fmt->i++;
		}
		else if (!ft_isdigit(fmt->format[fmt->i]))
			precision = 0;
		else
		{
			precision = 0;
			while (ft_isdigit(fmt->format[fmt->i]))
			{
				precision = (precision * 10) + (fmt->format[fmt->i] - '0');
				fmt->i++;
			}
		}
	}
	h->precision = precision;
}

void	ft_parse_conversion(t_format *fmt, t_holder *h)
{
	if (!ft_strchr(HOLDER_ALL, fmt->format[fmt->i]) \
		&& ft_isprint(fmt->format[fmt->i]))
	{
		h->conversion = fmt->format[fmt->i];
		fmt->i++;
	}
}
