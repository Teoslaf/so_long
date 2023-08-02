NAME    := so_long
CFLAGS  := -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX  := ../MLX42
LIBFT_DIR := ./libft

HEADERS := -I ./include -I $(LIBMLX)/include $(LIBFT_INC)
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT_LIB)
SRCS    := $(shell find ./src -iname "*.c") $(LIBFT_DIR)/libft.a
OBJS    := ${SRCS:.c=.o}

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft
