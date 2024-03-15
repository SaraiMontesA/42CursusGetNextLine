/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:13:08 by sarmonte          #+#    #+#             */
/*   Updated: 2024/03/15 17:21:22 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** @brief      Busca un caracter (definido por c) en una cadena de caracteres.
 **
 ** @param[in]  s puntero a la cadena de caracteres.
 ** @param[in]  c es el caracter a buscar.
 **
 ** @return     devuelve un puntero a char
*/
char	*ft_strchr(char const *s, int c)
{
	while (*s && *s != (unsigned char)c)
		++s;
	if (*s == (unsigned char)c)
		return ((char *)(unsigned long)s);
	else
		return (0);
}
/*
 ** @brief      Mide la longitud de una cadena de caracteres.
 **
 ** @param[in]  str puntero de la cadena de caracteres a medir.
 **
 ** @return     devuelve un size_t.
*/
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
/*
 ** @brief      Mide la longitud de una cadena de caracteres hasta \\n.
 **
 ** @param[in]  str puntero de la cadena de caracteres a medir.
 **
 ** @return     devuelve un size_t.
*/
size_t	ft_strlen_hasta_barran(char *str) //TODO poner el nombre en ingles
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

/*
 ** @brief      Duplica una cadena de caracteres.
 **
 ** @param[in]  str puntero de la cadena de caracteres a duplicar.
 **
 ** @return     devuelve un puntero a char (hace malloc).
*/
char	*ft_strdup(char const *str)
{
	char	*dup;
	char	*ptr;

	dup = malloc(sizeof (*dup) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (dup);
}

/*
 ** @brief      Copia n caracteres desde src a dst.
 **
 ** @param[in]  scr Cadena de origen.
 ** @param[in]  scr Cadena de destino.
 ** @param[in]  n Cantidad de caracteres a copiar.
 **
 ** @return     No devuelve nada.
*/
void	ft_memcpy(char *src, char *dst, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

/*
 ** @brief      Concatena dos cadenas de char en una tercera cadena(nueva) .
 **
 ** @param[in]  s1 Primera cadena.
 ** @param[in]  s2 Segunda cadena.
 **
 ** @return     Devuelve s3, tercera cadena, nueva, creada con malloc.
*/
char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, s1_len);
	ft_memcpy(s3 + s1_len, s2, s2_len);
	s3[s1_len + s2_len] = '\0';
	free(s1);
	return (s3);
}

/*
 ** @brief      Extrae una subcadena de una cadena de caracteres.
 **
 ** @param[in]  str Cadena de caracteres original.
 ** @param[in]  start Posición de inicio.
 ** @param[in]  size Tamaño a extraer.
 **
 ** @return     Devuelve una tercera cadena, nueva, creada con malloc.
*/
//  (hace malloc)
char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	len = ft_strlen(str);
	if (start >= len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	sub = malloc(sizeof (*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}
