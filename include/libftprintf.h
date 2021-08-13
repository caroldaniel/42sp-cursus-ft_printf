/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:10:30 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 23:14:34 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include <wchar.h>
# include "../libft/libft.h"

# define	HOLDER_CONVERSION "cspdiuxX%"

# define	DECIMAL_BASE "0123456789"
# define	OCTAGONAL_BASE "01234567"
# define	HEXADECIMAL_U_BASE "0123456789ABCDEF"
# define	HEXADECIMAL_L_BASE "0123456789abcdef"

# define	PTR_START "0x"

typedef struct s_format
{
	va_list		ap;
	const char	*format;
	size_t		len;
	size_t		i;
}			t_format;

typedef struct s_holder
{
	char	conversion;
	char	*argument;
	size_t	len;
}			t_holder;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);

// Structs' initialization
t_format	*ft_initialize_format(const char *format, va_list ap);
t_holder	*ft_initialize_holder(void);

// Placeholder
void		ft_placeholder(t_format *fmt);
t_holder	*ft_parse(t_format *fmt);
void		ft_parse_conversion(t_format *fmt, t_holder *h);

// Conversions
void		ft_type_conversion(t_format *fmt, t_holder *h);
void		ft_convert_c(t_format *fmt, t_holder *h);
void		ft_convert_s(t_format *fmt, t_holder *h);
void		ft_convert_p(t_format *fmt, t_holder *h);
void		ft_convert_d_i(t_format *fmt, t_holder *h);
void		ft_convert_ux(t_format *fmt, t_holder *h, char *base);
void		ft_convert_pct(t_holder *h);

#endif