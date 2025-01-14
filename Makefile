NAME = pipex
BUILD_FOLDER = .build
INCLUDE_FOLDER = include \
	libft/include

FILES =	main.c

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

LIBFT_FOLDER = libft
LIBFT_ARCHIVE = libft.a
LIBFT_NAME = ft

INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_FOLDER))
CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP $(INCLUDE_FLAGS)

MAKEFLAGS = --no-print-directory

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L$(LIBFT_FOLDER) -l$(LIBFT_NAME)

$(BUILD_FOLDER)/%.o: %.c $(LIBFT_ARCHIVE)
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
