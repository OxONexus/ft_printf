/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:05:58 by apaget            #+#    #+#             */
/*   Updated: 2016/01/28 14:42:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_integer(long long int number,int base, char sep)
{
	char *str;
	long long int tmp;

	str = (char *)malloc(sizeof(char) * 2);
	ft_bzero(str, 2);
	if (number < 0)
	{
		tmp = -number;
		str[0] = '-';
		str = ft_strjoinfree(str,ft_itoa_base(tmp, base, sep));
	}
	else
		str = ft_itoa_base(number, base, sep);
	return (str);
}

char	*get_ptr(void *ptr)
{
	char *str;

	if (ptr != NULL)
	{
	str = ft_strnew(3);
	str[0] = '0';
	str[1] = 'x';
	str = ft_strjoinfree(str, ft_itoa_base((long long int)ptr, 16, 'a'));
	}
	else
	{
		str = ft_strdup("(nil)");
	}
	return (str);
}

char *get_char(char c)
{
	char *str;

	str = ft_strnew(2);
	*str = c;
	return (str);
}
