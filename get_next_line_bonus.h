/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:34:16 by dgomez-m          #+#    #+#             */
/*   Updated: 2024/03/18 20:15:32 by sarmonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// ####################
// #     INCLUDES     #
// ####################

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

// ####################
// #     DEFINES      #
// ####################

/*
 ** @brief      The minimum amount of characters (bytes) read by one
 **             get_next_line call on the given file descriptor.
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
 ** @brief      The maximum number of file that can be read simultaneously by
 **             get_next_line.
*/

# ifndef OPEN_MAX
#  define OPEN_MAX 512
# endif

// ####################
// #    PROTOTYPES    #
// ####################

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *src);
char	*ft_strjoin_free_s1(char *s1, char *s2, size_t len);

#endif