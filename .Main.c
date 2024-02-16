/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .Main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:46:50 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/16 17:13:02 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// ############### AQUÍ VAN LAS LIBRERÍAS QUE SE USARÁN ########################
#include "get_next_line.h"	// Para utilizar las funciones de get_next_line
#include <stdlib.h>			// Librería para utilizar clear en el encabezado
#include <stdio.h>			// Para printf

// ############### AQUÍ VAN LAS FUNCIONES QUE HACEN LOS TESTS ##################

/* Códigos de escape ANSI
	Códigos de colores para el texto
		\033[0;31m		Red
		\033[0;32m		Green
		\033[0;33m		Yellow
		\033[0;34m		Blue
		\033[0;35m		Purple
		\033[0;36m		Cyan
		\033[0m		Reset
	Códigos de colores para el fondo
		\033[41m		Red
		\033[42m		Green
		\033[43m		Yellow
		\033[44m		Blue
		\033[45m		Purple
		\033[46m		Cyan
		\033[40m		Reset
	Codigos de formato de texto
		\033[1m		Bold
		\033[4m		Underline
		\033[5m		Blink
		\033[7m		Reverse
		\033[8m		Blanking
		\033[0m		Reset
*/

// Test para %s
int	ft_test_string(char *nombre, char *value, char *str, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%s%s\033[0;34m-->\033[0m ", str, sep)
		== ft_printf("%s%s\033[0;34m-->\033[0m ", str, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %i
int	ft_test_integer(char *nombre, char *value, int num, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%i%s \033[0;34m-->\033[0m ", num, sep)
		== ft_printf("%i%s \033[0;34m-->\033[0m ", num, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %c
int	ft_test_char(char *nombre, char *value, char c, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%c%s \033[0;34m-->\033[0m ", c, sep)
		== ft_printf("%c%s \033[0;34m-->\033[0m ", c, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %d
int	ft_test_decimal(char *nombre, char *value, int dec, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);

	if (printf("%d%s \033[0;34m-->\033[0m ", dec, sep)
		== ft_printf("%d%s \033[0;34m-->\033[0m ", dec, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %u
int	ft_test_unsigned(char *nombre, char *value, unsigned int u_int, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%u%s \033[0;34m-->\033[0m ", u_int, sep)
		== ft_printf("%u%s \033[0;34m-->\033[0m ", u_int, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %x
int	ft_test_hex(char *nombre, char *value, int hex_int, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%x%s \033[0;34m-->\033[0m ", hex_int, sep)
		== ft_printf("%x%s \033[0;34m-->\033[0m ", hex_int, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %X
int	ft_test_hex2(char *nombre, char *value, int hex_int2, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%X%s \033[0;34m-->\033[0m ", hex_int2, sep)
		== ft_printf("%X%s \033[0;34m-->\033[0m ", hex_int2, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %p
int	ft_test_pointer(char *nombre, char *value, char *pointer, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%p%s \033[0;34m-->\033[0m ", pointer, sep)
		== ft_printf("%p%s \033[0;34m-->\033[0m ", pointer, sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %%
int	ft_test_percent(char *nombre, char *value, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("%%%s\033[0;34m -->\033[0m ", sep)
		== ft_printf("%%%s\033[0;34m -->\033[0m ", sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}

// Test para %#
int	ft_test_sharp(char *nombre, char *value, char *sep)
{
	printf("\033[0;34m%-12s --> \033[0;36m%-15s \033[0;34m--> \033[0m", nombre, value);
	fflush(stdout);
	if (printf("#%s\033[0;34m -->\033[0m ", sep)
		== ft_printf("#%s\033[0;34m -->\033[0m ", sep))
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mKO\033[0m\n");
	return (0);
}
// ############### AQUÍ VAN LAS FUNCIONES QUE LLAMAN A LOS TESTS ###############

//ft_printf_tests_string();		// %s
void	ft_printf_tests_string(void)
{
	char	*str;
	char	*value;
	char	*sep;

	printf("\033[0;33mTESTS OF PRINTF - s - string\033[0m\n");
	str = "+";
	value = "+";	sep = "\t\t\t ";
	ft_test_string("     Test1", value, str, sep);
	str = "Sarai Montes";
	value = "Sarai Montes";
	sep = "\t ";
	ft_test_string("     Test2", value, str, sep);
	str = "%s";
	value = "%s";
	sep = "\t\t\t ";
	ft_test_string("     Test3", value, str, sep);
	str = "\t";
	value = "\\t";
	sep = "\t\t ";
	ft_test_string("     Test4", value, str, sep);
	str = "''";
	value = "''";
	sep = "\t\t\t ";
	ft_test_string("     Test5", value, str, sep);
}

//ft_printf_tests_integer();		// %i
void	ft_printf_tests_integer(void)
{
	int		num;
	char	*value;
	char	*sep;

	printf("\033[0;33mTESTS OF PRINTF - i - integer\033[0m\n");
	num = 42;
	value = "42         ";
	sep = "\t\t\t";
	ft_test_integer("     Test1", value, num, sep);
	num = -42;
	value = "-42        ";
	sep = "\t\t";
	ft_test_integer("     Test2", value, num, sep);
	num = 2147483647;
	value = "2147483647";
	sep = "\t\t";
	ft_test_integer("     Test3", value, num, sep);
	num = 'S';
	value = "S";
	sep = "\t\t\t";
	ft_test_integer("     Test4", value, num, sep);
}

//ft_printf_tests_char();		// %c
void	ft_printf_tests_char(void)
{
	char	c;
	char	*value;
	char	*sep;

	sep = "\t\t\t";
	printf("\033[0;33mTESTS OF PRINTF - c - char\033[0m\n");
	c = 'S';
	value = "S          ";
	ft_test_char("     Test1", value, c, sep);
	c = '7';
	value = "7          ";
	ft_test_char("     Test2", value, c, sep);
	c = '\\';
	value = "\\          ";
	ft_test_char("     Test3", value, c, sep);
	c = '"';
	value = "'          ";
	ft_test_char("     Test4", value, c, sep);
	c = '\t';
	value = "\\t          ";
	sep = "\t\t";
	ft_test_char("     Test5", value, c, sep);
}

//ft_printf_tests_decimal();	// %d
void	ft_printf_tests_decimal(void)
{
	int		num;
	char	*value;
	char	*sep;

	printf("\033[0;33mTESTS OF PRINTF - d - decimal\033[0m\n");
	num = 42;
	value = "42         ";
	sep = "\t\t\t";
	ft_test_decimal("     Test1", value, num, sep);
	num = -42;
	value = "-42        ";
	sep = "\t\t";
	ft_test_decimal("     Test2", value, num, sep);
	num = 2147483647;
	value = "2147483647";
	sep = "\t\t";
	ft_test_decimal("     Test3", value, num, sep);
	num = 'S';
	value = "S";
	sep = "\t\t\t";
	ft_test_decimal("     Test4", value, num, sep);
}

//ft_printf_tests_unsigned();	// %u
void	ft_printf_tests_unsigned(void)
{
	unsigned int	num;
	char			*value;
	char			*sep;

	printf("\033[0;33mTESTS OF PRINTF - u - unsigned\033[0m\n");
	num = 42;
	value = "42         ";
	sep = "\t\t\t";
	ft_test_unsigned("     Test1", value, num, sep);
	num = -42;
	value = "-42        ";
	sep = "\t\t";
	ft_test_unsigned("     Test2", value, num, sep);
	num = 2147483647;
	value = "2147483647";
	sep = "\t\t";
	ft_test_unsigned("     Test3", value, num, sep);
	num = 'S';
	value = "S";
	sep = "\t\t\t";
	ft_test_unsigned("     Test4", value, num, sep);
}

//ft_printf_tests_hex();		// %x
void	ft_printf_tests_hex(void)
{
	int		hex_num;
	char	*value;
	char	*sep;

	printf("\033[0;33mTESTS OF PRINTF - x - hexadecimal\033[0m\n");
	hex_num = 42;
	value = "42         ";
	sep = "\t\t\t";
	ft_test_hex("     Test1", value, hex_num, sep);
	hex_num = -42;
	value = "-42        ";
	sep = "\t\t";
	ft_test_hex("     Test2", value, hex_num, sep);
	hex_num = 2147483647;
	value = "2147483647";
	sep = "\t\t";
	ft_test_hex("     Test3", value, hex_num, sep);
	hex_num = 'S';
	value = "S ";
	sep = "\t\t\t";
	ft_test_hex("     Test4", value, hex_num, sep);
}

//ft_printf_tests_hex2();		// %X
void	ft_printf_tests_hex2(void)
{
	int		hex_num2;
	char	*value;
	char	*sep;

	printf("\033[0;33mTESTS OF PRINTF - X - HEXADECIMAL\033[0m\n");
	hex_num2 = 42;
	value = "42         ";
	sep = "\t\t\t";
	ft_test_hex2("     Test1", value, hex_num2, sep);
	hex_num2 = -42;
	value = "-42        ";
	sep = "\t\t";
	ft_test_hex2("     Test2", value, hex_num2, sep);
	hex_num2 = 2147483647;
	value = "2147483647";
	sep = "\t\t";
	ft_test_hex2("     Test3", value, hex_num2, sep);
	hex_num2 = 'S';
	value = "S";
	sep = "\t\t\t";
	ft_test_hex2("     Test4", value, hex_num2, sep);
}

//ft_printf_tests_pointer();	// %p
void	ft_printf_tests_pointer(void)
{
	char	*str;
	char	*value;
	char	*sep;

	printf("\033[0;33mTESTS OF PRINTF - p - pointer\033[0m\n");
	str = "Hello world";
	value = "Hello world";
	sep = "\t";
	ft_test_pointer("     Test1", value, str, sep);
	str = "''";
	value = "''         ";
	sep = "\t";
	ft_test_pointer("     Test2", value, str, sep);
	str = "%s";
	value = "%s         ";
	sep = "\t";
	ft_test_pointer("     Test3", value, str, sep);
	str = "\t";
	value = "\\t";
	sep = "\t";
	ft_test_pointer("     Test4", value, str, sep);
}

//ft_printf_tests_percent();	// %%
void	ft_printf_tests_percent(void)
{
	char	*value;
	char	*sep;

	sep = "\t\t\t";
	printf("\033[0;33mTESTS OF PRINTF - %% - percent\033[0m\n");
	value = "           ";
	ft_test_percent("     Test1", value, sep);
}

//ft_printf_tests_sharp();		// %#
void	ft_printf_tests_sharp(void)
{
	char	*value;
	char	*sep;

	sep = "\t\t\t";
	printf("\033[0;33mTESTS OF PRINTF - # - sharp\033[0m\n");
	value = "           ";
	ft_test_sharp("     Test1", value, sep);
}
// ############### AQUÍ VAN LAS FUNCIONES DE ENCABEZADO Y FIRMA ################

// Función para imprimir el encabezado
void	ft_title(void)
{
	write(1, "\033[34m", 6);
	system("clear");
	write(1, "╔═════════════════════════════════════════════════════════════════════════════════════╗\n", 263);
	write(1, "║                                                                                     ║\n", 93);
	write(1, "║               \033[33mPrintf Sarai Tests\033[34m                                                    ║\n", 103);
	write(1, "║                                                                                     ║\n", 93);
	write(1, "╚═════════════════════════════════════════════════════════════════════════════════════╝\n", 263);
	write(1, "\033[0m\n", 6);
}

// Función para imprimir la firma
void	ft_signature(void)
{
	write(1, "\033[33m\n", 6);
	write(1, "                                                                               _      \n", 88);
	write(1, "                                                                    |\\__/|    ( \\     \n", 88);
	write(1, " By Sarai Montes                                                   _|o.o |_    ) )\033[34m    \n", 93);
	write(1, "╔═════════════════════════════════════════════════════════════════\033[33m(((\033[34m═══\033[33m(((\033[34m═══════════╗\n", 271);
	write(1, "║               \033[33mThanks for your time\033[34m                                                  ║\n", 103);
	write(1, "╚═════════════════════════════════════════════════════════════════════════════════════╝\n", 263);
	write(1, "\033[0m\n\n", 7);
}

// ############### AQUÍ VA EL MAIN #############################################
int	main(void)
{
	ft_title();
/*
*/
	ft_printf_tests_string();// %s
	ft_printf_tests_integer();// %i
	ft_printf_tests_char();// %c
	ft_printf_tests_decimal();// %d
	ft_printf_tests_unsigned();// %u
	ft_printf_tests_hex();// %x
	ft_printf_tests_hex2();// %X
	ft_printf_tests_pointer();// %p
	ft_printf_tests_percent();// %%	
	
	ft_signature();
	return (0);
}
