/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_wstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:33:14 by                   #+#    #+#             */
/*   Updated: 2016/01/31 19:46:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_wstr(t_data *data, va_list *list)
{
	wchar_t *str;

	str = NULL;
	if (data->type == 'C')
	{
		make_wchar(data, list);
		return (data->length <= 0 ? 1 : data->length);
	}
	else if (data->type == 'S')
		return (make_wwwwwwstr(data, list));
}

wchar_t	*apply_wprecision(t_data *data, wchar_t *str)
{
	wchar_t *new;
	int		length;

	length = ft_wstrlen(str);

	if (data->precision != -1 && data->precision < length && data->type == 'S')
	{
		new = ft_wstr_new(data->precision);
		ft_memcpy(new, str, data->precision);
		return (new);
	}
	else
	{
		new = ft_wstr_new(length);
		ft_memcpy(new,str,length * sizeof(wchar_t));
	}
	return (new);
}

int		apply_wlength(t_data *data, wchar_t *str)
{
	wchar_t	*new;
	int		length;

	length = ft_wstrlen(str);
	new = (wchar_t*)malloc(sizeof(wchar_t) * (data->length + 1));
	ft_memset(new, 0, sizeof(wchar_t) * (data->length + 1));
	if (isintab(data->drapeau, '-'))
	{
		ft_memcpy(new,str,length * sizeof(wchar_t));
		ft_memset(new + length, ' ', sizeof(wchar_t) * (data->length - length));
		ft_putwstr(new);
	}
	else
	{
		ft_memset(new, ' ', sizeof(wchar_t) * (data->length - length));
		ft_memcpy(new + data->length - length, str, length * sizeof(wchar_t));
		ft_putwstr(new);
	}
	length = ft_wstrlen(new);
	free(new);
	return (length);
}

int		make_wwwwwwstr(t_data *data, va_list *list)
{
	wchar_t	*str;
	wchar_t	*new;
	wchar_t	*tmp;
	int		length;

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
		ft_putwstr(str);
	free(str);
	return (length);
}
