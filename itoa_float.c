/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:39:14 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 03:56:14 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

int		get_len_float( float nb, int precision)
{
	if (nb < 9)
		return (1 + precision);
	else
		return (get_len_float(nb / 10, precision));
}

char	*itoa_float(float nb, int precision)
{
	char *str;

	str = ft_strnew(get_len_float(nb, precision) + 2);
}
