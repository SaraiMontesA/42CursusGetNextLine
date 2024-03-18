/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:12:54 by sarmonte          #+#    #+#             */
/*   Updated: 2024/03/18 01:16:47 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

/*
 ** @brief      Extrae la primera línea de la cadena a la que apunta temp y 
 **				desplaza la dirección de temp al comienzo de la siguiente línea o NULL si 
 **				se alcanza el final de la cadena.
 **
 ** @param[in]  temp un puntero estático a la primera línea.
 ** @param[out] temp un puntero estático a la siguiente línea: temp + ft_strlen(line)
 **
 ** @return     La primera línea a la que apuntaba temp o NULL..
*/
static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		++ptr;
	ptr += (*ptr == '\n');
	line = ft_substr(*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr(ptr, 0, ft_strlen(ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

/*
 ** @brief      Lee el contenido del archivo al que apunta fd.
 **
 ** @param[in]  fd un descriptor de archivo que apunta a un archivo.
 ** @param[in]  temp un puntero estático al contenido leído.
 **
 ** @return     Un puntero a:
 **             - una línea, si BUFFER_SIZE es menor que una línea.
 **             - una línea + más, si BUFFER_SIZE es mayor que una línea
 **               o si no es la primera llamada a get_next_line para este fd.
 **             - NULL si no queda nada por leer en fd.
*/
static char	*ft_read(char *temp, int fd, char *buf)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr(temp, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		buf[r] = 0;
		temp = ft_strjoin_free_s1(temp, buf);
		if (!temp)
		{
			free(buf);
			return (NULL);
		}
	}
	free (buf);
	return (temp);
}

//Por pasos:

/*
	Paso 1:
	Leer del fd al buffer
	Añadir del buffer a la linea
	Devolver la linea

	Paso 4:
	Mover el resto guardado desde el buffer a la linea
	Mientras no encuentro \n en la linea
		Leer del fd al buffer
		Gestionar errores
		Gestionar si he terminado de leer
		Terminar el buffer en \0
		Añadir cosas del buffer a la linea
			(hasta \n si hay \n, si no hasta el final)
	Mover el resto al principio del buffer
	Devolver la linea
*/


char	*get_next_line(int fd)
{
	static char	temp[BUFFER_SIZE + 1];
	char 		*line;
	ssize_t		bytes_leidos_por_read;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);

	// Compruebo que el buffer no sea nulo
	if (temp[fd] == NULL)
		temp[fd] = ft_strdup("");

	//1. Leer del fd al buffer una vez y copiar a la linea (hacer un malloc)
	// Copio el contenido del buffer a la linea
	line = ft_strdup(temp);

	// Libero el buffer
	free(temp);

	//2. Leer del fd al buffer varias veces y ampliar la linea
		// (hacer varios mallocs, liberar los mallocs anteriores)
	// Mientras no encuentro \n en la linea
	while (!ft_strchr(line, '\n'))
	{
		// Leo del fd al buffer
		bytes_leidos_por_read = read(fd, temp, BUFFER_SIZE);
		// Gestiono errores
		if (bytes_leidos_por_read == -1)
		{
			// Libero el buffer
			free(temp);
			// Libero la linea
			free(line);
			// Devuelvo NULL
			return (NULL);
		}
		// Gestiono si he terminado de leer
		if (bytes_leidos_por_read == 0)
		{
			// Libero el buffer
			free(temp);
			// Devuelvo la linea
			return (line);
		}
		// Terminar el buffer en \0
		temp[bytes_leidos_por_read] = 0;

		// Añadir cosas del buffer a la linea
		// (hasta \n si hay \n, si no hasta el final)
		line = ft_strjoin_free_s1(line, temp);

		// Mover el resto al principio del buffer
		temp = ft_substr(temp, ft_strlen_hasta_barran(temp), ft_strlen(temp));
	}
	// Devuelvo la linea
	return (line);
}




/*
char	*get_next_line(int fd)
{
	char		*line;
	static char	temp[BUFFER_SIZE + 1];
	ssize_t		bytes_leidos_por_read;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp)
		temp = ft_strdup(""); 
	if (!temp)
		return (NULL);
	temp = ft_read(line, fd, temp);
	if (!temp)
		return (NULL);
	if (!*temp)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	return (ft_next(&temp));
}
*/
