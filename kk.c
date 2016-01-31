/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kk.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:35:51 by                   #+#    #+#             */
/*   Updated: 2016/01/31 18:49:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "ft_printf.h"

void		print_wchar(wchar_t c);

int main(int argc, const char *argv[])
{
	char* l = setlocale(LC_ALL, "");
	if (l == NULL) {
		printf("Locale not set\n");
	} else {
		printf("Locale set to %s\n", l);
	}
	printf("%S\n",L"我是一只猫。");
	ft_printf("%S",L"我是一只猫。");
	return 0;
}
