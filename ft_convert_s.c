/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:23:49 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/11 17:24:03 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	char 	*s;
	int		len;
	
	s = ft_strdup(va_arg(fmt->ap, char *));
	len = ft_strlen(s);
	h->len += len;
	h->argument = (char *)malloc((h->len + 1) * sizeof(char));
	if (!h->argument)
		h->len -= len;
	else
		ft_strlcpy(h->argument, s, len);
	free(s);
}