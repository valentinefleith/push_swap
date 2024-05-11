# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 15:31:12 by vafleith          #+#    #+#              #
#    Updated: 2024/05/11 11:58:25 by vafleith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -g3
#CFLAGS += -Werror

LIBFT_PATH = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)/$(LIBFT_NAME)

INC = -Iinclude -Ilibft

SRC_DIR = src

OPERATIONS_DIR = operations
OPERATIONS_SRCS = operations.c display_swap.c display_push.c display_rotate.c \
				  display_reverse_rotate.c
OPERATIONS_SRCS := $(addprefix $(OPERATIONS_DIR)/, $(OPERATIONS_SRCS))

PARSE_DIR = parse
PARSE_SRCS = parse_args.c store_stack.c parse_utils.c
PARSE_SRCS := $(addprefix $(PARSE_DIR)/, $(PARSE_SRCS))

SORT_DIR = sort
SORT_SRCS = sort_utils.c presort.c radix.c small_sorts.c
SORT_SRCS := $(addprefix $(SORT_DIR)/, $(SORT_SRCS))

UTILS_DIR = utils
UTILS_SRCS = linked_lists_utils.c print_stack.c free.c
UTILS_SRCS := $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

SRCS = main.c $(OPERATIONS_SRCS) $(PARSE_SRCS) $(SORT_SRCS) $(UTILS_SRCS)
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = build
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

.PHONY: all
all: $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: %.c
	@echo Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(LIBFT):
	@echo "Making Libft"
	@make -C $(LIBFT_PATH) > /dev/null

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INC)
	@echo "push_swap ready."

.PHONY: clean
clean:
	@echo Cleaning up object files	
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_PATH) > /dev/null

.PHONY: fclean
fclean: clean
	@make fclean -C $(LIBFT_PATH) > /dev/null
	@rm -rf $(NAME)

.PHONY: re
re: fclean all
