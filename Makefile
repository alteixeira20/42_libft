# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 16:10:40 by paalexan          #+#    #+#              #
#    Updated: 2025/04/23 16:44:10 by paalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

NAME		:= libft.a

# Compiler and Flags
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

# GitHub Repositories
PRINTF_URL	:= https://github.com/alteixeira20/42_printf.git
GNL_URL		:= https://github.com/alteixeira20/42_get_next_line.git

# Directories
LIBFT_DIR	:= libft
PRINTF_DIR	:= printf
GNL_DIR		:= gnl

# Libft Source Code
CHAR_CHECK_SRC := \
	$(LIBFT_DIR)/ft_isalnum.c  $(LIBFT_DIR)/ft_isalpha.c  $(LIBFT_DIR)/ft_isascii.c \
	$(LIBFT_DIR)/ft_isdigit.c  $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_isnumeric.c \
	$(LIBFT_DIR)/ft_iswhitespace.c $(LIBFT_DIR)/ft_isspace.c $(LIBFT_DIR)/ft_max.c
STRING_MANIP_SRC := \
	$(LIBFT_DIR)/ft_strlen.c   $(LIBFT_DIR)/ft_strlcat.c  $(LIBFT_DIR)/ft_strlcpy.c \
	$(LIBFT_DIR)/ft_strdup.c   $(LIBFT_DIR)/ft_strchr.c   $(LIBFT_DIR)/ft_strrchr.c \
	$(LIBFT_DIR)/ft_strnstr.c  $(LIBFT_DIR)/ft_strncmp.c  $(LIBFT_DIR)/ft_strmapi.c \
	$(LIBFT_DIR)/ft_striteri.c $(LIBFT_DIR)/ft_strjoin.c  $(LIBFT_DIR)/ft_strtrim.c \
	$(LIBFT_DIR)/ft_substr.c   $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_swapstrs.c \
	$(LIBFT_DIR)/ft_str_append_char.c $(LIBFT_DIR)/ft_strcmp.c
MEMORY_SRC := \
	$(LIBFT_DIR)/ft_memchr.c   $(LIBFT_DIR)/ft_memcmp.c   $(LIBFT_DIR)/ft_memcpy.c \
	$(LIBFT_DIR)/ft_memmove.c  $(LIBFT_DIR)/ft_memset.c   $(LIBFT_DIR)/ft_bzero.c \
	$(LIBFT_DIR)/ft_calloc.c
CONVERSION_SRC := \
	$(LIBFT_DIR)/ft_atoi.c     $(LIBFT_DIR)/ft_atol.c $(LIBFT_DIR)/ft_itoa.c
CHAR_TRANSFORM_SRC := \
	$(LIBFT_DIR)/ft_tolower.c  $(LIBFT_DIR)/ft_toupper.c
FD_OUTPUT_SRC := \
	$(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr_fd.c \
	$(LIBFT_DIR)/ft_putstr_fd.c
LINKED_LIST_SRC := \
	$(LIBFT_DIR)/ft_lstadd_back.c  $(LIBFT_DIR)/ft_lstadd_front.c  \
	$(LIBFT_DIR)/ft_lstclear.c  $(LIBFT_DIR)/ft_lstdelone.c  \
	$(LIBFT_DIR)/ft_lstiter.c  $(LIBFT_DIR)/ft_lstlast.c  \
	$(LIBFT_DIR)/ft_lstmap.c  $(LIBFT_DIR)/ft_lstnew.c  \
	$(LIBFT_DIR)/ft_lstsize.c
LIBFT_SRC := $(CHAR_CHECK_SRC) $(STRING_MANIP_SRC) $(MEMORY_SRC) $(CONVERSION_SRC) \
	$(CHAR_TRANSFORM_SRC) $(FD_OUTPUT_SRC) $(LINKED_LIST_SRC)

# Printf Source Code
PRINTF_SRC := $(PRINTF_DIR)/ft_printf_bonus.c $(PRINTF_DIR)/ft_printf_numbers_bonus.c \
	$(PRINTF_DIR)/ft_printf_hex_bonus.c $(PRINTF_DIR)/ft_printf_strings_bonus.c \
	$(PRINTF_DIR)/ft_printf_utils_numbers_bonus.c $(PRINTF_DIR)/ft_printf_utils_hex_bonus.c \
	$(PRINTF_DIR)/ft_printf_utils_str_bonus.c $(PRINTF_DIR)/ft_padding_bonus.c \
	$(PRINTF_DIR)/ft_padding_utils_bonus.c $(PRINTF_DIR)/ft_parser_bonus.c

# GNL Source Code
GNL_SRC := $(GNL_DIR)/get_next_line_bonus.c $(GNL_DIR)/get_next_line_utils_bonus.c $(GNL_DIR)/get_next_line_utils2_bonus.c

# Object Files
OBJ_DIR		:= obj
LIBFT_OBJ	:= $(addprefix $(OBJ_DIR)/, $(notdir $(LIBFT_SRC:.c=.o)))
PRINTF_OBJ	:= $(addprefix $(OBJ_DIR)/, $(notdir $(PRINTF_SRC:.c=.o)))
GNL_OBJ		:= $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRC:.c=.o)))

