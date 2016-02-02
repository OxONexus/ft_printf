/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 02:51:28 by apaget            #+#    #+#             */
/*   Updated: 2016/02/02 06:35:18 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

long long int cast_number(t_data *data, long long int cast)
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

int		make_str(t_data *data, va_list *list)
{
	char *number;
	int ret;

	ret = 0;
	if (data->type != 'S' && data->type != 'C' &&
			!(data->type == 'c' && (data->modificateur == 'l'|| data->modificateur == LL)) &&
			!(data->type == 's' && (data->modificateur == 'l'|| data->modificateur == LL)))
	{
		number = get_var(data,list);
		if (*number == 0 && data->type == 'c')
			ret = 1;
		data->nb_len = ft_strlen(number); // va ajouter zero si > strlen uUidoOxXpD ou reduit la haine de caractere
		number = apply_precision(data,number);
		number = apply_flag(data,number);
		number = apply_length(data,number);
		les_flics(data, number);
		ft_putstr(number);
		if (data->type == 'c' && *number == 0)
			return (1);
		else
				return (ft_strlen(number) + ret);
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
	char fill;
	char *tmp;

	fill = ' ';
	if (data->comp == 1 && !isintab("sc", data->type) && data->precision != -1)
		fill = '0';
	ft_memset(new, fill, data->length);
	ft_strcpy(new + data->length - ft_strlen(str), str);
	/*
	if ((*str == '-' || *str == '+' || *str == ' ') && data->comp == 1 &&
			data->type != 'c' && data->precision != -1)
	{
		*new = *str;
		ft_memset(new + 1, '0', data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1));
		ft_strcpy(new + data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1) + 1, str + 1);
	}
	else if (*str != '-' && data->comp == 0)
	{
		ft_memset(new, ' ', data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1));
		ft_strcpy(new + data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1),str);
	}
	else if (*str != '-' && data->comp == 1 && data->type != 'c'&&
			data->precision != -1)
	{
		ft_memset(new, '0', data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1));
		ft_strcpy(new + data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1),str);
	}
	else
	{
		ft_memset(new, ' ', data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1));
		ft_strcpy(new + data->length - (ft_strlen(str) > 1 ? ft_strlen(str) : 1),str);
	}
	*/
}
