/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:12:54 by sarmonte          #+#    #+#             */
/*   Updated: 2024/03/18 18:42:04 by sarmonte         ###   ########.fr       */
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
 **
 ** @return     La primera línea a la que apuntaba temp o NULL..
*/
char	*read_line(int fd, char *buf)
{
	char	*line;
	int		countread;

	countread = -2;
	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')) && countread != 0)
	{
		countread = read(fd, buf, BUFFER_SIZE);
		if (countread == -1)
		{
			free(line);
			buf[0] = '\0';
			return (NULL);
		}
		buf[countread] = '\0';
		line = ft_strjoin_free_s1(line, buf, countread);
	}
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

void	prepare_buffer(char *buf, char *line, char *newline)
{
	int	to_copy;

	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
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
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, buf);
	if (!line || ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	prepare_buffer(buf, line, newline);
	return (line);
}
