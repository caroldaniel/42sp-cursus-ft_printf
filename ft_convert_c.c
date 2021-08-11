/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:53:12 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/11 17:28:38 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(t_format *fmt, t_holder *h)
{
	int	c;

	c = va_arg(fmt->ap, int c);
	h->len += 1;
	h->argument = (char *)malloc((h->len + 1) * sizeof(char));
	if (!h->argument)
		h->len -= 1;
	else
	{
		h->argument[0] = c;
		h->argument[h->len] = '\0';		
	}
}
