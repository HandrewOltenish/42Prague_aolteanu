SERVER = server
SERVER_SOURCE = server.c
CLIENT = client
CLIENT_SOURCE = client.c
INCLUDES_SOURCE = utils/ft_atoi.c utils/ft_itoa.c utils/ft_putnbr_fd.c
OBJS = ${INCLUDES_SOURCE:.c=.o}
LIBC = ar rcs
NAME = minitalk.a
HEADER = minitalk.h
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
${NAME}: ${OBJS} ${HEADER}
	${LIBC} ${NAME} ${OBJS}
	${CC} ${CFLAGS} ${SERVER_SOURCE} ${INCLUDES_SOURCE} -o ${SERVER}
	${CC} ${CFLAGS} ${CLIENT_SOURCE} ${INCLUDES_SOURCE} -o ${CLIENT}

${SERVER}: ${SERVER_SOURCE} ${INCLUDES_SOURCE} ${HEADER}
	${CC} ${CFLAGS} ${SERVER_SOURCE} ${INCLUDES_SOURCE} -o ${SERVER}

${CLIENT}: ${CLIENT_SOURCE} ${INCLUDES_SOURCE} ${HEADER}
	${CC} ${CFLAGS} ${CLIENT_SOURCE} ${INCLUDES_SOURCE} -o ${CLIENT}

all: ${NAME} ${SERVER} ${CLIENT}

clean:
	${RM} ${NAME} ${OBJS} ${SERVER} ${CLIENT}

fclean: clean
	${RM} ${NAME} ${OBJS} ${SERVER} ${CLIENT}

re: fclean all

.PHONY: all clean fclean re
