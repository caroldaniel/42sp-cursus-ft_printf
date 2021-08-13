/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:59:19 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 22:57:54 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_conversion(t_format *fmt, t_holder *h)
{	
	if (h->conversion == 'c')
		ft_convert_c(fmt, h);
	else if (h->conversion == 's')
		ft_convert_s(fmt, h);
	else if (h->conversion == 'p')
		ft_convert_p(fmt, h);
	else if (h->conversion == 'd' || h->conversion == 'i')
		ft_convert_d_i(fmt, h);
	else if (h->conversion == 'u')
		ft_convert_uxX(fmt, h, DECIMAL_BASE);
	else if (h->conversion == 'x')
		ft_convert_uxX(fmt, h, HEXADECIMAL_L_BASE);
	else if (h->conversion == 'X')
		ft_convert_uxX(fmt, h, HEXADECIMAL_U_BASE);
	else if (h->conversion == '%')
		ft_convert_pct(h);
}
