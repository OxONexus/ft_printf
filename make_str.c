/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 02:51:28 by apaget            #+#    #+#             */
/*   Updated: 2016/01/28 15:37:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>


unsigned long long int cast_unsigned_number(t_data *data, unsigned long long nb)
{
	if (data->modificateur == LL)
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

long long int cast_number(t_data *data, long long int cast)
{
	if (data->modificateur == LL)
		cast = (long long)cast;
	else if (data->modificateur == 'l')
		cast = (long)cast;
	else if (data->modificateur == 'h')
		cast = (short)cast;
	else if (data->modificateur == HH)
		cast = (char)cast;
	else if (data->modificateur == 'z')
		cast = (size_t)cast;
	else if (data->modificateur == 'j')
		cast = (long long)cast;
	else
		cast = (int)cast;
	return (cast);
}

void	get_nb_len(t_data *data, char *src)
{
	data->nb_len = ft_strlen(src);
}

char	*get_var(t_data *data, va_list *list)
{
	char *str;
	long long int cast;
	unsigned long long un_cast;;

	cast = 0;
	if (ft_strchr("diDoc", data->type) != NULL)
	{
		cast = va_arg(*list, long long int);
		cast = cast_number(data, cast);
		if (data->type == 'd' || data->type == 'i' || data->type == 'D')
			str = get_integer(cast, 10, 'a');
		if (data->type == 'o' || data->type == 'O')
			str = get_integer(cast , 8,'a');
		if (data->type == 'c')
			str = get_char(cast);
	}
	else if (ft_strchr("xXuU", data->type) != NULL)
	{
		un_cast = va_arg(*list, unsigned long long);
		un_cast = cast_unsigned_number(data, un_cast);
		if (data->type == 'x')
			str = ft_unsigned_itoa_base(un_cast, 16, 'a');
		if (data->type == 'X')
			str = ft_unsigned_itoa_base(un_cast, 16, 'A');
		if (data->type == 'u' || data->type == 'U')
			str = ft_unsigned_itoa_base(un_cast, 10, 'a');
	}
	else
	{
		if (data->type == 'p')
			str = get_ptr(va_arg(*list, int*));
		if (data->type == 's')
		{
			if ((str = va_arg(*list, char*)) == NULL)
				str = ft_strdup("(null)");
		}
	}
	return (str);
}

int		make_str(t_data *data, va_list *list)
{
	char *number;
	if (data->type != 'S' && data->type != 'C')
	{
		number = get_var(data,list);
		get_nb_len(data, number);
		number = apply_precision(data,number);
		number = apply_flag(data,number);
		number = apply_length(data,number);
		les_flics(data, number);
		ft_putstr(number);
		return (ft_strlen(number));
	}
	else
		return(make_wstr(data, list));
}

char	*apply_precision(t_data *data, char *str)
{
	char *new;
	int length;

	length = ft_strlen(str);

	if (data->precision != -1 && data->precision < length && data->type == 's')
	{
		new = ft_strnew(data->precision);
		ft_memcpy(new,str,data->precision);
		return (new);
	}
	else if (data->precision > length && data->type != 's' && data->type != 'c')
	{
		new = ft_strnew(data->precision);
		ft_memset(new, '0', data->precision);
		ft_memcpy(new + data->precision - length, str, length);
		return (new);
	}
	return (str);
}

int isintab(char *tab, char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}


char	*apply_length(t_data *data, char *str)
{
	char *new;
	int length;
	char c;

	c = ' ';
	if (data->comp == 1)
		c = '0';

	length = ft_strlen(str);
	if (data->length > length)
	{
		new = ft_strnew(data->length);
		if (isintab(data->drapeau, '-'))
		{
			ft_strcpy(new, str);
			ft_memset(new + ft_strlen(str), ' ', data->length - ft_strlen(str));
		}
		else
			psuh_right(data, str, new);
		return (new);
	}
	return (str);
}

void psuh_right(t_data *data, char *str, char *new)
{
	int neg;
	char c;

	c = ' ';

	if ((*str == '-' || *str == '+' || *str == ' ') && data->comp == 1 &&
			data->type != 'c' && data->precision != -1)
	{
		*new = *str;
		ft_memset(new + 1, '0', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str) + 1, str + 1);
	}
	else if (*str != '-' && data->comp == 0)
	{
		ft_memset(new, ' ', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str),str);
	}
	else if (*str != '-' && data->comp == 1 && data->type != 'c' &&
		data->precision != -1)
	{
		ft_memset(new, '0', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str),str);
	}
	else
	{
		ft_memset(new, ' ', data->length - ft_strlen(str));
		ft_strcpy(new + data->length - ft_strlen(str),str);
	}
}

char *apply_diezzz(t_data *data, char *str)
{
	char *add;

	add = ft_strnew(3);
	if (data->type == 'x')
	{
		*add = '0';
		*(add + 1) = 'x';
	}
	if (data->type == 'X')
	{
		*add = '0';
		*(add + 1) = 'X';
	}
	if (data->type == 'o' && data->precision <= data->nb_len)
	{
		*add = '0';
	}
	str = ft_strjoinfree(add, str);
	return (str);
}