# Prefix for messages
PREFIX		:= \033[1;35m[LIBFT]\033[0m

# Colors
RESET		:= \033[0m
BOLD		:= \033[1m
RED		:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
PURPLE		:= \033[35m
CYAN		:= \033[36m

# **************************************************************************** #
# TARGETS                                                                      #
# **************************************************************************** #

# Default target: Prepare environment only
all: $(GNL_DIR) $(PRINTF_DIR) prepare_dirs

prepare_dirs:
	@mkdir -p $(OBJ_DIR)
	@echo "$(PREFIX) Created $(CYAN)$(OBJ_DIR)$(RESET) directory."
	@make lib

# Clone GNL repository only if it doesn't exist
$(GNL_DIR):
	@if [ ! -d "$(GNL_DIR)" ]; then \
		echo "$(PREFIX) Cloning $(CYAN)gnl$(RESET) repository..."; \
		git clone $(GNL_URL) $(GNL_DIR); \
		find $(GNL_DIR) -type f ! -name '*_bonus*' -delete; \
		rm -rf $(GNL_DIR)/.tester $(GNL_DIR)/.git; \
	fi
	@echo "$(PREFIX) $(CYAN)gnl$(RESET) repository is ready."

# Clone Printf repository only if it doesn't exist
$(PRINTF_DIR):
	@if [ ! -d "$(PRINTF_DIR)" ]; then \
		echo "$(PREFIX) Cloning $(CYAN)ft_printf$(RESET) repository..."; \
		git clone $(PRINTF_URL) $(PRINTF_DIR); \
		mv $(PRINTF_DIR)/srcb/* $(PRINTF_DIR)/; \
		rm -rf $(PRINTF_DIR)/src $(PRINTF_DIR)/srcb; \
		rm -f $(PRINTF_DIR)/Makefile $(PRINTF_DIR)/README.md; \
		rm -rf $(PRINTF_DIR)/.tester $(PRINTF_DIR)/.git; \
	fi
	@echo "$(PREFIX) $(CYAN)ft_printf$(RESET) repository is ready."

# Compilation process for the library
lib: $(GNL_DIR) $(PRINTF_DIR) $(NAME)

$(NAME): $(LIBFT_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	@echo "$(PREFIX) Creating library $(CYAN)$(NAME)$(RESET) ..."
	@ar rcs $@ $^
	@echo "$(PREFIX) Library $(CYAN)$(NAME)$(RESET) created $(GREEN)successfully$(RESET)!"

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(PREFIX) $(YELLOW)Compiled:$(RESET) $<"

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(PREFIX) $(YELLOW)Compiled:$(RESET) $<"

$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(PREFIX) $(YELLOW)Compiled:$(RESET) $<"

# Cleaning rules
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "$(PREFIX) $(CYAN)Object files$(RESET) cleaned!"; \
	else \
		echo "$(PREFIX) No $(CYAN)object files$(RESET) to clean."; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(PREFIX) Library $(CYAN)$(NAME)$(RESET) removed."; \
	else \
		echo "$(PREFIX) No $(CYAN)library$(RESET) to remove."; \
	fi
	@if [ -d "$(PRINTF_DIR)" ]; then \
		rm -rf $(PRINTF_DIR); \
		echo "$(PREFIX) $(CYAN)ft_printf$(RESET) repository cleaned."; \
	else \
		echo "$(PREFIX) No $(CYAN)ft_printf$(RESET) repository found."; \
	fi
	@if [ -d "$(GNL_DIR)" ]; then \
		rm -rf $(GNL_DIR); \
		echo "$(PREFIX) $(CYAN)gnl$(RESET) repository cleaned."; \
	else \
		echo "$(PREFIX) No $(CYAN)gnl$(RESET) repository found."; \
	fi

re: fclean all

.PHONY: all clean fclean re
