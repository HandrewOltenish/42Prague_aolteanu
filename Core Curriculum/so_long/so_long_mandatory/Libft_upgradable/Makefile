# Variables
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS = ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c \
		ft_lstsize.c ft_lstiter.c ft_lstmap.c ft_lstlast.c
FT_PRINTF = ft_printf.c ft_printf_cops.c
GET_NEXT_LINE = get_next_line.c get_next_line_utils.c
GET_NEXT_LINE_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

# Derived variables
OBJS = $(SRCS:.c=.o) $(FT_PRINTF:.c=.o) $(GET_NEXT_LINE:.c=.o)
BNS = $(BONUS:.c=.o) $(GET_NEXT_LINE_BONUS:.c=.o)
NAME = libft.a

# Tools
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Compilation rule
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Target rules
$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(BNS)
	$(LIBC) $(NAME) $(OBJS) $(BNS)

clean:
	$(RM) $(OBJS) $(BNS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
