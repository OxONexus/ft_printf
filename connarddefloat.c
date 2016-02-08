/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connarddefloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:25:59 by apaget            #+#    #+#             */
/*   Updated: 2016/02/08 16:56:00 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_float_str(t_data *data, va_list *list)
{
	float f;
	char *str;

	f = va_arg(*list, double);
	str = itoa_float(f, data->precision);
	return (str);
}

int		get_len_float( double nb, int precision)
{
	if (nb <= 9 && nb >= -9)
		return (1 + precision);
	else
		return (get_len_float(nb / 10, precision));
}

int		power_float(unsigned long long nb, int x)
{
	if (x == 0)
		return (0);
	while (x > 0)
	{
		nb *= 10;
		x--;
	}
	return ((int)nb);
}

char	*itoa_float(double nb, int precision)
{
	char *str;
	char *tmp;
	char *neg;
	float f;
	char *tmp2;
	long long unsigned int ent;

	str = ft_strnew(get_len_float(nb, precision) + 2);
	tmp2 = str;
	ent = (int)nb;
	if (nb < 0)
	{
		neg = ft_strdup("-");
		ent = (int)-nb;
	}
	else
	neg = ft_strdup("");
	tmp = ft_unsigned_itoa_base(ent, 10, 0);
	ft_strcpy(str, tmp);
	str += ft_strlen(tmp);
	*str = '.';
	if (nb >= 0)
		f = (float)(nb - (float)ent) > 0 ? (nb - (float)ent) : ((float)ent - nb);
	else
		f = (float)(nb + (float)ent) > 0 ? ((float)ent + nb) : -(nb + (float)ent);
	free(tmp);
	ent = power_float(f,precision);
	tmp = ft_unsigned_itoa_base(ent, 10, 0);
	str++;
	ft_strcpy(str, tmp);
	str[ft_strlen(tmp)] = 0;
	return (ft_strjoin(neg,tmp2));
}

