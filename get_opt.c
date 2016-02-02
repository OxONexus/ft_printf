/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 20:38:03 by apaget            #+#    #+#             */
/*   Updated: 2016/02/02 03:21:53 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char	*get_drapeau(t_data *data, char **str)
{
	char *flag;

	if ((flag = ft_strnew(4)) == NULL)
		return (NULL);
	while (**str == ' ' || **str == '-' || **str == '+' || **str == '#' ||
			**str == '%' || **str == '0')
	{
		if (**str == '%')
		{
			free(flag);
			return (NULL);
		}
		if (**str == '0')
			data->comp = 1;
		else
			addtotab(flag, **str);
		(*str)++;
	}
	return (flag);
}

int		get_length(char **str, t_data *data)
{
	while(**str == ' ')
		(*str)++;
	if (**str == '0')
	{
		data->comp = 1;
		if (ft_isdigit(*(*str + 1)))
			return (atoi(*str + 1));
	}
	if (ft_isdigit(**str))
		return (atoi(*str));
	return (-1);
}

int		get_precision(char **str)
{
	while(**str == ' ')
		(*str)++;
	if (**str == '.')
	{
		return (atoi((*str + 1)));
	}
	return (-1);
}

char	get_modificateur(char **str)
{
	char mod;

	mod = 0;
	if (**str == 'l' && *((*str) + 1) == 'l')
	{
		(*str) += 2;
		return (LL);
	}
	else if (**str == 'h' && *((*str) + 1) == 'h')
	{
		(*str) += 2;
		return (HH);
	}
	else if (**str == 'h' || **str == 'z' || **str == 'j' || **str == 'l')
	{
		mod = **str;
		(*str)++;
		return (mod);
	}
		return (0);
}

char	get_type(char **str)
{
	int i;
	char type[] = "SCDspdioOUuxXc";

	i = 0;
	while(**str == ' ')
		(*str)++;
	while (type[i])
	{
		if (type[i] == **str)
			return (**str);
		i++;
	}
	return (0);
}
