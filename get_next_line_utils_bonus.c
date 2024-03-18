/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:32:52 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/18 20:12:43 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 ** @brief      Searches for a character in a string.
 **
 ** @param[in]  s pointer to the string.
 ** @param[in]  c is the character to search for.
 **
 ** @return     returns a pointer to char
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
 ** @brief      Measures the length of a string.
 **
 ** @param[in]  str pointer to the string to measure.
 **
 ** @return     returns a size_t.
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
 ** @brief      Copies the string src into dst.
 **
 ** @param[in]  dst pointer to the destination string.
 ** @param[in]  src pointer to the source string.
 ** @param[in]  dstsize size of the destination buffer.
 **
 ** @return     returns a size_t.
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
 ** @brief      Duplicates a string.
 **
 ** @param[in]  str pointer to the string to duplicate.
 **
 ** @return     returns a pointer to char (does malloc).
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
 ** @brief      Concatenates two char strings into a third (new) string.
 **
 ** @param[in]  s1 First string.
 ** @param[in]  s2 Second string.
 **
 ** @return     Returns s3, third string, new, created with malloc.
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
