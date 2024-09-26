# Compiler and flags
CC = g++
CFLAGS = -Iinclude -Wall $(shell sdl2-config --cflags)  # Get SDL2 compile flags
LDFLAGS = $(shell sdl2-config --libs)  # Get SDL2 linker flags

# Source and build directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIB_DIR = lib

# Source files (in 'src' directory)
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (in 'build' directory)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Executable target name
TARGET = main.out

# Default target: build the executable
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files, output them in 'build' folder
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
