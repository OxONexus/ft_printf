/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 02:48:37 by apaget            #+#    #+#             */
/*   Updated: 2016/02/05 02:49:27 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	addtotab(char *tab, char c)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tab[i] == c)
			return ;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (tab[i] == 0)
		{
			tab[i] = c;
			return ;
		}
		i++;
	}
}

int		isintab(char *tab, char c)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}
