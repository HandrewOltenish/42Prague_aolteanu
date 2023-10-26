CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ./ft_isalpha.c \
	./ft_isdigit.c \
	
OBJ = $(SRC:.c=.o)
NAME = libft.h
all: $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
$(NAME): $(OBJ)
	cc $(OBJ)
	ar rcs $(NAME) $(OBJ)

.PHONY: all clean fclean re
#ar rcs - name of ar command for creating archives
#r - creating files
#c - create the archive
#s - writing object-file index into archive
