NAME = so_long_experiment
CFLAGS = -Wall -Wextra -Werror -g
LIBMLX = ./MLX42
LIBFT = ./Libft_upgradable
HEADERS = -I ./include
LIBS = $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -lpthread -lm
SRCS = so_long_experiment.c
OBJS = $(SRCS:.c=.o)
all: libmlx libft $(NAME)
libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 -ldl -lglfw -lm -lpthread 
libft:
	make -C $(LIBFT)
$(OBJS): ${SRCS}
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"
$(NAME): $(OBJS)
	$(CC) ${CFLAGS} ${OBJS} ${LIBS} -o $(NAME)  && printf "Linking: $(NAME)\n"
clean:
	rm -f $(OBJS)
	make -C $(LIBMLX)/build clean
	make -C $(LIBFT) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all
.PHONY: all clean fclean re libmlx libft