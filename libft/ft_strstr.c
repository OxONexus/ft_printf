/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:36:58 by apaget            #+#    #+#             */
/*   Updated: 2016/01/10 15:39:59 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_containsubstring(const char *s1,
		const char *s2, int i, int j)
{
	while (s2[j])
	{
		if (s1[i + j] != s2[j])
			return (0);
		j++;
	}
	return (1);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	if (ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			if (ft_containsubstring(s1, s2, i, j))
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
