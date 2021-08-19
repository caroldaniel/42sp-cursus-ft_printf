/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:53:12 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/19 10:52:03 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
*	DESCRIPTION
*	Converts the variadic argument into a single character string, returning it
*	into the holder's 'argument' variable.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_convert_c(t_format *fmt, t_holder *h)
{
	char	ch;
	char	*temp;

	ch = (wint_t)va_arg(fmt->ap, wint_t);
	h->argument = ft_strdup("");
	temp = h->argument;
	h->argument = ft_appendchr(temp, ch);
	free(temp);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, h->padding, h->width);
	else
		ft_fill_right_pad(&h->argument, h->padding, h->width);
	h->len = ft_strlen(h->argument);
}
