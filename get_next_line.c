/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:12:54 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/16 18:07:16 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

// Function for open and close files
#include <stdio.h>

int open_file(char *filename)
{
    printf("Estoy en open file\n");
    printf("Archivo: %s\n", filename);
    
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: file not found\n");
        return (-1);
    }
    printf("File opened successfully\n");
    fclose(file);
    
    return (0);
}

// Principal function
char *get_next_line(int fd)
{
    char *filename;

    filename = "test.txt";
    printf("Estoy en get next line\n");
    printf("filename: %s\n", filename);
    printf("%i\n", fd);

    open_file(filename);

    return (filename);
}
