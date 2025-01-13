NAME = libftprintf.a
BUILD_FOLDER = .build
INCLUDE_FOLDER = includes

FILES =	ft_printf.c \
		utils.c \
		handle_flag.c \
		flags/flag_c.c \
		flags/flag_s.c \
		flags/flag_p.c \
		flags/flag_i.c \
		flags/flag_u.c \
		flags/flag_low_x.c \
		flags/flag_up_x.c \

OBJS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.o))
DEPS = $(addprefix $(BUILD_FOLDER)/, $(FILES:.c=.d))

CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP -I$(INCLUDE_FOLDER)

MAKEFLAGS = --no-print-directory

TEST = test.out
TEST_FLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_FOLDER)
TEST_MAIN = main.test.c

.PHONY: all clean fclean re test compile

all:	$(NAME)

$(NAME):	$(OBJS)
	ar d $(NAME) $(BONUS_OBJS)
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

$(TEST): $(NAME)
	@$(CC) $(TEST_MAIN) $(TEST_FLAGS) -L. -l$(shell echo $(NAME) | cut -c4- | rev | cut -c3- | rev) -o $(TEST)

test: $(TEST)
	@./$(TEST)
	@rm $(TEST)

-include $(DEPS)