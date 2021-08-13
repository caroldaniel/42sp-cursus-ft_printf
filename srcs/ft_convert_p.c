/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:39:08 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 23:10:20 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_p(t_format *fmt, t_holder *h)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = (void *)va_arg(fmt->ap, void *);
	if (!ptr)
		h->argument = ft_strdup("");
	else
	{
		number = ft_uitoa_base((unsigned long)ptr, HEXADECIMAL_L_BASE);
		h->argument = ft_strjoin(PTR_START, number);
		h->len += ft_strlen(h->argument);
		free(number);
	}
}
