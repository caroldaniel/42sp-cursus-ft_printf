/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:23:49 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/16 19:37:49 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
*	DESCRIPTION
*	Converts the variadic argument into a full string, returning it into the 
*	holder's 'argument' variable.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	char	*s;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("(null)");
	h->len = ft_strlen(s);
	h->argument = (char *)malloc((h->len + 1) * sizeof(char));
	if (h->argument)
		ft_strlcpy(h->argument, s, h->len + 1);
	free(s);
}
