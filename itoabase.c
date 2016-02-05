/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoabase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:09:46 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 03:25:17 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		power_base(long long int nb, int power, long long int nbsave)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	return (power_base(nb * nbsave, power - 1, nbsave));
}

void	corrige_ptr(char *str)
{
	int		i;
	char	tmp;

	i = 0;
	if (isintab(str, 'x') || isintab(str, 'X'))
	{
		while (*str == ' ')
			str++;
		while (str[i] != 'x' && str[i] != 'X')
			i++;
		tmp = str[1];
		str[1] = str[i];
		str[i] = tmp;
	}
}

void	parse(char *str, char *deb, char c)
{
	int i;

	i = 0;
	if (*str != c)
		return ;
	while (str[i] == c)
		i++;
	if (str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		*deb = str[i];
		str[i] = c;
	}
}

void	corrige_sign(t_data *data, char *str)
{
	int		i;

	i = 0;
	if (isintab(str, '-') || (isintab(str, ' ') && isintab(data->drapeau, ' '))
			|| isintab(str, '+'))
	{
		if ((int)ft_strlen(str) == data->length)
		{
			if (data->comp == 1)
				parse(&str[i], str, '0');
		}
	}
}

void	les_flics(t_data *data, char *str)
{
	int		i;

	i = 0;
	if (isintab("pxX", data->type))
		corrige_ptr(str);
	else if (isintab("id", data->type))
		corrige_sign(data, str);
}
