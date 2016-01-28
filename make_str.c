/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 02:51:28 by apaget            #+#    #+#             */
/*   Updated: 2016/01/28 19:24:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

long long int cast_number(t_data *data, long long int cast)
{
	if (data->modificateur == LL)
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

char	*get_signed_var(t_data *data, va_list *list)
{
	char			*str;
	long long int	cast;

	cast = 0;
	str = NULL;
	cast = va_arg(*list, long long int);
	cast = cast_number(data, cast);
	if (data->type == 'd' || data->type == 'i')
		str = get_integer(cast, 10, 'a');
	if (data->type == 'o' || data->type == 'O')
		str = get_integer(cast , 8,'a');
	if (data->type == 'c')
		str = get_char(cast);
	return (str);
}


int		make_str(t_data *data, va_list *list)
{
	char *number;
	if (data->type != 'S' && data->type != 'C')
	{
		number = get_var(data,list);
		data->nb_len = ft_strlen(number);
		number = apply_precision(data,number);
		number = apply_flag(data,number);
		number = apply_length(data,number);
		les_flics(data, number);
		ft_putstr(number);
		return (ft_strlen(number));
	}
	else
		return(make_wstr(data, list));
}


int isintab(char *tab, char c)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void psuh_right(t_data *data, char *str, char *new)
{
	if ((*str == '-' || *str == '+' || *str == ' ') && data->comp == 1 &&
			data->type != 'c' && data->precision != -1)
	{
		*new = *str;
		ft_memset(new + 1, '0', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str) + 1, str + 1);
	}
	else if (*str != '-' && data->comp == 0)
	{
		ft_memset(new, ' ', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str),str);
	}
	else if (*str != '-' && data->comp == 1 && data->type != 'c' &&
			data->precision != -1)
	{
		ft_memset(new, '0', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str),str);
	}
	else
	{
		ft_memset(new, ' ', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str),str);
	}
}
