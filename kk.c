/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kk.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:35:51 by                   #+#    #+#             */
/*   Updated: 2016/02/02 08:52:30 by apaget           ###   ########.fr       */
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
	/*
	char* l = setlocale(LC_ALL, "");
	if (l == NULL) {
		printf("Locale not set\n");
	} else {
		printf("Locale set to %s\n", l);
	}

	//x = printf("%C\n",L'是');
	//
	*//*
	y = ft_printf("%S",L"是");
	printf("\n");
	x = printf(7777,L"是");
	printf("\n");

	printf("printf : %d\n",x);
	printf("ft_printf : %d\n",y);
	printf("\n");
	printf("\n");
	*/
	int x,y;
	char c;
	char *str = "%d";
	y = ft_printf("%3c\n",0);
	x = printf("%3c\n",0);
	printf("prinf  %d et  ft %d\n",x,y);
	return 0;
}

// + ignorer xXoOpuUsScC
