/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 02:55:26 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 03:06:18 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <unistd.h>

int		ft_putwstr(wchar_t *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (*str)
	{
		if ((i = print_wchar(*str)) == -1)
			return (-1);
		else
			count += i;
		str++;
	}
	return (count);
}

int		ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7f)
			i++;
		else if (*str <= 0x7ff)
			i += 2;
		else if (*str <= 0xffff)
			i += 3;
		else if (*str <= 0x1fffff)
			i += 4;
		else
			return (-1);
		str++;
	}
	return (i);
}

wchar_t	*ft_wstr_new(int length)
{
	wchar_t	*tmp;
	int		i;

	i = 0;
	tmp = (wchar_t*)malloc(sizeof(wchar_t) * length + 1);
	while (i < length + 1)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

int		apply_length_of_wchar(t_data *data, wchar_t tmp)
{
	wchar_t *str;

	str = (wchar_t*)malloc(sizeof(wchar_t) * (data->length + 1));
	ft_memset(str, 0, sizeof(wchar_t) * (data->length + 1));
	if (isintab(data->drapeau, '-'))
	{
		str[0] = tmp;
		ft_memset(str + 1, ' ', sizeof(wchar_t) * (data->length - 1));
		return (ft_putwstr(str));
	}
	else
	{
		ft_memset(str, ' ', sizeof(wchar_t) * (data->length - 1));
		str[data->length - 1] = tmp;
		return (ft_putwstr(str));
	}
	return (1);
}

int		make_wchar(t_data *data, va_list *list)
{
	wchar_t *str;
	wchar_t tmp;

	if ((tmp = va_arg(*list, wchar_t)) == 0)
	{
		write(1, &tmp, 1);
		return (1);
	}
	if (data->length > 1)
		return (apply_length_of_wchar(data, tmp));
	else
	{
		str = ft_wstr_new(1);
		*str = tmp;
		*(str + 1) = L'\0';
		return (ft_putwstr(str));
	}
	return (1);
}
