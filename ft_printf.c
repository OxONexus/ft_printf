/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 02:20:27 by apaget            #+#    #+#             */
/*   Updated: 2016/02/08 15:18:34 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_void(t_data *data, char c)
{
	char *str;

	str = ft_strnew(1);
	*str = c;
	str = apply_length(data, str);
	ft_putstr(str);
	return (ft_strlen(str));
}

char	*parse_conf(char *str)
{
	while (isintab("# +-", *str))
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '*')
		str++;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
			str++;
	if (*str == '*')
		str++;
	}
	while (*str && *str == ' ')
		str++;
	return (str);
}

char	*get_conf(char *str, int *count, va_list *list)
{
	t_data	data;
	char	*tmp;

	if ((tmp = load_conf(str, &data, list)) == NULL)
	{
		str = parse_conf(str);
		if (data.length > 0)
		{
			*count += make_void(&data, *str);
			str++;
		}
		else if (*str == '%')
		{
			ft_putchar('%');
			(*count)++;
		}
	}
	else
	{
		str = tmp;
		fill_empty_data(&data);
		*count += print_value_of_data(&data, list);
	}
	return (str - 1);
}

int		ft_printf(char *str, ...)
{
	int		count_print_char;
	va_list	list;

	va_start(list, str);
	count_print_char = 0;
	while (*str && ft_isascii(*str))
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			count_print_char++;
		}
		else if (*str == '%' && *(str + 1) != '%')
			str = get_conf(str + 1, &count_print_char, &list);
		else
		{
			ft_putchar(*str);
			count_print_char++;
			str++;
		}
		str++;
	}
	va_end(list);
	return (count_print_char);
}
