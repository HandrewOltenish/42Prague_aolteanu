SERVER = server
SERVER_SOURCE = server.c
CLIENT = client
CLIENT_SOURCE = client.c
INCLUDES_SOURCE = utils/ft_atoi.c utils/ft_itoa.c
OBJS = ${INCLUDES_SOURCE:.c=.o}
LIBC = ar rcs
NAME = minitalk.a
HEADER = minitalk.h
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
MAKEDEPEND = $(CC) $(CFLAGS) $< \
               | sed -n 's,^\# *[0-9][0-9]* *"\([^"<]*\)".*,$@: \1\n\1:,p' \
               | sort -u > $*.d
depend: ${MAKEDEPEND}
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
	${RM} ${OBJS} ${SERVER} ${CLIENT} ${DEPEND_FILE}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
