#include "ft_printf.h"

int main(int argc, const char *argv[])
{
	printf("%012o\n\n" -255);
	ft_printf("%d\n", ft_printf("2chiffre 1 %+050d chiffre 2 %+050d\n", -42, 42));
	printf("%d\n\n", printf("2chiffre 1 %+   d chiffre 2 %+ d\n\n", -42, 42));

	ft_printf("%d\n", ft_printf("3chiffre 1 %12d chiffre 2 %12d\n", 42, -42));
	printf("%d\n\n", printf("3chiffre 1 %12d chiffre 2 %12d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));
	printf("%d\n\n", printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));
	printf("%d\n\n", printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
	printf("%d\n\n", printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));
	printf("%d\n\n", printf("7chiffre 1 %-012d chiffre 2 %012d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("9chiffre 1 %+d chiffre 2 %+d\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("10chiffre 1 %+12d chiffre 2 %+12d\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("10chiffre 1 %+12d chiffre 2 %+12d\n\n", 42, 6, -42, 6));

	printf("%d\n\n", printf("12chiffre 1 %-+10X chiffre 2 %-+10d\n\n", 42, -42));  
	ft_printf("%d\n", ft_printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42));

	ft_printf("%d\n", ft_printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42));
	printf("%d\n\n", printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));
	printf("%d\n\n", printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
	printf("%d\n\n", printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("16chiffre 1 %.6d chiffre 2 %.6d\n", 42, -42));
	printf("%d\n\n", printf("16chiffre 1 %.6d chiffre 2 %.6d\n\n", 42, -42));

	/* Memes tests avec les %c */

	ft_printf("%d\n", ft_printf("1caractere 1 %c caractere 2 %c\n", 'a', 'c'));
	printf("%d\n\n", printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("2caractere 1 %   c caractere 2 % c\n", 'a', 'c'));
	printf("%d\n\n", printf("3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("4caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));
	printf("%d\n\n", printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("4caractere 1 %-12c caractere 2 %-12c\n", 'a', 'c'));
	printf("%d\n\n", printf("4caractere 1 %-12c caractere 2 %-12c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("5caractere 1 %0c caractere 2 %0c\n", 'a', 'c'));
	printf("%d\n\n", printf("5caractere 1 %0c caractere 2 %0c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("6caractere 1 %012c caractere 2 %012c\n", 'a', 'c'));
	printf("%d\n\n", printf("6caractere 1 %012c caractere 2 %012c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("7caractere 1 %-012c caractere 2 %012c\n", 'a', 'c'));
	printf("%d\n\n", printf("7caractere 1 %-012c caractere 2 %012c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("8caractere 1 %*c caractere 2 %*c\n", 'a', 6, 6, 6));
	printf("%d\n\n", printf("8caractere 1 %*c caractere 2 %*c\n\n", 'a', 6, 6, 6));

	ft_printf("%d\n", ft_printf("9caractere 1 %+c caractere 2 %+c\n", 'a', 6, 'c', 6));
	printf("%d\n\n", printf("9caractere 1 %+c caractere 2 %+c\n\n", 'a', 6, 'c', 6));

	ft_printf("%d\n", ft_printf("10caractere 1 %+12c caractere 2 %+12c\n", 'a', 6, 'c', 6));
	printf("%d\n\n", printf("10caractere 1 %+12c caractere 2 %+12c\n\n", 'a', 6, 'c', 6));

	ft_printf("%d\n", ft_printf("11caractere 1 %*12c caractere 2 %*12c\n", 'a', -6, 'a', 6));
	printf("%d\n\n", printf("11caractere 1 %*12c caractere 2 %*12c\n\n", 'a', -6, 'a', 6));

	ft_printf("%d\n", ft_printf("12caractere 1 %-+5c caractere 2 %-+5c\n", 'a', 'c'));
	printf("%d\n\n", printf("12caractere 1 %-+5c caractere 2 %-+5c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("13caractere 1 %-+05c caractere 2 %-+05c\n", 'a', 'c'));
	printf("%d\n\n", printf("13caractere 1 %-+05c caractere 2 %-+05c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("14caractere 1 %+-5c caractere 2 %+-5c\n", 'a', 'c'));
	printf("%d\n\n", printf("14caractere 1 %+-5c caractere 2 %+-5c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("15caractere 1 %.c caractere 2 %.c\n", 'a', 'c'));
	printf("%d\n\n", printf("15caractere 1 %.c caractere 2 %.c\n\n", 'a', 'c'));

	ft_printf("%d\n", ft_printf("16caractere 1 %.6c caractere 2 %.6c\n", 'a', 'c'));
	printf("%d\n\n", printf("16caractere 1 %.6c caractere 2 %.6c\n\n", 'a', 'c'));

	/* Memes tests avec les %o */

	ft_printf("%d\n", ft_printf("1octal 1 %o octal 2 %o\n", 42, -42));
	printf("%d\n\n", printf("1octal 1 %o octal 2 %o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("2octal 1 %   o octal 2 % o\n", 42, -42));
	printf("%d\n\n", printf("3octal 1 %   o octal 2 % o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42));
	printf("%d\n\n", printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));
	printf("%d\n\n", printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42));
	printf("%d\n\n", printf("5octal 1 %0o octal 2 %0o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42));
	printf("%d\n\n", printf("6octal 1 %012o octal 2 %012o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));
	printf("%d\n\n", printf("7octal 1 %-012o octal 2 %012o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));
	printf("%d\n\n", printf("8octal 1 %*o octal 2 %*o\n\n", 42, 6, 6, 6));

	ft_printf("%d\n", ft_printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("9octal 1 %+o octal 2 %+o\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("10octal 1 %+12o octal 2 %+12o\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));
	printf("%d\n\n", printf("11octal 1 %*12o octal 2 %*12o\n\n", 42, -6, -42, 6));

	ft_printf("%d\n", ft_printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));
	printf("%d\n\n", printf("12octal 1 %-+5o octal 2 %-+5o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));
	printf("%d\n\n", printf("13octal 1 %-+05o octal 2 %-+05o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));
	printf("%d\n\n", printf("14octal 1 %+-5o octal 2 %+-5o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42));
	printf("%d\n\n", printf("15octal 1 %.o octal 2 %.o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
	printf("%d\n\n", printf("16octal 1 %.6o octal 2 %.6o\n\n", 42, -42));

	/* Memes tests avec les %o */

	ft_printf("%d\n", ft_printf("1octal 1 %o octal 2 %o\n", 42, -42));
	printf("%d\n\n", printf("1octal 1 %o octal 2 %o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("2octal 1 %   o octal 2 % o\n", 42, -42));
	printf("%d\n\n", printf("3octal 1 %   o octal 2 % o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4octal 1 %12o octal 2 %12o\n", 42, -42));
	printf("%d\n\n", printf("4octal 1 %12o octal 2 %12o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4octal 1 %-12o octal 2 %-12o\n", 42, -42));
	printf("%d\n\n", printf("4octal 1 %-12o octal 2 %-12o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("5octal 1 %0o octal 2 %0o\n", 42, -42));
	printf("%d\n\n", printf("5octal 1 %0o octal 2 %0o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("6octal 1 %012o octal 2 %012o\n", 42, -42));
	printf("%d\n\n", printf("6octal 1 %012o octal 2 %012o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("7octal 1 %-012o octal 2 %012o\n", 42, -42));
	printf("%d\n\n", printf("7octal 1 %-012o octal 2 %012o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("8octal 1 %*o octal 2 %*o\n", 42, 6, 6, 6));
	printf("%d\n\n", printf("8octal 1 %*o octal 2 %*o\n\n", 42, 6, 6, 6));

	ft_printf("%d\n", ft_printf("9octal 1 %+o octal 2 %+o\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("9octal 1 %+o octal 2 %+o\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("10octal 1 %+12o octal 2 %+12o\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("10octal 1 %+12o octal 2 %+12o\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("11octal 1 %*12o octal 2 %*12o\n", 42, -6, -42, 6));
	printf("%d\n\n", printf("11octal 1 %*12o octal 2 %*12o\n\n", 42, -6, -42, 6));

	ft_printf("%d\n", ft_printf("12octal 1 %-+5o octal 2 %-+5o\n", 42, -42));
	printf("%d\n\n", printf("12octal 1 %-+5o octal 2 %-+5o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("13octal 1 %-+05o octal 2 %-+05o\n", 42, -42));
	printf("%d\n\n", printf("13octal 1 %-+05o octal 2 %-+05o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("14octal 1 %+-5o octal 2 %+-5o\n", 42, -42));
	printf("%d\n\n", printf("14octal 1 %+-5o octal 2 %+-5o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("15octal 1 %.o octal 2 %.o\n", 42, -42));
	printf("%d\n\n", printf("15octal 1 %.o octal 2 %.o\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("16octal 1 %.6o octal 2 %.6o\n", 42, -42));
	printf("%d\n\n", printf("16octal 1 %.6o octal 2 %.6o\n\n", 42, -42));

	/* Memes tests avec les %x */
	/*

	ft_printf("%d\n", ft_printf("1hexa 1 %x hexa 2 %x\n", 42, -42));
	printf("%d\n\n", printf("1hexa 1 %x hexa 2 %x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("2hexa 1 %   x hexa 2 % x\n", 42, -42));
	printf("%d\n\n", printf("3hexa 1 %   x hexa 2 % x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4hexa 1 %12x hexa 2 %12x\n", 42, -42));
	printf("%d\n\n", printf("4hexa 1 %12x hexa 2 %12x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4hexa 1 %-12x hexa 2 %-12x\n", 42, -42));
	printf("%d\n\n", printf("4hexa 1 %-12x hexa 2 %-12x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("5hexa 1 %0x hexa 2 %0x\n", 42, -42));
	printf("%d\n\n", printf("5hexa 1 %0x hexa 2 %0x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("6hexa 1 %012x hexa 2 %012x\n", 42, -42));
	printf("%d\n\n", printf("6hexa 1 %012x hexa 2 %012x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("7hexa 1 %-012x hexa 2 %012x\n", 42, -42));
	printf("%d\n\n", printf("7hexa 1 %-012x hexa 2 %012x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("8hexa 1 %*x hexa 2 %*x\n", 42, 6, 6, 6));
	printf("%d\n\n", printf("8hexa 1 %*x hexa 2 %*x\n\n", 42, 6, 6, 6));

	ft_printf("%d\n", ft_printf("9hexa 1 %+x hexa 2 %+x\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("9hexa 1 %+x hexa 2 %+x\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("10hexa 1 %+12x hexa 2 %+12x\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("10hexa 1 %+12x hexa 2 %+12x\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("11hexa 1 %*12x hexa 2 %*12x\n", 42, -6, -42, 6));
	printf("%d\n\n", printf("11hexa 1 %*12x hexa 2 %*12x\n\n", 42, -6, -42, 6));

	ft_printf("%d\n", ft_printf("12hexa 1 %-+5x hexa 2 %-+5x\n", 42, -42));
	printf("%d\n\n", printf("12hexa 1 %-+5x hexa 2 %-+5x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("13hexa 1 %-+05x hexa 2 %-+05x\n", 42, -42));
	printf("%d\n\n", printf("13hexa 1 %-+05x hexa 2 %-+05x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("14hexa 1 %+-5x hexa 2 %+-5x\n", 42, -42));
	printf("%d\n\n", printf("14hexa 1 %+-5x hexa 2 %+-5x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("15hexa 1 %.x hexa 2 %.x\n", 42, -42));
	printf("%d\n\n", printf("15hexa 1 %.x hexa 2 %.x\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("16hexa 1 %.6x hexa 2 %.6x\n", 42, -42));
	printf("%d\n\n", printf("16hexa 1 %.6x hexa 2 %.6x\n\n", 42, -42));


	ft_printf("%d\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("%d\n\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("2hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
	printf("%d\n\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
	printf("%d\n\n", printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("%d\n\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("%d\n\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n\n", printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n", 42, 6, 6, 6));
	printf("%d\n\n", printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6));

	ft_printf("%d\n", ft_printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
	printf("%d\n\n", printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n\n", 42, 6, -42, 6));

	ft_printf("%d\n", ft_printf("11hexa-maj 1 %*12X hexa-maj 2 %*12X\n", 42, -6, -42, 6));
	printf("%d\n\n", printf("11hexa-maj 1 %*12X hexa-maj 2 %*12X\n\n", 42, -6, -42, 6));

	ft_printf("%d\n", ft_printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
	printf("%d\n\n", printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
	printf("%d\n\n", printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
	printf("%d\n\n", printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
	printf("%d\n\n", printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n\n", 42, -42));

	ft_printf("%d\n", ft_printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
	printf("%d\n\n", printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n\n", 42, -42));
*/
	return 0;
}
