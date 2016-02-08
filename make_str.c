/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 02:32:57 by apaget            #+#    #+#             */
/*   Updated: 2016/02/08 15:27:53 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "ft_printf.h"

long long int	cast_number(t_data *data, long long int cast)
{
	if (data->type == 'D')
		cast = (long long)cast;
	else if (data->modificateur == LL)
		cast = (long long)cast;
	else if (data->modificateur == 'l')
		cast = (long)cast;
	else if (data->modificateur == 'h')
		cast = (short)cast;
	else if (data->modificateur == HH)
		cast = (char)cast;
	else if (data->modificateur == 'z')
		cast = (size_t)cast;
	else if (data->modificateur == 'j')
		cast = (long long)cast;
	else
		cast = (int)cast;
	return (cast);
}

int				print_value_of_data(t_data *data, va_list *list)
{
	if (data->type != 'S' && data->type != 'C' &&
			!(data->type == 'c' && (data->modificateur == 'l' ||
					data->modificateur == LL)) && !(data->type == 's' &&
					(data->modificateur == 'l' || data->modificateur == LL)))
		return (make_str(data, list));
	else
		return (make_wstr(data, list));
}

int				make_str(t_data *data, va_list *list)
{
	char	*number;
	int		ret;
	int		length;

	ret = 0;
	length = 0;
	number = get_var(data, list);
	if (*number == 0 && data->type == 'c')
		ret = 1;
	data->nb_len = ft_strlen(number);
	number = apply_precision(data, number);
	number = apply_flag(data, number);
	number = apply_length(data, number);
	les_flics(data, number);
	if (ret == 1)
	{
		length =  (int)ft_strlen(number) > data->length ? (int)ft_strlen(number) : data->length;
		if (length <= 0)
			length = 1;
		ft_putstr_with_null(number,length);
		return (length);
	}
	else
		ft_putstr(number);
	if (data->type == 'c' && *number == 0)
		return (1);
	else
		return (ft_strlen(number) + ret);
}

void			psuh_right(t_data *data, char *str, char *new_str, int length)
{
	char	fill;
	int		len;

	len = ft_strlen(str);
	if (len < 1 && isintab("c", data->type))
		len = 1;
	fill = ' ';
	if (data->comp == 1 && ((data->precision != -1 && data->precision < length)
				|| isintab("sc", data->type)))
		fill = '0';
	ft_memset(new_str, fill, data->length);
	ft_memcpy(new_str + data->length - len, str, length);
}
