/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:18:59 by                   #+#    #+#             */
/*   Updated: 2016/01/31 18:37:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_2byte(unsigned int c)
{
	unsigned char byte[2];
	unsigned char printed_byte;

	byte[0] = (c << 26) >> 26;
	byte[1] = ((c >> 6) << 27) >> 27;
	printed_byte = (49280 >> 8) | byte[1];
	write(1, &printed_byte, 1);
	printed_byte = (49280 << 24) >> 24 | byte[0];
	write(1, &printed_byte, 1);
}

void	print_3byte(unsigned int c)
{
	unsigned char byte[3];
	unsigned char printed_byte;

	byte[0] = (c << 26) >> 26;
	byte[1] = ((c >> 6) << 26) >> 26;
	byte[2] = ((c >> 12) << 28) >> 28;
	printed_byte = (14712960 >> 16) | byte[2];
	write(1, &printed_byte, 1);
	printed_byte = (14712960 << 16) >> 24 | byte[1];
	write(1, &printed_byte, 1);
	printed_byte = (14712960 << 24) >> 24 | byte[0];
	write(1, &printed_byte, 1);
}

void	print_4byte(unsigned int c)
{
	unsigned char byte[4];
	unsigned char printed_byte;

	byte[0] = (c << 26) >> 26;
	byte[1] = ((c >> 6) << 26) >> 26;
	byte[2] = ((c >> 12) << 26) >> 26;
	byte[3] = ((c >> 18) << 29) >> 29;
	printed_byte = (4034953344 >> 24) | byte[3];
	write(1, &printed_byte, 1);
	printed_byte = (4034953344 << 8) >> 24 | byte[2];
	write(1, &printed_byte, 1);
	printed_byte = (4034953344 << 16) >> 24 | byte[1];
	write(1, &printed_byte, 1);
	printed_byte = (4034953344 << 24) >> 24 | byte[0];
	write(1, &printed_byte, 1);
}