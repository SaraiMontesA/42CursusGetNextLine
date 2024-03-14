/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:12:54 by sarmonte          #+#    #+#             */
/*   Updated: 2024/03/14 18:00:08 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** @brief      Extrae la primera línea de la cadena a la que apunta temp y 
 **				desplaza la dirección de temp al comienzo de la siguiente línea o NULL si 
 **				se alcanza el final de la cadena.
 **
 ** @param[in]  temp un puntero estático a la primera línea.
 ** @param[out] temp un puntero estático a la siguiente línea: temp + ft_strlen(line)
 ** @return     La primera línea a la que apuntaba temp o NULL..
 */
// 
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
	ptr = ft_substr (ptr, 0, ft_strlen(ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

/*
 ** @brief      Lee el contenido del archivo al que apunta fd.
 **
 ** @param[in]  fd un descriptor de archivo que apunta a un archivo.
 ** @param[in]  temp un puntero estático al contenido leído.
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
//1. Leer del fd al buffer una vez y copiar a la linea (hacer un malloc)
//2. Leer del fd al buffer varias veces y ampliar la linea
	// (hacer varios mallocs, liberar los mallocs anteriores)
//3. Dejar de leer cuando la linea tiene un \n, y devolver solo hasta el \n
//4. Añadir variable estática buffer, dejar en el buffer lo que no se ha
	// devuelto en la linea al final de la función y al principio añadir a
	// la linea lo que queda en el buffer

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
	char		*line;
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		bytes_leidos_por_read;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	if (!temp[fd])
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(temp[fd]);
		return (NULL);
	}
	temp[fd] = ft_read(temp[fd], fd, buf);
	if (!temp[fd])
		return (NULL);
	if (!*temp[fd])
	{
		free(temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&temp[fd]));
}
