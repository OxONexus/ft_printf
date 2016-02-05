/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:05:58 by apaget            #+#    #+#             */
/*   Updated: 2016/02/04 12:27:50 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_integer(long long int number,int base, char sep)
{
	char *str;
	char *ito;
	unsigned long long int tmp;

	str = (char *)malloc(sizeof(char) * 2);
	ft_bzero(str, 2);
	if (number < 0)
	{
		tmp = -number;
		str[0] = '-';
		ito = ft_unsigned_itoa_base(tmp, base, sep);
		str = ft_strjoin(str,ito);
		//free(ito);
	}
	else
		str = ft_unsigned_itoa_base(number, base, sep);
	return (str);
}

char	*get_ptr(void *ptr)
{
	char *str;
	char *tmp;

	if (ptr != NULL)
	{
	str = ft_strnew(2);
	str[0] = '0';
	str[1] = 'x';
	tmp = ft_unsigned_itoa_base((long long int)ptr, 16, 'a');
	str = ft_strjoin(str,tmp);
	//free(tmp);
	}
	else
	{
		str = ft_strdup("0x0");
	}
	return (str);
}

char *get_char(char c)
{
	char *str;

	str = ft_strnew(2);
	*str = c;
	//printf("debug str : %s\n",str);
	return (str);
}

int get_str_len_of_num(unsigned long long int number, int base)
{
	if (base > 0 && number >= (unsigned int)base)
		return(1 + get_str_len_of_num(number / base, base));
	else
		return (1);
}
