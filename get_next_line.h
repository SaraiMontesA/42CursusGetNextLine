/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:33:32 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/17 02:07:21 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* #########################################
// #    INCLUDES OF EXTERNAL LIBRARIES     #
// #######################################*/

// Manual para hacerlo: https://medium.com/@lannur-s/gnl-c3cff1ee552b


// It is used to handle variable number of function arguments.
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>			// FALTA QUITAR, ES SOLO PARA PRUEBAS ########################################
#include <stdlib.h>			// ¿FALTA QUITAR?, ES PARA MALLOC ########################################

/* #########################################	
// #    LIST OF FUNCTIONS                  #
// #######################################*/

char	*get_next_line(int fd);
//FILE	*open_file(char *filename);

#endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif