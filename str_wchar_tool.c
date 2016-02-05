/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_wchar_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 02:36:38 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 02:39:09 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wstrcpy(wchar_t *dest, wchar_t *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
}

void	ft_wstrncpy(wchar_t *dest, wchar_t *src, int n)
{
	int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	fill(wchar_t *str, wchar_t c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
}

int		ft_wcharlen(wchar_t *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
