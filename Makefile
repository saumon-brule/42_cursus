NAME = libget_next_line.a
BUILD_FOLDER = .build
INCLUDE_FOLDER = includes

FILES =	src/get_next_line.c \
	src/get_next_line_utils.c

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(INCLUDE_FOLDER)

MAKEFLAGS = --no-print-directory

.PHONY: all clean fclean re test compile

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

compile: $(OBJS)
	@echo $(OBJS) > $(BUILD_FOLDER)/obj_list.mk

$(BUILD_FOLDER)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean 
	$(MAKE) all

-include $(DEPS)