/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:33:32 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/16 17:12:50 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* #########################################
// #    INCLUDES OF EXTERNAL LIBRARIES     #
// #######################################*/

// It is used to handle variable number of function arguments.
# include <stdarg.h>
# include <unistd.h>

/* #########################################	
// #    LIST OF FUNCTIONS                  #
// #######################################*/

char *get_next_line(int fd);

#endif