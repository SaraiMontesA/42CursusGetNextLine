/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:33:32 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/17 22:04:04 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ####################
// #     INCLUDES     #
// ##################*/

// Manual para hacerlo: https://medium.com/@lannur-s/gnl-c3cff1ee552b
// It is used to handle variable number of function arguments.
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>		// FALTA QUITAR, ES SOLO PARA PRUEBAS ####################################
# include <string.h>	// ¿FALTA QUITAR?, ES PARA STRcpy ########################################

/* ####################
// #     DEFINES      #
// ##################*/
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
#  define OPEN_MAX 1024
# endif

/* ####################
// #    PROTOTYPES    #
// ##################*/

/*
 ** get_next_line_utils.c
 **
 ** Libft functions required by get_next_line_utils.
 */

char	*ft_strchr(char const *s, int c);
size_t	ft_strlen(char const *str);
char	*ft_strdup(char const *s1);
char	*ft_strjoin_free_s1(char *s1, char const *s2);
char	*ft_substr(char const *str, unsigned int start, size_t size);

/*
 ** get_next_line.c
 **
 ** Read each line of the given file, one at a function call.
 */

/* static char *ft_next(char **temp) */
/* static char *ft_read(char *temp, int fd) */
char	*get_next_line(int fd);

#endif