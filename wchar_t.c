/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 01:38:26 by                   #+#    #+#             */
/*   Updated: 2016/01/31 18:40:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <unistd.h>

void	ft_putwstr(wchar_t *str)
{
	while (*str)
	{
		print_wchar(*str);
		str++;
	}
}
int		ft_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while(*str)
	{
		str++;
		i++;
	}
	return (i);
}
wchar_t	*ft_wstr_new(int length)
{
	wchar_t *tmp;
	int i;

	i = 0;
	tmp = (wchar_t*)malloc(sizeof(wchar_t) * length + 1);
	while(i < length + 1)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

void	make_wchar(t_data *data, va_list *list)
{
	wchar_t *str;

	str = NULL;
	if (data->length > 1)
	{
		str = (wchar_t*)malloc(sizeof(wchar_t) * (data->length + 1));
		ft_memset(str, 0, sizeof(wchar_t) * (data->length + 1));
		if (isintab(data->drapeau, '-'))
		{
			str[0] = va_arg(*list, wchar_t);
			ft_memset(str + 1, ' ', sizeof(wchar_t) * (data->length - 1));
			ft_putwstr(str);
		}
		else
		{
			ft_memset(str,' ', sizeof(wchar_t) * (data->length - 1));
			str[data->length - 1] = va_arg(*list, wchar_t);
			ft_putwstr(str);
		}
	}
}




void		draw(int nb, unsigned int c)
{
	int i;
	char *str = ft_unsigned_itoa_base(c, 2, 'a');
	printf("%s\n",str);
	free(str);
	c >> 8;
	str = ft_unsigned_itoa_base(c, 2, 'a');
	printf("%s\n",str);
	free(str);
	c >> 8;
	str = ft_unsigned_itoa_base(c, 2, 'a');
	printf("%s\n",str);
	free(str);
	c >> 8;
	str = ft_unsigned_itoa_base(c, 2, 'a');
	printf("%s\n",str);
	free(str);
	c >> 8;
	str = ft_unsigned_itoa_base(c, 2, 'a');
	printf("%s\n",str);
	free(str);
}

void		print_wchar(wchar_t c)
{
	unsigned int wchar;
	char *str2 = ft_unsigned_itoa_base(0xc080,2,0);

	wchar = (unsigned int)c;
	if (c <= 0x7f)
		ft_putchar((char)wchar);
	else if (c <= 0x7ff)
		print_2byte((unsigned int)wchar);
	else if (c <= 0xffff)
		print_3byte((unsigned int)wchar);
	else if (c <= 0x1fffff)
		print_4byte((unsigned int)wchar);
}
