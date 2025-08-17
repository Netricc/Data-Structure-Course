# Name of the source file inside src (without .cpp extension)
SRC ?= linkedQueue

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -std=c++23

# Directories
SRC_DIR := src
BUILD_DIR := .

# Target executable
TARGET := $(BUILD_DIR)/$(SRC)

# Default rule
all: $(TARGET)

$(TARGET): $(SRC_DIR)/$(SRC).cpp
	$(CXX) $(CXXFLAGS) $< -o $@ && echo "\n" && ./$(TARGET)


# Clean build
clean:
	rm -f $(TARGET)