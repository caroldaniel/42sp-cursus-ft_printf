/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:23:49 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/11 19:39:37 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	h->argument = ft_strdup(va_arg(fmt->ap, char *));
	h->len = ft_strlen(h->argument);
}