/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:17:33 by                   #+#    #+#             */
/*   Updated: 2016/02/02 07:08:38 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *apply_flag(t_data *data, char *str)
{
	char *add;

	add = ft_strnew(3);
	if (isintab(data->drapeau,'#'))
		str = apply_diezzz(data, str);
	if (*str != '-' && isintab(data->drapeau, '+') && !(isintab("cCpuUsSoOxX",data->type)))
	{
		*add = '+';
		str = ft_strjoin(add,str);
	}
	if (isintab(data->drapeau, ' ') && !(isintab("sScCpuUoOxX",data->type))
		&& (*str != '-' && *str != '+'))
	{
		*add = ' ';
		str = ft_strjoin(add,str);
	}
	//free(add);
	return (str);
}

char	*apply_precision(t_data *data, char *str)
{
	char *new;
	int length;

	length = ft_strlen(str);

	if (data->precision != -1 && data->precision < length && data->type == 'p'&&
	   (isintab(data->drapeau,'#') || !ft_strncmp(str,"0x0",3)))
	{
		new = ft_strnew(data->precision + 2);
		ft_memcpy(new,str,data->precision + 2);
		return (new);
	}
	else if (data->precision != -1 && data->precision < length && data->type == 's')
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

	length = ft_strlen(str);
	if (length < 1)
		length = 1;
	if (data->length > length)
	{
		new = ft_strnew(data->length + (ft_strlen(str) - data->nb_len));
		if (isintab(data->drapeau, '-'))
		{
			ft_memset(new, ' ', data->length + (ft_strlen(str) - data->nb_len));
			ft_strncpy(new, str,ft_strlen(str));
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

	if (ft_strchr("diDc", data->type) != NULL)
		str = get_signed_var(data, list);
	else if (ft_strchr("oOxXuU", data->type) != NULL)
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
	if (data->type == 'x' && ft_atoi(str) != 0)
	{
		*add = '0';
		*(add + 1) = 'x';
	}
	if (data->type == 'X' && ft_atoi(str) != 0)
	{
		*add = '0';
		*(add + 1) = 'X';
	}
	if ((data->type == 'o' || data->type == 'O') && data->precision <= data->nb_len && ft_atoi(str) != 0)
	{
		*add = '0';
	}
	str = ft_strjoin(add, str);
	free(add);
	return (str);
}
