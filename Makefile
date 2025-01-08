NAME = libft.a
BUILD_FOLDER = .build
HEADER_FOLDER = headers

IS_TYPE_FILE = is_type/ft_isalpha.c \
	is_type/ft_isalnum.c \
	is_type/ft_isdigit.c \
	is_type/ft_isascii.c \
	is_type/ft_isprint.c

STRING_FILE = ft_strlen.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c
	ft_toupper.c \
	ft_tolower.c \
	ft_strnstr.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \

FILES =	
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstmap_bonus.c

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(HEADER_FOLDER)

.PHONY: all clean fclean re

all:	$(NAME)

-include $(DEPS)

$(NAME):	$(OBJS)
	ar d $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS)

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(BUILD_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean 
	$(MAKE) all
