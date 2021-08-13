/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:22:20 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 23:13:39 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_d_i(t_format *fmt, t_holder *h)
{
	char	*number;
	int		arg;

	number = NULL;
	arg = (int)va_arg(fmt->ap, int);
	if (!arg)
		h->argument = ft_strdup("");
	else
	{
		number = ft_itoa(arg);
		h->argument = ft_strdup(number);
		h->len = ft_strlen(h->argument);
		free(number);
	}
}
