/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 22:06:35 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/22 08:06:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
*	DESCRIPTION
*	Converts the '%' into a single character of its kind.
*	PARAMETERS
*	#1. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

void	ft_convert_pct(t_holder *h)
{
	h->argument = ft_appendchr("", h->conversion);
	if (!h->left_justify)
		ft_fill_left_pad(&h->argument, h->padding, h->width);
	else
		ft_fill_right_pad(&h->argument, ' ', h->width);
	h->len = ft_strlen(h->argument);
}
