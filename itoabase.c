/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoabase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:09:46 by apaget            #+#    #+#             */
/*   Updated: 2016/02/02 07:05:10 by apaget           ###   ########.fr       */
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
		if (*str > '9')
			*str += sep - 10;
		else
			*str += '0';
		str++;
		len--;
	}
	return (tmp);
}


int		is_null_ptr(char *ptr)
{
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '0' && *ptr != 'x' && *ptr != 'X')
			return (0);
		ptr++;
	}
	return (1);
}


void	corrige_Ox(char *str)
{
	int i;
	char tmp;

	i = 0;

	if (isintab(str,'x') || isintab(str,'X'))
	{
		while (str[i] != 'x' && str[i] != 'X')
			i++;
		tmp = str[1];
		str[1] = str[i];
		str[i] = tmp;
	}
}

void	corrige_sign(char *str)
{
	char *tmp;
	int i;

	i = 0;
	if (isintab(str,'-') || isintab(str,' ') || isintab(str,'-'))
	{
		if(*str =='0')
		{
			while (str[i] != '-' && str[i] != ' ' && str[i] != '+')
				i++;
			*str = str[i];
			str[i] = '0';
		}
	}
}
void	*les_flics(t_data *data, char *str)
{
	int i;
	char c;

	i = 0;
	if (isintab("pxX", data->type))
		corrige_Ox(str);
	else if (isintab("id", data->type))
		corrige_sign(str);
	/*
	   if ((data->type == 'x' || data->type == 'X') && (data->length >
	   data->nb_len + 2 && data->comp == 1 && isintab(data->drapeau, '#')))
	   {
	   while (str[i] == '0' && str[i])
	   i++;
	   str[1] = str[i];
	   str[i] = '0';
	   }
	   i = 0;
	   if (*str == '0' || *str == ' ')
	   {
	   while ((str[i] == '0' || str[i] == ' ') && str[i])
	   i++;
	   if (str[i] == '-'|| str[i] == '+' || str[i] == ' ')
	   {
	   c = str[i];
	   if (*str == '0')
	   {
	   str[0] = str[i];
	   str[i] = '0';
	   }
	   else if (data->type == 'o' || data->type == 'O')
	   {
	   i = 0;
	   while (str[i] == ' ' && str[i])
	   i++;
	   str[i - 1] = c;
	   while (str[i] != c)
	   i++;
	   str[i] = '0';
	   }
	   }
	   }
	   */
}
