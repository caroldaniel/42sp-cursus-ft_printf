/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:10:30 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/19 01:27:41 by cado-car         ###   ########lyon.fr   */
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

# define	HOLDER_CONVERSION "cspdiuxX%o"
# define	HOLDER_ALL_FLAGS "-0# +"
# define	HOLDER_JUSTIFY '-'
# define	HOLDER_PREFIX "# +"
# define	HOLDER_PAD '0'
# define	HOLDER_PRECISION '.'
# define	HOLDER_STAR '*'

# define	OCTAL_BASE "01234567"
# define	DECIMAL_BASE "0123456789"
# define	HEXADECIMAL_U_BASE "0123456789ABCDEF"
# define	HEXADECIMAL_L_BASE "0123456789abcdef"

# define	PTR_HEX_L_PREFIX "0x"
# define	HEX_U_PREFIX "0X"
# define	OCT_PREFIX "0"

typedef enum e_bool { false, true }	t_bool;

typedef struct s_format
{
	const char	*format;
	va_list		ap;
	size_t		i;
	size_t		len;
}			t_format;

typedef struct s_holder
{
	t_bool	left_justify;
	char	*prefix;
	char	padding;
	int		width;
	int		precision;
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
void		*ft_parse(t_format *fmt, t_holder *h);
void		ft_parse_flags(t_format *fmt, t_holder *h);
void		ft_parse_width(t_format *fmt, t_holder *h);
void		ft_parse_precision(t_format *fmt, t_holder *h);
void		ft_parse_conversion(t_format *fmt, t_holder *h);

// Conversions
void		ft_type_conversion(t_format *fmt, t_holder *h);
void		ft_convert_c(t_format *fmt, t_holder *h);
void		ft_convert_s(t_format *fmt, t_holder *h);
void		ft_convert_p(t_format *fmt, t_holder *h);
void		ft_convert_d_i(t_format *fmt, t_holder *h);
void		ft_convert_ux(t_format *fmt, t_holder *h, char *base);
void		ft_convert_pct(t_holder *h, char pct);

#endif