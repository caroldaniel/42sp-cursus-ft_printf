/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:23:49 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 23:13:49 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(t_format *fmt, t_holder *h)
{
	char	*s;

	s = ft_strdup(va_arg(fmt->ap, char *));
	if (!s)
		s = ft_strdup("");
	h->len = ft_strlen(s);
	h->argument = (char *)malloc((h->len + 1) * sizeof(char));
	if (h->argument)
		ft_strlcpy(h->argument, s, h->len + 1);
	free(s);
}
