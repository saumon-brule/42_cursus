NAME = so_long
BUILD_FOLDER = .build
SRC_FOLDER = src
INCLUDE_FLAGS = -Iinclude

FILES =	$(addprefix $(SRC_FOLDER)/, \
	main.c \
	init/init_game.c \
	init/init_sprites.c \
	events/on_key_press.c \
	events/on_destroy.c \
	setup/setup_game.c \
	update/handle_tile.c \
	update/move_player.c \
	map/parse_map.c \
	map/get_map_errors.c \
	map/handle_map.c \
	map/parse_util.c \
	map/check_map.c \
	map/flood_map.c \
	map/flood_map_utils.c \
	draw/draw_img_on_screen.c \
	draw/draw_game.c \
	draw/draw_map.c \
	draw/draw_player.c \
	draw/flush_window.c \
	exit/exit_game.c \
	exit/clean.c \
)

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP $(INCLUDE_FLAGS) -g3

LIBFT_FOLDER = libft
LIBFT_ARCHIVE = libft.a
LIBFT = $(LIBFT_FOLDER)/$(LIBFT_ARCHIVE)
LIBFT_INCLUDE_FLAGS = -I$(LIBFT_FOLDER)/include
LIBFT_FLAGS = -L$(LIBFT_FOLDER) -l$(shell echo $(LIBFT_ARCHIVE) | cut -c4- | rev | cut -c3- | rev)

MLX_FOLDER = mlx
MLX_ARCHIVE = libmlx.a
MLX = $(MLX_FOLDER)/$(MLX_ARCHIVE)
MLX_INCLUDE_FLAGS = -I$(MLX_FOLDER)
MLX_FLAGS = -L$(MLX_FOLDER) -l$(shell echo $(MLX_ARCHIVE) | cut -c4- | rev | cut -c3- | rev)

X11_FLAGS = -L/usr/lib -lX11 -lXext

MAKEFLAGS = --no-print-directory

TEST = test.out
TEST_FLAGS = -Wall -Wextra -Werror -g3 $(INCLUDE_FLAGS)
TEST_MAIN = main.test.c

.PHONY: all clean fclean re test compile FORCE

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(X11_FLAGS) $(MATHS_FLAGS)

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDE_FLAGS) $(MLX_INCLUDE_FLAGS) -c $< -o $@

$(LIBFT): FORCE
	make -C $(LIBFT_FOLDER)

$(MLX): FORCE
	make -C $(MLX_FOLDER)

clean:
	rm -rf $(BUILD_FOLDER)
# $(MAKE) -C $(MLX_FOLDER) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	$(MAKE) -C $(MLX_FOLDER) clean

re: fclean
	$(MAKE) all

$(TEST): $(NAME)
	@$(CC) $(TEST_MAIN) $(TEST_FLAGS) -L. -l$(shell echo $(NAME) | cut -c4- | rev | cut -c3- | rev) -o $(TEST)

test: $(TEST)
	@./$(TEST)
	@rm $(TEST)

-include $(DEPS)
