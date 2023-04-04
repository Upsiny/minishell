# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 11:43:52 by hguillau          #+#    #+#              #
#    Updated: 2023/03/31 11:45:25 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=		includes/main.c		\

OBJS    	=		${SRCS:.c=.o}

NAME    	=		minishell

RL			=		-L/opt/homebrew/opt/readline/lib -lreadline

CC      	=		gcc -g

RM      	=		rm -f

CFLAGS  	=		-Wall -Wextra -Werror #-g -fsanitize=address

all:				${NAME}

${NAME}:			${OBJS}
					${CC} ${CFLAGS} ${RL} -o ${NAME} ${OBJS}

clean:
					${RM} ${OBJS}

fclean: 			clean
					${RM} ${NAME}

re:     			fclean all

bonus:				all

.PHONY: 			all clean fclean re
