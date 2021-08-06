/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:10:30 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/04 23:04:41 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
// # include "libft.h"

# define	HOLDER_CONVERSION "cspdiuxX%"

# define	DECIMAL_BASE "0123456789"
# define	OCTAGONAL_BASE "01234567"
# define	HEXAGONAL_U_BASE "0123456789ABCDEF"
# define	HEXAGONAL_L_BASE "0123456789abcdef"

typedef	struct s_format
{
	va_list	ap;
	char	*format;
	size_t	len;
	size_t	i;
}			t_format;

typedef	struct s_holder
{
	char	conversion;
	char	*argument;
	size_t	len;
}			t_holder;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);

// initialize the format struct
t_format	*ft_initialize_format(char *format, va_list ap);
t_holder	*ft_initialize_holder(t_holder *h);
// deal with the placeholder's flags and conversions
void		ft_placeholder(t_format *fmt);
void		ft_print_conversion(t_format *fmt, t_holder *h);
t_holder	*ft_parse(t_format *fmt);
void		ft_parse_conv(t_format *fmt, t_holder *h);
void		ft_type_conversion(t_format *fmt, t_holder *h);

void		ft_putchar (char c);
char		*ft_strchr(const char *s, int c);

#endif