/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:38:09 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/04 22:50:10 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_holder	*ft_parse(t_format *fmt)
{
	t_holder	*h;

	h = ft_initialize_holder(h);
	ft_parse_conv(fmt, h);
	return (h);
}

void	ft_parse_conv(t_format *fmt, t_holder *h)
{
	if (!fmt || !h)
		return ;
	if (ft_strchr(HOLDER_CONVERSION, fmt->format[fmt->i]))
		{
			h->conversion = fmt->format[fmt->i];
			fmt->i++;
		}
}
