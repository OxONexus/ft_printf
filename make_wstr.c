/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 02:42:11 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 03:09:09 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_wstr(t_data *data, va_list *list)
{
	wchar_t *str;

	str = NULL;
	if (data->type == 'C' || data->type == 'c')
		return (make_wchar(data, list));
	else
		return (make_wwwwwwstr(data, list));
}

int		get_pprecision(t_data *data, wchar_t *str)
{
	int i;
	int old;

	i = 0;
	old = 0;
	while (*str && i < data->precision)
	{
		if (*str <= 0x7f)
			i++;
		else if (*str <= 0x7ff)
			i += 2;
		else if (*str <= 0xffff)
			i += 3;
		else if (*str <= 0x1fffff)
			i += 4;
		str++;
	}
	if (ft_wcharlen(str) < data->precision)
		return (i + 4);
	else
		return (data->precision);
}

wchar_t	*apply_wprecision(t_data *data, wchar_t *str)
{
	wchar_t *new_str;
	int		length;

	length = ft_wstrlen(str);
	if (data->precision != -1 && data->precision < length && data->type == 'S')
	{
		new_str = (wchar_t*)malloc(sizeof(wchar_t) * (data->precision + 1));
		ft_memcpy(new_str, str, get_pprecision(data, str));
		new_str[data->precision] = 0;
		return (new_str);
	}
	else
	{
		new_str = (wchar_t*)malloc(sizeof(wchar_t) * (length + 1));
		ft_memcpy(new_str, str, length * sizeof(wchar_t));
		new_str[length] = 0;
	}
	return (new_str);
}

int		apply_wlength(t_data *data, wchar_t *str)
{
	wchar_t	*new_str;
	int		length;
	wchar_t t;

	t = L' ';
	if (data->comp)
		t = L'0';
	length = ft_wstrlen(str);
	new_str = (wchar_t*)malloc(sizeof(wchar_t) * (data->length + 1));
	new_str[data->length] = 0;
	if (isintab(data->drapeau, '-'))
	{
		ft_wstrcpy(new_str, str);
		fill(new_str + ft_wcharlen(str), t, data->length - ft_wcharlen(str));
		new_str[ft_wcharlen(str) + (data->length - ft_wstrlen(str))] = 0;
		ft_putwstr(new_str);
	}
	else
	{
		fill(new_str, t, data->length - ft_wstrlen(str));
		ft_wstrcpy(new_str + data->length - ft_wstrlen(str), str);
		ft_putwstr(new_str);
	}
	length = ft_wstrlen(new_str);
	return (length);
}

int		make_wwwwwwstr(t_data *data, va_list *list)
{
	wchar_t	*str;
	wchar_t	*new_str;
	wchar_t	*tmp;
	int		length;

	length = 0;
	if ((tmp = va_arg(*list, wchar_t*)) == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	str = apply_wprecision(data, tmp);
	length = ft_wstrlen(str);
	if (data->length > length)
		return (apply_wlength(data, str));
	else
		length = ft_putwstr(str);
	return (length);
}
