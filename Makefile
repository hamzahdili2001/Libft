# ============================================================
# libft - Makefile
# ============================================================

NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

INC_DIR     = include
SRC_DIR     = src
TEST_DIR    = tests
OBJ_DIR     = obj

# Add more subfolders here as you add categories (e.g. src/memory, src/stdlib)
SRC_SUBDIRS = strings

SRCS        = $(foreach d,$(SRC_SUBDIRS),$(wildcard $(SRC_DIR)/$(d)/*.c))
OBJS        = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TEST_SRCS   = $(wildcard $(TEST_DIR)/*.c)
TEST_BIN    = run_tests

# ------------------------------------------------------------
# Main targets
# ------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "✅ $(NAME) built"

# Compile each .c into obj/, mirroring the src/ subfolder structure
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# ------------------------------------------------------------
# Tests: compile tests/*.c and link against the built library
# ------------------------------------------------------------

test: $(NAME)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $(TEST_SRCS) -L. -lft -o $(TEST_BIN)
	./$(TEST_BIN)

# ------------------------------------------------------------
# Housekeeping
# ------------------------------------------------------------

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST_BIN)

re: fclean all

.PHONY: all test clean fclean re
