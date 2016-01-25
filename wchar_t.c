/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 01:38:26 by                   #+#    #+#             */
/*   Updated: 2016/01/19 03:58:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <unistd.h>

void	ft_putwchar_t(wchar_t c)
{
	write(1, &c, 1);
}

void	ft_putwstr(wchar_t *str)
{
	while (*str)
	{
		write(1, str, 1);
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
