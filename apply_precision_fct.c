/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_fct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 01:25:17 by apaget            #+#    #+#             */
/*   Updated: 2016/02/08 17:14:46 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_precision(t_data *data, char *str)
{
	int		length;

	length = ft_strlen(str);
	if (*str == '-' && isintab("diD", data->type))
		length--;
	if (data->type == 'p')
		return (apply_ptr_precision(data, str));
	else if (data->precision != -1 && data->precision < length
			&& data->type == 's')
		return (apply_string_precision(data, str));
	else if (data->precision > length && data->type != 's'
			&& data->type != 'c')
		return (apply_nbr_precision(data, str));
	else if (data->precision == 0 && ft_atoi(str) == 0)
		return (ft_strdup(""));
	return (str);
}

char	*apply_ptr_precision(t_data *data, char *str)
{
	char	*tmp;
	char	*ox;
	int		len;

	ox = ft_strnew(2);
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
	{
		*ox = '0';
		ox[1] = *(str + 1);
		str += 2;
	}
	len = ft_strlen(str);
	if (data->precision > len)
	{
		tmp = ft_strnew(data->precision);
		ft_memset(tmp, '0', data->precision);
		ft_strcpy(tmp + data->precision - ft_strlen(str), str);
		return (ft_strjoin(ox, tmp));
	}
	else if (data->precision == 0)
		return (ox);
	free(ox);
	return (str - 2);
}

char	*apply_string_precision(t_data *data, char *str)
{
	char *tmp;

	tmp = ft_strnew(data->precision);
	ft_memcpy(tmp, str, data->precision);
	return (tmp);
}

char	*apply_nbr_precision(t_data *data, char *str)
{
	char	*new;
	char	*tmp;
	char	*result;
	int		length;

	if (*str == '-')
	{
		tmp = ft_strdup("-");
		str++;
	}
	else
		tmp = ft_strdup("");
	length = ft_strlen(str);
	new = ft_strnew(data->precision);
	ft_memset(new, '0', data->precision);
	ft_memcpy(new + data->precision - length, str, length);
	result = ft_strjoin(tmp, new);
	free(tmp);
	free(new);
	return (result);
}
