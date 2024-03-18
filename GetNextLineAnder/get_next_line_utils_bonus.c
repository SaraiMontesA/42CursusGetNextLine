/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:32:52 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/18 19:54:17 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
 ** @brief      Copia la cadena src en dst.
 **
 ** @param[in]  dst puntero de la cadena de caracteres destino.
 ** @param[in]  src puntero de la cadena de caracteres origen.
 ** @param[in]  dstsize tamaño del buffer de destino.
 **
 ** @return     devuelve un size_t.
*/

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

	if (src == NULL)
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

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = len;
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, s2_len + 1);
	free(s1);
	return (join);
}
