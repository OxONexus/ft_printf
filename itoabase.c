/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoabase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:09:46 by apaget            #+#    #+#             */
/*   Updated: 2016/01/28 20:13:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int power_base(long long int nb, int power,long long int nbsave)
{
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	return (power_base(nb * nbsave, power - 1, nbsave));
}

int		get_str(long long int number, int base, int i)
{
	if (i == 1)
		return (number % base);
	else
		return (get_str(number / base, base, i - 1));
}

char	*ft_itoa_base(long long int number, int base, char sep)
{
	char	*str;
	char	*tmp;
	int		len;

	len = get_str_len_of_num(number, base);
	str = (char*)malloc(sizeof(char) * len + 1);
	tmp = str;
	str[len] = '\0';
	while (len > 0)
	{

		*str = get_str(number, base, len);
		if (*str > 9)
			*str += sep - 10;
		else
			*str += '0';
		str++;
		len--;
	}
	return (tmp);
}

void	*les_flics(t_data *data, char *str)
{
	int i;

	i = 0;
	if ((data->type == 'x' || data->type == 'X') && data->length >
		data->nb_len + 2 && data->comp == 1 && isintab(data->drapeau, '#'))
	{
		while (str[i] == '0' && str[i])
			i++;
		str[1] = str[i];
		str[i] = '0';
	}
	i = 0;
	if (*str == 0)
	{
		while (str[i] == 0 && str[i])
			i++;
		if (str[i] == '-'|| str[i] == '+' || str[i] == ' ')
		{
			str[0] = str[i];
			str[i] = 0;
		}
	}
}














