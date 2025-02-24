NAME = so_long
BUILD_FOLDER = .build
SRC_FOLDER = src
INCLUDE_FOLDER = includes

FILES =	$(addprefix $(SRC_FOLDER)/, \
	main.c \
	events/on_key_press.c \
	events/on_key_release.c \
	events/on_destroy.c \
	init/init_game.c \
	setup/setup_game.c \
	map/parse_map.c \
	map/get_map_errors.c \
	map/handle_map.c \
	maths/check_collision.c \
	maths/geometry.c \
	update/collisions.c \
	update/time.c \
	update/update.c \
	draw/draw_img_on_screen.c \
	draw/draw_game.c \
	draw/draw_map.c \
	draw/draw_player.c \
	exit/clean.c \
	exit/exit_game.c \
)

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = clang
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(INCLUDE_FOLDER) -g3

LIBFT_FOLDER = libft
LIBFT_ARCHIVE = libft.a
LIBFT_FLAGS = -L$(LIBFT_FOLDER) -l$(shell echo $(LIBFT_ARCHIVE) | cut -c4- | rev | cut -c3- | rev)

# MLX_FOLDER = minilibx
# MLX_ARCHIVE = libmlx.a
# MLX_FLAGS = -L$(MLX_FOLDER) -l$(shell echo $(MLX_ARCHIVE) | cut -c4- | rev | cut -c3- | rev)
MLX_FLAGS = -lmlx

MATHS_FLAGS = -lm

X11_FLAGS = -L/usr/lib -lX11 -lXext

MAKEFLAGS = --no-print-directory

TEST = test.out
TEST_FLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_FOLDER)
TEST_MAIN = main.test.c

.PHONY: all clean fclean re test compile

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_ARCHIVE)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(X11_FLAGS) $(MATHS_FLAGS)

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_ARCHIVE):
	make -C $(LIBFT_FOLDER)

$(MLX_ARCHIVE):
	make -C $(MLX_FOLDER)

clean:
	rm -rf $(BUILD_FOLDER)
# $(MAKE) -C $(MLX_FOLDER) clean

fclean: clean
	rm -f $(NAME)

re: fclean 
	$(MAKE) all

$(TEST): $(NAME)
	@$(CC) $(TEST_MAIN) $(TEST_FLAGS) -L. -l$(shell echo $(NAME) | cut -c4- | rev | cut -c3- | rev) -o $(TEST)

test: $(TEST)
	@./$(TEST)
	@rm $(TEST)

-include $(DEPS)
