/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:01:39 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 02:10:52 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*load_conf(char *str, t_data *data)
{
	if ((data->drapeau = get_drapeau(data, &str)) == NULL)
		return (NULL);
	if ((data->length = get_length(&str, data)) != -1)
	{
		while (ft_isdigit(*str))
			str++;
	}
	if ((data->precision = get_precision(&str)) != -1)
	{
		str++;
		while (ft_isdigit(*str))
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
		data->type != 's' && data->type != 'c' && data->type != 'S')
			data->precision = 1;
		else if (data->type == 'S' || data->type == 's')
			data->precision = -1;
		else
			data->precision = 6;
	}
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
