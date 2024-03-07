/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:13:08 by sarmonte          #+#    #+#             */
/*   Updated: 2024/03/07 17:01:51 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Unmodified from Libft.
 */

#include "get_next_line.h"

/*
 ** @brief      Locate a character in string.
 **
 ** "The strchr() function locates the first occurrence of c (converted to a
 ** char) in the string pointed to by s.  The terminating null character is
 ** considered to be part of the string; therefore if c is ‘\0’, the functions
 ** locate the terminating ‘\0’."
 **
 ** @see        STRCHR(3) <string.h>
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
 ** @brief      Find length of string.
 **
 ** "The strlen() function computes the length of the string s.  The strnlen()
 ** function attempts to compute the length of s, but never scans beyond the **
 ** first maxlen bytes of s."
 **
 ** @see        STRLEN(3) <string.h>
 */
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlen_hasta_barran(char *str)
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
 ** @brief      Save a copy of a string.
 **
 ** "The strdup() function allocates sufficient memory for a copy of the string
 ** s1, does the copy, and returns a pointer to it.  The pointer may
 ** subsequently be used as an argument to the function free(3)."
 **
 ** @see        STRDUP(3) <string.h>
 */

char	*ft_strdup(char const *str)
{
	char	*dup;
	char	*ptr;

	dup = malloc (sizeof (*dup) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (dup);
}

void	ft_memcpy(char *dst, char *src, size_t n)
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
 ** @brief      Concatenate two strings into a new string (with malloc).
 **
 ** @param[in]  s1 the first string (will be free).
 ** @param[in]  s2 the second string.
 ** @return     A string made of s1 + s2 or NULL if malloc fail.
 */

char	*ft_strjoin_free_s1(char *s1, char *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	//Calcular el tamaño de s1 y s2
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	//Reservar s3
	s3 = malloc(sizeof(char) * (s1_len + s2_len + 1));
	//Si falla malloc devolver null
	if (s3 == NULL)
		return (NULL);
	//Copiar s1 en s3
	ft_memcpy(s3, s1, s1_len);
	//Copiar s2 en s3
	ft_memcpy(s3 + s1_len, s2, s2_len);
	//Añadir el terminador de cadena a s3
	s3[s1_len + s2_len] = '\0';
	//Liberar s1
	free(s1);
	//Devolver s3
	return (s3);
	//Fin de la función
}

/*
 ** @brief      Extract substring from string.
 **
 ** "Allocates (with malloc(3)) and returns a substring from the string s.
 ** The substring begins at index start and is of maximum size len."
 **
 ** @param[in]  str the string that contain the cherished substring.
 ** @param[in]  start the beginning of the substring.
 ** @param[in]  size the length of the substring.
 ** @return     The cherished substring or NULL if malloc fail.
 */

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	len = ft_strlen (str);
	if (start >= len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	sub = malloc (sizeof (*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}
