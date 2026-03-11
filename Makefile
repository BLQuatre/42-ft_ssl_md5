NAME		= ft_ssl
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD

INC_DIR		= includes
SRCS_DIR	= srcs
OBJS_DIR	= objs

FILES		= main.c \
			  utils/gnl.c \
			  utils/ft.c \
			  dev.c \
			  md5/md5_main.c \
			  md5/md5_process.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(FILES))

OBJS		= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
DEPS		= $(OBJS:.o=.d)

GREEN		= \033[0;32m
CYAN		= \033[0;36m
RESET		= \033[0m
GRAY		= \033[90m

SUCCESS		= $(GREEN)[SUCCESS]$(RESET)
INFO		= $(CYAN)[INFO]$(RESET)

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(dir $@)
	@echo "$(INFO) Compiling $<...$(GRAY)"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(INFO) Compiling $(NAME)...$(GRAY)"
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(SUCCESS) $(NAME) compiled."

-include $(DEPS)

clean:
	@echo "$(INFO) Removing object files...$(GRAY)"
	rm -rf $(OBJS_DIR)
	@echo "$(SUCCESS) Objects and libs removed."

fclean: clean
	@echo "$(INFO) Removing $(NAME)...$(GRAY)"
	rm -f $(NAME)
	@echo "$(SUCCESS) $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
