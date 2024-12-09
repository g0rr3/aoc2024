SRC_DIR = src
EXEC_DIR = exec
INCLUDE_DIR = include
CC = tcc
CFLAGS = -Wall -g -Iinclude

# Find all .c files in src/ directory
ALL_SRCS = $(wildcard $(SRC_DIR)/*.c)

# Find all .h files in include/ directory
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

DEFINITIONS = $(patsubst $(INCLUDE_DIR)/%.h, $(SRC_DIR)/%.c, $(HEADERS))

# Automatically exclude the corresponding .c files for each header
SOURCES = $(filter-out $(DEFINITIONS), $(ALL_SRCS))

# Generate corresponding executables in the exec/ directory
EXECUTABLES = $(patsubst $(SRC_DIR)/%.c, $(EXEC_DIR)/%, $(SOURCES))

# Default target (build all executables)
all: $(EXEC_DIR) $(EXECUTABLES) 

$(EXEC_DIR):
	@mkdir -p $(EXEC_DIR)

# Rule to build each executable (compile and link)
$(EXEC_DIR)/%: $(SRC_DIR)/%.c $(DEFINITIONS) $(HEADERS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target to remove executables
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
