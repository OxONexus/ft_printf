/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:28:39 by                   #+#    #+#             */
/*   Updated: 2016/01/28 19:29:15 by                  ###   ########.fr       */
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
		return;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (tab[i] == 0)
		{
			tab[i] = c;
			return;
		}
		i++;
	}
}