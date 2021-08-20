/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:59:19 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/20 19:45:59 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static void	ft_prefix_ux(t_holder *h);

/*
*	DESCRIPTION
*	Much like a switch case operator, the type_conversion() function takes the
*	format and holder structs that, in that moment, already hold all the 
*	information necessary to perform the placeholder's intended conversion, and
*	orients each one to its specific conversion functions.
*	PARAMETERS
*	#1. The t_format struct that holds information about the string to be 
*	formatted.
*	#2. The t_holder struct that holds all the information about the placeholder
*	and its flags.
*	RETURN VALUES
*	-
*/

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
		ft_convert_ux(fmt, h, DECIMAL_BASE);
	else if (h->conversion == 'x')
		ft_convert_ux(fmt, h, HEXADECIMAL_L_BASE);
	else if (h->conversion == 'X')
		ft_convert_ux(fmt, h, HEXADECIMAL_U_BASE);
	else if (h->conversion == 'o')
		ft_convert_ux(fmt, h, OCTAL_BASE);
	else
		ft_convert_pct(h);
}

void	ft_fill_left_pad(char **src, char padding, int width)
{
	char	*temp;
	size_t	strlen;
	size_t	padlen;

	strlen = ft_strlen(*src);
	if (!width || width < (int)strlen)
		width = strlen;
	temp = (char *)malloc(width * sizeof(char));
	if (!temp)
		return ;
	padlen = width - strlen;
	ft_memset(temp, padding, padlen);
	temp[padlen] = '\0';
	ft_strlcat(temp, *src, width + 1);
	free(*src);
	*src = temp;
}

void	ft_fill_right_pad(char **src, char padding, int width)
{
	char	*temp;
	size_t	strlen;
	size_t	padlen;

	strlen = ft_strlen(*src);
	if (!width || width < (int)strlen)
		width = strlen;
	temp = (char *)malloc(width * sizeof(char));
	if (!temp)
		return ;
	ft_strlcpy(temp, *src, strlen + 1);
	padlen = width - strlen;
	ft_memset(&temp[strlen], padding, padlen);
	temp[width] = '\0';
	free(*src);
	*src = temp;
}

void	ft_add_prefix(t_holder	*h, int sign)
{
	int	len;

	len = (int)ft_strlen(h->argument);
	if (h->conversion == 'd' || h->conversion == 'i')
	{
		len += 1;
		if (ft_strchr(h->prefix, PLUS) && sign == 1)
			ft_fill_left_pad(&h->argument, PLUS, len);
		else if (ft_strchr(h->prefix, SPACE) && sign == 1)
			ft_fill_left_pad(&h->argument, SPACE, len);
		else if (sign == -1)
			ft_fill_left_pad(&h->argument, MINUS, len);
	}
	else if (h->conversion == 'x' || h->conversion == 'X' \
			|| h->conversion == 'o')
		ft_prefix_ux(h);
}

static void	ft_prefix_ux(t_holder *h)
{
	char	*temp;

	temp = h->argument;
	if (ft_strchr(h->prefix, '#'))
	{
		if (h->conversion == 'x')
			h->argument = ft_strjoin(PTR_HEX_L_PREFIX, temp);
		if (h->conversion == 'X')
			h->argument = ft_strjoin(HEX_U_PREFIX, temp);
		if (h->conversion == 'o')
			h->argument = ft_strjoin(OCT_PREFIX, temp);
		free(temp);
	}
}
