/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:16:37 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/04 22:55:11 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_placeholder(t_format *fmt)
{
	t_holder	*h;

	if (!fmt)
		return ;
	fmt->i++;
	h = ft_parse(fmt);
	if (h->argument)
	{
		ft_type_conversion(fmt, h);
		fmt->len += write(1, h->argument, h->len);
		free(h->argument);
	}
	free(h);
}