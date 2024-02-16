#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarmonte <sarmonte@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 12:32:19 by sarmonte          #+#    #+#              #
#    Updated: 2024/02/16 17:24:49 by sarmonte         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftget_next_line.a
INCLUDE	= 	get_next_line.h

SRC		=	get_next_line.c

OBJ		=	${SRC:.c=.o}

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):	${OBJ} 
	@echo "Compiling .."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}
	@echo "Done !"

clean:
	@echo "Remove .o  ..."
	${RM} ${OBJ}
	@echo "Done !"

fclean: clean
	@echo "Remove lib ..."
	${RM} $(NAME)
	@echo "Done !"

re: fclean all  