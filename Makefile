# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #
NAME        := libft.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
SRC_DIR     := src
OBJ_DIR     := obj
TEST_DIR    := tester
TEST_EXEC   := libft_test
RESULTS_FILE := $(TEST_DIR)/results.txt
INC_TESTER  := libft_tester.h
SRC         := $(wildcard $(SRC_DIR)/*.c)
OBJ         := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

MANDATORY_FUNCS := $(TEST_DIR)/mandatory.txt
BONUS_FUNCS     := $(TEST_DIR)/bonus.txt
EXTRA_FUNCS     := $(TEST_DIR)/extra.txt

# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(BGRN)Library $(NAME) created successfully!$(D)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BYEL)Compiled:$(D) $<"

# Rule to compile and run tests
test: clean_results $(NAME) mandatory bonus

# Ensure results.txt is cleaned before running new tests
clean_results:
	@echo "Cleaning up previous test results..."
	@rm -f $(RESULTS_FILE)

# Compile and run mandatory and bonus tests
mandatory: compile_test
	@echo "$(B)Checking mandatory functions...$(D)"
	@if [ -f $(RESULTS_FILE) ]; then \
		while read -r func; do \
			if grep -q "$$func: SUCCESS" $(RESULTS_FILE); then \
				echo "$(GRN)$$func: SUCCESS$(D)"; \
			else \
				echo "$(RED)$$func: KO$(D)"; \
			fi; \
		done < $(MANDATORY_FUNCS); \
	else \
		echo "$(YEL)No results.txt found. Please run 'make test' first!$(D)"; \
	fi

bonus: compile_test
	@echo "$(B)Checking bonus functions...$(D)"
	@if [ -f $(RESULTS_FILE) ]; then \
		while read -r func; do \
			if grep -q "$$func: SUCCESS" $(RESULTS_FILE); then \
				echo "$(GRN)$$func: SUCCESS$(D)"; \
			else \
				echo "$(RED)$$func: KO$(D)"; \
			fi; \
		done < $(BONUS_FUNCS); \
	else \
		echo "$(YEL)No results.txt found. Please run 'make test' first!$(D)"; \
	fi

# Compile the test executable
compile_test: $(TEST_EXEC)
	@./$(TEST_EXEC)  # Run the test binary to generate results.txt
	@echo "$(BGRN)Test results saved to $(RESULTS_FILE)$(D)"

$(TEST_EXEC): $(TEST_DIR)/main.c
	@echo "$(B)Compiling tests...$(D)"
	@$(CC) $(CFLAGS) $(TEST_DIR)/main.c -L. -lft -o $(TEST_EXEC)
	@echo "$(BGRN)Test binary $(TEST_EXEC) compiled.$(D)"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BRED)Object files cleaned!$(D)"

# Clean object files and the library
fclean: clean
	@rm -f $(NAME) $(TEST_EXEC)
	@echo "$(BRED)All cleaned up!$(D)"

# Rebuild the library
re: fclean all

# Norminette check
norm:
	@norminette $(SRC_DIR) $(TEST_DIR)
	@echo "$(B)Norm check completed.$(D)"

.PHONY: all clean fclean re test mandatory bonus norm clean_results compile_test

# **************************************************************************** #
#                                  UTILS                                       #
# **************************************************************************** #

# Colors
B  	= $(shell tput bold)
BLA	= $(shell tput setaf 0)
RED	= $(shell tput setaf 1)
GRN	= $(shell tput setaf 2)
YEL	= $(shell tput setaf 3)
BLU	= $(shell tput setaf 4)
MAG	= $(shell tput setaf 5)
CYA	= $(shell tput setaf 6)
WHI	= $(shell tput setaf 7)
GRE	= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 	= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tpu el 1)
