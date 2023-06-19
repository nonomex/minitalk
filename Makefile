NAME 	= global

SERVER 	= server

CLIENT	= client

SRCS		= utils.c

SRCS_SERVER	= server.c

SRCS_CLIENT = client.c

CC 		= cc

CFLAGS	= -Wextra -Wall -Werror 

OBJS			= ${SRCS:.c=.o}

OBJS_SERVER 	= $(SRCS_SERVER:.c=.o)

OBJS_CLIENT		= $(SRCS_CLIENT:.c=.o)

HEADERS	= minitalk.h

%.o : %.c ${HEADERS} Makefile
	${CC} ${CFLAGS} -c $< -o $@ -I $(HEADERS)

${NAME}: ${OBJS} ${SERVER} ${CLIENT}

${SERVER}: ${OBJS} ${OBJS_SERVER}
		cc ${OBJS_SERVER} ${OBJS} -o ${SERVER}

${CLIENT}: ${OBJS} ${OBJS_CLIENT}
		cc ${OBJS_CLIENT} ${OBJS} -o ${CLIENT}

all: ${NAME}

clean: 
	rm -f ${OBJS_CLIENT} ${OBJS_SERVER} ${OBJS}

fclean: clean
	rm -f ${SERVER} ${CLIENT}

re: fclean all

.PHONY: clean re fclean
