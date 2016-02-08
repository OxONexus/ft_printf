/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:01:39 by apaget            #+#    #+#             */
/*   Updated: 2016/02/08 15:41:30 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*load_conf(char *str, t_data *data, va_list *list)
{
	int length;
	if ((data->drapeau = get_drapeau(data, &str)) == NULL)
		return (NULL);
	if ((data->length = get_length(&str, data, list)) != -1)
	{
		if (ft_isdigit(*str))
		{
			while (ft_isdigit(*str))
				str++;
		}
		else if (*str == '*')
		{
			str++;
			if ((length = get_length(&str, data, list)) != -1)
				data->length = length;
			while (ft_isdigit(*str))
				str++;
		}
		if (*str == '*')
		{
			length = get_length(&str, data, list);
			data->length = length;
			str++;
			while (ft_isdigit(*str))
				str++;
		}
	}
	if ((data->precision = get_precision(&str, list)) != -1)
	{
		str++;
		while (ft_isdigit(*str))
			str++;
		if (*str == '*')
			str++;
	}
	data->modificateur = get_modificateur(&str);
	if ((data->type = get_type(&str)) != 0)
		str++;
	else
		return (NULL);
	return (str);
}

void	fill_empty_data(t_data *data)
{
	if (data->precision == -1)
	{
		if (data->type != 'e' && data->type != 'E' && data->type != 'f' &&
		data->type != 's' && data->type != 'c' && data->type != 'S' &&
		data->type != 'F')
			data->precision = 1;
		else if (data->type == 'S' || data->type == 's')
			data->precision = -1;
		else
			data->precision = 6;
	}
	if (data->precision == -2 && data->type == 's')
		data->precision = -1;
}

void	init_data(t_data *data)
{
	data->drapeau = 0;
	data->length = -1;
	data->comp = 0;
	data->precision = -1;
	data->modificateur = 0;
	data->type = 0;
	data->data = NULL;
}
