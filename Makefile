# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azari <azari@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 20:39:15 by azari             #+#    #+#              #
#    Updated: 2022/11/01 12:19:30 by azari            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS =  -Wall -Werror -Wextra
CFILES = ft_printf.c ft_printf_utils.c ft_printf_printers.c 
OFILES = ${CFILES:.c=.o}

all : ${NAME}

${NAME} : ${OFILES}
	ar -crs ${NAME} ${OFILES}

%.o:%.c ft_printf.h
	${CC} -c ${FLAGS} $<

clean :
	rm -f ${OFILES} ${BONUSO}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY: clean fclean re all