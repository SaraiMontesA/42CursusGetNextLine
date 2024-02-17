/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:12:54 by sarmonte          #+#    #+#             */
/*   Updated: 2024/02/17 02:02:27 by sarmonte         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	//printf("Estoy en ft_bzero\n");	// FALTA QUITAR, ES SOLO PARA PRUEBAS ########################################

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

static void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*pointer;

	//printf("Estoy en ft_calloc\n");	// FALTA QUITAR, ES SOLO PARA PRUEBAS ########################################

	pointer = malloc(element_size * num_elements);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, element_size * num_elements);
	return (pointer);
}

// Principal function
/* -------------------------------------------------------------------------- */
/* Function to read data from the file and append it to partial content.      */
/* -------------------------------------------------------------------------- */
static char *read_from_file(int fd)
{
 int   bytes_read;
 char  *cup_buffer;
 static int count = 1;

 printf("ft_calloc#[%d]---", count++);
 cup_buffer = ft_calloc (3 + 1, sizeof(char));
 if (cup_buffer == NULL)
  return (NULL);
 bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
 if (bytes_read <= 0)
  return (free (cup_buffer), NULL);
 return (cup_buffer);
}

/* -------------------------------------------------------------------------- */
/* The get_next_line function to get the next line from the file descriptor.  */
/* -------------------------------------------------------------------------- */
char *get_next_line(int fd)
{
 char *basin_buffer;

 basin_buffer = read_from_file(fd);
 return (basin_buffer);
}