/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaget <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 02:20:27 by apaget            #+#    #+#             */
/*   Updated: 2016/01/25 23:07:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sSpdDiuOuUxXcC
// test passer sScCdixXpuU
// 			DoO

#include "ft_printf.h"

#define PRINT(x,y) printf(x,y); ; printf("\n") ; ft_printf(x,y); printf("\n\n");

int		ft_printf(char *str, ...)
{
	int cuunt_char;
	char *tmp;
	t_data data;
	va_list list;
	va_start(list, str);

	init_data(&data);
	cuunt_char = 0;
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			cuunt_char++;
		}
		else if (*str == '%' && *(str + 1) != '%')
		{
			if((tmp = load_conf(str + 1, &data)) != NULL)
			{
			str = tmp - 1;
			fill_empty_data(&data);
			//debug_print_cunf(&data);
			cuunt_char += make_str(&data,&list);
			}
			else
				ft_putchar(*str);
		}
		else
		{
			ft_putchar(*str);
			str++;
		}
		str++;
	}
	va_end(list);
	return (cuunt_char + 1);
}
int main(void)
{
PRINT("%o",255)
PRINT("%.o",255)
PRINT("%.10o",255)
PRINT("%.10o",255)
	PRINT("#10o : %#10o ",42)
	PRINT("#010o : %#010o ",42)
	PRINT("#-10o : %-#10o ",42)
	PRINT("#-010o : %-#010o ",42)
	PRINT("#10x : %#10x ",42)
	PRINT("#010x : %#010x ",42)
	PRINT("#-10x : %-#10x ",42)
	PRINT("#-010x : %-#010x ",42)
	PRINT("+020d %+020d",43)
	PRINT("+020d %+020d",-43)
	PRINT("% 020x",1000)
	PRINT("%.8x",1000)
	PRINT("%#030x",-1000)
	PRINT("%.10d",1000)
	PRINT("%-.10d",1000)
	PRINT("aa %hhd",1000)
	PRINT("%ld",1000)
	PRINT("%ld",1000)
	PRINT("%zd",1000)
	PRINT("%020d",1000)
	PRINT("%020.20d",1000)
	PRINT("%-020.20d",1000)
	PRINT("%zd",333333)
	PRINT("50d : %50d ",42)
	PRINT(".2d : %.2d ",42)
	PRINT(".10d : %.10d ",42)
	PRINT("-.10d : %-.10d ",42)
	PRINT(".0d : %.0d ",42)
	PRINT("#050d : %#050d ",42)
	PRINT("-020d : %-020d ",42)
	PRINT("s : %s ","Hellu ->");
	PRINT("-20.2s : %-20.2s ","Hellu ->");
	PRINT("40.2s : %40.2s ","Hellu ->");
	PRINT("c : %c ",'a')
	PRINT("10c : %10c ",'a')
	PRINT("010c : %010c ",'a')
	PRINT("x : %x",0xFF3678)
	PRINT("x : %x",-0xFF3678)
	PRINT("10x : %10x",0xFF3678)
	PRINT("-10x : %-10x",0xFF3678)
	PRINT("-10x : %-10x",0xFF3678)
	PRINT("-10x : %-10x",-0xFF3678)
	PRINT("010x : %010x",0xFF3678)
	PRINT("010x : %010x",-0xFF3678)
	PRINT("10x : %10x",0xFF3678)
	PRINT("#x : %#x",0xFF3678)
	PRINT("#050x : %#050x",0xFF3678)
	PRINT("X : %X",0xFF3678)
	PRINT("o : %o ",42)
	PRINT("-o : %-o ",-42)
	PRINT("50o : %50o ",42)
	PRINT(".2o : %.2o ",42)
	PRINT(".o : %.0o ",42)
	PRINT("S : %S ",L"Hellu ->");
	PRINT(".2S : %.2S ",L"Hellu ->");
	PRINT("-20.2S : %-20.2S ",L"sssssss");
	PRINT("40.2S : %40.2S ",L"sssssssss");
	PRINT("C : %C ",L'a')
	PRINT("u : %u ",42)
	PRINT("#u : %#u ",-42)
	PRINT("50u : %50u ",42)
	PRINT(".2u : %.2u ",42)
	PRINT(".u : %.0u ",42)
	return 0;
}
