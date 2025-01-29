NAME = pipex
BUILD_FOLDER = .build
INCLUDE_FOLDER = include \
	./libft/include

FILES =	main.c \
	pipex.c \
	parsing_utils.c \
	exec_shell.c \
	pipex_utils.c \
	parse_args/char_type.c \
	parse_args/parse_dquote.c \
	parse_args/parse_neutral.c \
	parse_args/parse_squote.c \
	parse_args/parse_env.c

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

LIBFT_FOLDER = libft
LIBFT_ARCHIVE = libft.a
LIBFT_NAME = ft

INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_FOLDER))
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MD -MP $(INCLUDE_FLAGS)

MAKEFLAGS = --no-print-directory

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_ARCHIVE)
	$(CC) $(OBJS) -g3 -o $(NAME) -L$(LIBFT_FOLDER) -l$(LIBFT_NAME)

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_FOLDER)

clean:
	rm -rf $(BUILD_FOLDER)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_FOLDER)

re: fclean 
	$(MAKE) all

-include $(DEPS)
