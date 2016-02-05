		/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kk.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:35:51 by                   #+#    #+#             */
/*   Updated: 2016/02/05 01:18:16 by apaget           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>

int main(int argc, const char *argv[])
{
	char* l = setlocale(LC_ALL, "");
	if (l == NULL) {
		printf("Locale not set\n");
	} else {
		printf("Locale set to %s\n", l);
	}

	ft_printf("%.3d\n",-42);
	printf("%.3d\n",-42);
	
	return 0;
}

// + ignorer xXoOpuUsScC
