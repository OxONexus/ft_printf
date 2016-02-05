/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:05:58 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 02:30:06 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_integer(long long int number, int base, char sep)
{
	char					*str;
	char					*ito;
	char					*result;
	unsigned long long int	tmp;

	if (number < 0)
	{
		str = ft_strnew(1);
		tmp = -number;
		str[0] = '-';
		ito = ft_unsigned_itoa_base(tmp, base, sep);
		result = ft_strjoin(str, ito);
		free(ito);
		free(str);
	}
	else
		result = ft_unsigned_itoa_base(number, base, sep);
	return (result);
}

char	*get_signed_var(t_data *data, va_list *list)
{
	char			*str;
	long long int	cast;

	cast = 0;
	str = NULL;
	cast = va_arg(*list, long long int);
	cast = cast_number(data, cast);
	if (data->type == 'd' || data->type == 'i' || data->type == 'D')
		str = get_integer(cast, 10, 'a');
	if (data->type == 'c')
		str = get_char(cast);
	return (str);
}

char	*get_ptr(void *ptr)
{
	char *str;
	char *tmp;
	char *result;

	if (ptr != NULL)
	{
		str = ft_strnew(2);
		str[0] = '0';
		str[1] = 'x';
		tmp = ft_unsigned_itoa_base((long long int)ptr, 16, 'a');
		result = ft_strjoin(str, tmp);
		free(str);
		free(tmp);
		return (result);
	}
	else
		str = ft_strdup("0x0");
	return (str);
}

char	*get_char(char c)
{
	char *str;

	str = ft_strnew(2);
	*str = c;
	return (str);
}

int		get_str_len_of_num(unsigned long long int number, int base)
{
	if (base > 0 && number >= (unsigned int)base)
		return (1 + get_str_len_of_num(number / base, base));
	else
		return (1);
}
