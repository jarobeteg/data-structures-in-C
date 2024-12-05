# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -O2 -std=c11
LDFLAGS := 

# Directories
SRC_DIRS := array stack linked_list binary_tree binary_search_tree queue deque hash_table
TEST_DIR := tests
BUILD_DIR := build
INCLUDE_DIRS := $(SRC_DIRS)
INCLUDE_FLAGS := $(addprefix -I, $(INCLUDE_DIRS))

# Source and object files
SRCS := main.c $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRCS))
TEST_OBJS := $(patsubst %.c, $(BUILD_DIR)/%.o, $(TEST_SRCS))
SRC_OBJS := $(filter-out $(BUILD_DIR)/main.o, $(OBJS)) # Exclude main.c for tests

# Executable names
TARGET := main
TEST_TARGET := main_test

# Default target
.PHONY: all
all: $(TARGET)

# Link the main executable
$(TARGET): $(OBJS)
	@echo "Linking $@"
	$(CC) $(OBJS) $(LDFLAGS) -o $@

# Link the test executable (exclude main.c)
$(TEST_TARGET): $(SRC_OBJS) $(TEST_OBJS)
	@echo "Linking $@ (test executable)"
	$(CC) $(SRC_OBJS) $(TEST_OBJS) $(LDFLAGS) -o $@

# Compile object files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling $< -> $@"
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# Clean target
.PHONY: clean
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

# Run the program
.PHONY: run
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# Run tests
.PHONY: test-run
test-run: $(TEST_TARGET)
	@echo "Running $(TEST_TARGET)..."
	./$(TEST_TARGET)

# Automatic dependency handling
DEPFILES := $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)
-include $(DEPFILES)

$(BUILD_DIR)/%.d: %.c
	@mkdir -p $(dir $@)
	@echo "Generating dependencies for $<"
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -MM -MT $(@:.d=.o) $< > $@
