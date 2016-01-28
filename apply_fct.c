/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:33 by                   #+#    #+#             */
/*   Updated: 2016/01/28 19:21:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *apply_flag(t_data *data, char *str)
{
	char *add;

	add = ft_strnew(3);
	if (isintab(data->drapeau,'#'))
		str = apply_diezzz(data, str);
	if (*str != '-' && isintab(data->drapeau, '+') && !(isintab("cuUsoOxX",data->type)))
	{
		*add = '+';
		str = ft_strjoin(add,str);
	}
	if (isintab(data->drapeau, ' ') && (data->type != 'c' && data->type != 's')
		&& (*str != '-' && *str != '+'))
	{
		*add = ' ';
		str = ft_strjoin(add,str);
	}
	free(add);
	return (str);
}

char	*apply_precision(t_data *data, char *str)
{
	char *new;
	int length;

	length = ft_strlen(str);

	if (data->precision != -1 && data->precision < length && data->type == 's')
	{
		new = ft_strnew(data->precision);
		ft_memcpy(new,str,data->precision);
		return (new);
	}
	else if (data->precision > length && data->type != 's' && data->type != 'c')
	{
		new = ft_strnew(data->precision);
		ft_memset(new, '0', data->precision);
		ft_memcpy(new + data->precision - length, str, length);
		return (new);
	}
	return (str);
}

char	*apply_length(t_data *data, char *str)
{
	char *new;
	int length;
	char c;

	c = ' ';
	if (data->comp == 1)
		c = '0';

	length = ft_strlen(str);
	if (data->length > length)
	{
		new = ft_strnew(data->length);
		if (isintab(data->drapeau, '-'))
		{
			ft_strcpy(new, str);
			ft_memset(new + ft_strlen(str), ' ', data->length - ft_strlen(str));
		}
		else
			psuh_right(data, str, new);
		return (new);
	}
	return (str);
}

char	*get_var(t_data *data, va_list *list)
{
	char *str;

	if (ft_strchr("dioOc", data->type) != NULL)
		str = get_signed_var(data, list);
	else if (ft_strchr("xDXuU", data->type) != NULL)
		str = get_unsigned_var(data, list);
	else
	{
		if (data->type == 'p')
			str = get_ptr(va_arg(*list, int*));
		if (data->type == 's')
		{
			if ((str = va_arg(*list, char*)) == NULL)
				str = ft_strdup("(null)");
		}
	}
	return (str);
}

char *apply_diezzz(t_data *data, char *str)
{
	char *add;

	add = ft_strnew(3);
	if (data->type == 'x')
	{
		*add = '0';
		*(add + 1) = 'x';
	}
	if (data->type == 'X')
	{
		*add = '0';
		*(add + 1) = 'X';
	}
	if (data->type == 'o' && data->precision <= data->nb_len)
	{
		*add = '0';
	}
	str = ft_strjoinfree(add, str);
	return (str);
}
