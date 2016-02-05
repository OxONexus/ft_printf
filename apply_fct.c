/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 01:32:49 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 01:36:02 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_flag(t_data *data, char *str)
{
	char *add;

	add = ft_strnew(3);
	if (isintab(data->drapeau, '#'))
		str = apply_diezzz(data, str);
	if (*str != '-' && isintab(data->drapeau, '+') &&
			!(isintab("cCpuUsSoOxX", data->type)))
	{
		*add = '+';
		str = ft_strjoin(add, str);
	}
	if (isintab(data->drapeau, ' ') && !(isintab("sScCpuUoOxX", data->type))
			&& (*str != '-' && *str != '+'))
	{
		*add = ' ';
		str = ft_strjoin(add, str);
	}
	free(add);
	return (str);
}

char	*apply_length(t_data *data, char *str)
{
	char	*new;
	int		length;

	length = ft_strlen(str);
	if (length < 1)
		length = 1;
	if (data->length > length)
	{
		new = ft_strnew(data->length);
		if (isintab(data->drapeau, '-'))
		{
			ft_memset(new, ' ', data->length);
			ft_strncpy(new, str, ft_strlen(str));
		}
		else
			psuh_right(data, str, new, length);
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

char	*apply_diezzz(t_data *data, char *str)
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
	if ((data->type == 'o' || data->type == 'O') && data->precision <=
			data->nb_len && (ft_atoi(str) != 0 || data->precision <= 0))
	{
		*add = '0';
	}
	str = ft_strjoin(add, str);
	free(add);
	return (str);
}
