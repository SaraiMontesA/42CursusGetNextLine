/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:18:53 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/18 20:06:16 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
 ** @brief      Reads the content of the file pointed to by fd.
 **
 ** @param[in]  fd a file descriptor
 ** @param[out] buf a static pointer to the read content.
 **
 ** @return     The first line pointed to by temp or NULL.
*/
char	*read_line(int fd, char *buf)
{
	char	*line;
	int		countread;

	countread = 1;
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
		if (countread == 0)
			break ;
		buf[countread] = '\0';
		line = ft_strjoin_free_s1(line, buf, countread);
	}
	return (line);
}

/*
 ** @brief      Prepares the buffer for the next read.
 **
 ** @param[in]  *buf a static pointer to the read content.
 ** @param[in]  *line a pointer to the read line.
 ** @param[in]  *newline a pointer to the first occurrence of '\n' in line.
 **
 ** @return     Returns nothing.
 ** 		   - Copies the content of newline + 1 to buf.
 ** 		   - Copies the content of line to buf if newline is NULL.
 ** 		   - Sets the last character of line to '\0'.
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
 ** @brief      Main function that reads the content of a file.
 **
 ** @param[in]  fd a file descriptor that points to a file.
 **
 ** @return     A pointer to:
 **             - a line, if BUFFER_SIZE is less than a line.
 **             - a line + more, if BUFFER_SIZE is greater than a line.
 **               or if it is not the first call to get_next_line for this fd.
 **             - NULL if there is nothing left to read in fd.
*/
char	*get_next_line(int fd)
{
	static char	buf[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*newline;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, buf[fd]);
	if (!line || ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	prepare_buffer(buf[fd], line, newline);
	return (line);
}
