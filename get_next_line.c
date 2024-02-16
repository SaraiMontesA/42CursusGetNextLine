/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:12:54 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/16 17:30:26 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

// Principal function
char *get_next_line(int fd)
{
    char *line;

    line = "Hello, World!\n";
    write(1, line, 14);
    printf("%i", fd);

    return (line);
}
