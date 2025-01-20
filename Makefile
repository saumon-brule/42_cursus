NAME = libft.a
BUILD_FOLDER = .build
HEADER_FOLDER = include
SRC_FOLDER = src

CONVERTER_FOLDER = converter
CONVERTER_FILES = ft_atoi.c \
	ft_itoa.c

FREE_FOLDER = free
FREE_FILES = free_split.c \
	free_n.c

FT_PRINTF_FOLDER = ft_printf
FT_PRINTF_FILES = ft_vfprintf.c \
	ft_printf.c \
	ft_dprintf.c \
	handle_flag.c \
	ft_vfprintf_utils.c \
	flags/flag_c.c \
	flags/flag_i.c \
	flags/flag_low_x.c \
	flags/flag_p.c \
	flags/flag_s.c \
	flags/flag_u.c \
	flags/flag_up_x.c

GET_NEXT_LINE_FOLDER = get_next_line
GET_NEXT_LINE_FILES = get_next_line.c \
	get_next_line_utils.c

IDENTIFER_FOLDER = identifier
IDENTIFER_FILES = ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isupper.c

MATHS_FOLDER = maths
MATHS_FILES = arrmax.c \
	arrmin.c \
	max.c \
	min.c

LIST_FOLDER = list
LIST_FILES = ft_lstadd_back.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

MEMORY_FOLDER = memory
MEMORY_FILES = ft_bzero.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c

STRING_FOLDER = string
STRING_FILES = ft_split.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strstr.c \
	ft_strtok.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_toupper.c \
	ft_tolower.c

FILES = $(addprefix $(SRC_FOLDER)/, \
	$(addprefix $(CONVERTER_FOLDER)/, $(CONVERTER_FILES)) \
	$(addprefix $(FREE_FOLDER)/, $(FREE_FILES)) \
	$(addprefix $(FT_PRINTF_FOLDER)/, $(FT_PRINTF_FILES)) \
	$(addprefix $(GET_NEXT_LINE_FOLDER)/, $(GET_NEXT_LINE_FILES)) \
	$(addprefix $(IDENTIFER_FOLDER)/, $(IDENTIFER_FILES)) \
	$(addprefix $(LIST_FOLDER)/, $(LIST_FILES)) \
	$(addprefix $(MATHS_FOLDER)/, $(MATHS_FILES)) \
	$(addprefix $(MEMORY_FOLDER)/, $(MEMORY_FILES)) \
	$(addprefix $(STRING_FOLDER)/, $(STRING_FILES)) \
)

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(HEADER_FOLDER)

MAKEFLAGS = --no-print-directory

TEST_NAME = tester
TEST_FLAGS = -Wall -Wextra -Werror -I$(HEADER_FOLDER)
TEST_FILE = main.test.c

.PHONY: all clean fclean re test tester

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_FOLDER)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re: fclean 
	$(MAKE) all

$(TEST_NAME): fclean
	@$(MAKE) -s $(NAME) CFLAGS="$(CFLAGS) -g3"
	@$(CC) $(TEST_FLAGS) $(TEST_FILE) $(NAME) -g3 -o $(TEST_NAME)

test: $(TEST_NAME)
	@./$(TEST_NAME)
	@rm $(TEST_NAME)

-include $(DEPS)