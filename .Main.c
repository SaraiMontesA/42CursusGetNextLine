/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .Main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:46:50 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/17 19:13:07 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// ############### AQUÍ VAN LAS LIBRERÍAS QUE SE USARÁN ########################
#include "get_next_line.h"	// Para utilizar las funciones de get_next_line
#include <stdlib.h>			// Librería para utilizar clear en el encabezado
#include <stdio.h>			// Para printf
#include <fcntl.h>

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

/* // Test para %s
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

// ############### AQUÍ VAN LAS FUNCIONES QUE LLAMAN A LOS TESTS ###############

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

*/
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
	char	*filename;
	filename = "test.txt";

	int    fd;
	char  *next_line;
	int  count;

	ft_title();

	printf("Estoy en el main\n");

	count = 0;
	fd = open("test.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free(next_line);
		next_line = NULL;
	}

	close(fd);

	ft_signature();
	return (0);
}
