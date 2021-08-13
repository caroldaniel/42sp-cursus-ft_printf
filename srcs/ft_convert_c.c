/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:53:12 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 23:13:36 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_c(t_format *fmt, t_holder *h)
{
	h->len += 1;
	h->argument = (char *)malloc(h->len * sizeof(char));
	if (!h->argument)
		h->len -= 1;
	else
		h->argument[0] = (wint_t)va_arg(fmt->ap, wint_t);
}
