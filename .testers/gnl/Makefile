#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 19:27:01 by paalexan          #+#    #+#              #
#    Updated: 2025/01/29 03:13:10 by paalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

# Compiler and Flags
CC := cc
BUFFER_SIZE := 42
CFLAGS := -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)

# Paths
SRC_DIR := ..
TEST_DIR := tests
LIB := ../../libft.a

# Test Programs
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TESTS := $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/%, $(TEST_SRC))

# Colors
BOLD := $(shell tput bold)
RED := $(shell tput setaf 1)
GREEN := $(shell tput setaf 2)
YELLOW := $(shell tput setaf 3)
BLUE := $(shell tput setaf 4)
RESET := $(shell tput sgr0)

# **************************************************************************** #
#                                  TARGETS                                     #
# **************************************************************************** #

# Declare phony targets
.PHONY: all bonus run clean fclean re

# Default target: compile mandatory part
all: run

# Compile the library for bonus part
bonus: print_buffer
	@$(MAKE) fclean
	@$(MAKE) $(BONUS_OBJ)
	@ar rcs $(LIB) $(BONUS_OBJ)
	@ranlib $(LIB)
	@echo "$(GREEN)Bonus library $(LIB) created successfully!$(RESET)"

# Compile test programs
$(TESTS): $(TEST_DIR)/%: $(TEST_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ $< $(LIB)
	@echo "$(BLUE)Test program $@ compiled successfully!$(RESET)"

# Run the tester
run: $(TESTS)
	@echo "$(BLUE)Running tests...$(RESET)"
	@bash $(TEST_DIR)/run_tests.sh

# Compile object files
%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled test programs and object files
clean:
	@rm -f $(TESTS)
	@rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)
	@echo "$(YELLOW)Cleaned up test programs and object files.$(RESET)"

# Full clean, including the library
fclean: clean
	@rm -rf $(TEST_DIR)/expected/*
	@echo "$(RED)Full clean completed.$(RESET)"

# Recompile everything
re: fclean all
