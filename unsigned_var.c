/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:22:48 by                   #+#    #+#             */
/*   Updated: 2016/02/02 10:34:11 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int cast_unsigned_number(t_data *data, unsigned long long nb)
{
	if (isintab("OU",data->type))
		nb = (unsigned long long)nb;
	else if (data->modificateur == LL)
		nb = (unsigned long long)nb;
	else if (data->modificateur == 'l')
		nb = (unsigned long)nb;
	else if (data->modificateur == 'h')
		nb = (unsigned short)nb;
	else if (data->modificateur == HH)
		nb = (unsigned char)nb;
	else if (data->modificateur == 'z')
		nb = (size_t)nb;
	else if (data->modificateur == 'j')
		nb = (unsigned long long)nb;
	else
		nb = (unsigned)nb;
	return (nb);
}

char	*get_unsigned_var(t_data *data, va_list *list)
{
	unsigned long long	un_cast;;
	char				*str;

	un_cast = 0;

	un_cast = va_arg(*list, unsigned long long);
	un_cast = cast_unsigned_number(data, un_cast);
	if (data->type == 'x')
		str = ft_unsigned_itoa_base(un_cast, 16, 'a');
	else if (data->type == 'X')
		str = ft_unsigned_itoa_base(un_cast, 16, 'A');
	else if (data->type == 'u' || data->type == 'U' || data->type == 'D')
		str = ft_unsigned_itoa_base(un_cast, 10, 'a');
	else if (data->type == 'o' || data->type == 'O')
		str = ft_unsigned_itoa_base(un_cast, 8, 'a');
	return (str);
}

char *ft_unsigned_itoa_base(unsigned long long int number, int base, char sep)
{
	char *str;
	char *tmp;
	int len;

	len = get_str_len_of_num(number, base);
	str = (char*)malloc(sizeof(char) * len + 1);
	tmp = str;
	str[len] = '\0';
	while (len > 0)
	{

		*str = get_unsigned_str(number, base, len);
		if (*str > 9)
			*str += sep - 10;
		else
			*str += '0';
		str++;
		len--;
	}
	return (tmp);
}

int		get_unsigned_str(unsigned long long int number, int base, int i)
{
	if (i == 1)
		return (number % base);
	else
		return (get_unsigned_str(number / base, base, i - 1));
}
