/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_uxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:41:44 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 22:03:23 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_uxX(t_format *fmt, t_holder *h, char *base)
{
	unsigned int	nbr;
	char			*number;
	
	nbr = (unsigned int)(va_arg(fmt->ap, unsigned int));
	if (!nbr)
		h->argument = ft_strdup("");
	else
	{
		number = ft_uitoa_base((unsigned long)nbr, base);
		h->argument = ft_strdup(number);
		h->len += ft_strlen(h->argument);
	}
	free(number);
}
