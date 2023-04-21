# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaufert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 11:43:52 by hguillau          #+#    #+#              #
#    Updated: 2023/04/21 17:10:06 by tpaufert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=	src/main.c						\
				src/signaux/signaux.c			\
				src/lexer_parser/init.c			\
				src/errors/error.c				\

OBJS    	=	${SRCS:.c=.o}

NAME    	=	minishell

LIBS		=	./src/libft/

#RL			=	-L/opt/homebrew/opt/readline/lib -lreadline 

ifeq ($(USER), tpaufert)
RL			=	-L/Users/$(USER)/.brew/Cellar/readline/8.2.1/lib -lreadline
else
RL			=
endif
CC      	=	gcc

RM      	=	rm -f

CFLAGS  	=	-Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			make all -C ${LIBS}
			${CC} ${CFLAGS} ${RL} -o ${NAME} ${OBJS} -L ${LIBS} -lft

clean:
			make clean -C ${LIBS}
			${RM} ${OBJS}

fclean:		clean
			make fclean -C ${LIBS}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
