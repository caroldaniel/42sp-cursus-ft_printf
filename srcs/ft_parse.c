/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:38:09 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/11 17:00:18 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_holder	*ft_parse(t_format *fmt)
{
	t_holder	*h;

	h = ft_initialize_holder();
	ft_parse_conversion(fmt, h);
	return (h);
}

void	ft_parse_conversion(t_format *fmt, t_holder *h)
{
	if (ft_strchr(HOLDER_CONVERSION, fmt->format[fmt->i]))
		h->conversion = fmt->format[fmt->i];
	fmt->i++;
}
