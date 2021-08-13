/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:16:37 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 21:43:42 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_placeholder(t_format *fmt)
{
	t_holder	*h;

	fmt->i++;
	h = ft_parse(fmt);
	if (h->conversion)
	{
		ft_type_conversion(fmt, h);
		fmt->len += write(1, h->argument, h->len);
		free(h->argument);
	}
	free(h);
}