/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:13:08 by sarmonte          #+#    #+#             */
/*   Updated: 2024/03/18 16:03:13 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** @brief      Busca un caracter en una cadena de caracteres.
 **
 ** @param[in]  s puntero a la cadena de caracteres.
 ** @param[in]  c es el caracter a buscar.
 **
 ** @return     devuelve un puntero a char
*/
char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/*
 ** @brief      Mide la longitud de una cadena de caracteres.
 **
 ** @param[in]  str puntero de la cadena de caracteres a medir.
 **
 ** @return     devuelve un size_t.
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < srcsize && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

/*
 ** @brief      Duplica una cadena de caracteres.
 **
 ** @param[in]  str puntero de la cadena de caracteres a duplicar.
 **
 ** @return     devuelve un puntero a char (hace malloc).
*/
char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

/*
 ** @brief      Concatena dos cadenas de char en una tercera cadena(nueva) .
 **
 ** @param[in]  s1 Primera cadena.
 ** @param[in]  s2 Segunda cadena.
 **
 ** @return     Devuelve s3, tercera cadena, nueva, creada con malloc.
*/
char	*ft_strjoin_free_s1(char *s1, char *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = len;
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, s2_len + 1);
	free(s1);
	return (join);
}

/*
 ** @brief      Mide la longitud de una cadena de caracteres hasta \\n.
 **
 ** @param[in]  str puntero de la cadena de caracteres a medir.
 **
 ** @return     devuelve un size_t.
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
*/

/*
 ** @brief      Copia n caracteres desde src a dst.
 **
 ** @param[in]  scr Cadena de origen.
 ** @param[in]  scr Cadena de destino.
 ** @param[in]  n Cantidad de caracteres a copiar.
 **
 ** @return     No devuelve nada.
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
*/

/*
 ** @brief      Extrae una subcadena de una cadena de caracteres.
 **
 ** @param[in]  str Cadena de caracteres original.
 ** @param[in]  start Posición de inicio.
 ** @param[in]  size Tamaño a extraer.
 **
 ** @return     Devuelve una tercera cadena, nueva, creada con malloc.
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
*/
