# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaufert <tpaufert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 11:43:52 by hguillau          #+#    #+#              #
#    Updated: 2023/06/16 18:01:58 by tpaufert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=	src/main.c							\
				src/signaux/signaux.c				\
				src/errors/error.c					\
				src/builtins/pwd.c					\
				src/builtins/cd.c					\
				src/builtins/echo.c					\
<<<<<<< HEAD
				src/builtins/exit.c					\
=======
				src/execution/redir_exec_builtins.c	\
				src/execution/utils.c				\
>>>>>>> fad291485da4752dfaaa16eefacdd5291aa4c2a9
				src/execution/set_for_exec.c		\
				src/execution/exec.c				\
				src/lexer_parser/init.c				\
				src/lexer_parser/utils.c			\
				src/lexer_parser/lexer.c			\
				src/lexer_parser/lexer_alpha.c		\
				src/lexer_parser/quotes.c			\
				src/lexer_parser/redir.c			\
				src/lexer_parser/lexer_pipe.c		\
				src/lexer_parser/parsing.c			\
				src/lexer_parser/free_lexer.c		\
				src/utils/free.c					\

OBJS    	=	${SRCS:.c=.o}

NAME    	=	minishell

LIBS		=	./src/libft/

ifeq ($(USER), tpaufert)
RL			=	-L/Users/$(USER)/.brew/Cellar/readline/8.2.1/lib -lreadline
else
RL			=	-L/opt/homebrew/opt/readline/lib -lreadline
endif

CC      	=	gcc

RM      	=	rm -f

CFLAGS  	=	-Wall -Wextra -Werror #-g -fsanitize=address

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
