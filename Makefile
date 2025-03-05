NAME = push_swap
BUILD_FOLDER = .build
HEADER_FOLDER = include
SRC_FOLDER = src

CONVERTER_FOLDER = converter
CONVERTER_FILES = ft_atoi.c \
	ft_itoa.c

FILES = $(addprefix $(SRC_FOLDER)/, \
	main.c \
	push_swap.c \
	push_swap_utils.c \
	parse_input.c \
	parsing_check/is_number.c \
	parsing_check/is_int.c \
)

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(HEADER_FOLDER) -I$(LIBFT_HEADER_FOLDER) -g3

LIBFT_FOLDER = libft
LIBFT_HEADERS = include
LIBFT_ARCHIVE = libft.a
LIBFT_HEADER_FOLDER = $(LIBFT_FOLDER)/$(LIBFT_HEADERS)
LIBFT_FLAGS = -L$(LIBFT_FOLDER) -l$(shell echo $(LIBFT_ARCHIVE) | cut -c4- | rev | cut -c3- | rev)

MAKEFLAGS = --no-print-directory

TEST_NAME = tester
TEST_FLAGS = -Wall -Wextra -Werror -I$(HEADER_FOLDER)
TEST_FILE = main.test.c

.PHONY: all clean fclean re test tester

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT_ARCHIVE)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) 

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_ARCHIVE):
	make -C $(LIBFT_FOLDER)

clean:
	rm -rf $(BUILD_FOLDER)
	$(MAKE) -C $(LIBFT_FOLDER) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)
	$(MAKE) -C $(LIBFT_FOLDER) fclean

re: fclean 
	$(MAKE) all

$(TEST_NAME):
	@$(MAKE) -s $(NAME) CFLAGS="$(CFLAGS) -g3"
	@$(CC) $(TEST_FLAGS) $(TEST_FILE) $(NAME) -g3 -o $(TEST_NAME)

test: $(TEST_NAME)
	@./$(TEST_NAME)
	@rm $(TEST_NAME)

-include $(DEPS)