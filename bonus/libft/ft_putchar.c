/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 23:44:32 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/12 21:44:58 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	LIBRARY
*	#include <stdio.h>
*	DESCRIPTION
*	Writes the character c, cast to an unsigned char, to stdout.
*	PARAMETERS
*	#1. The character's numeric value
*	RETURN VALUES
*	The putchar() function return the character written as an unsigned char cast 
*	to an int or EOF on error
*/

void	ft_putchar(int c)
{
	write(1, &c, 1);
}
