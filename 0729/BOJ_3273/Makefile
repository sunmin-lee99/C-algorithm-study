# Makefile for compiling 김웅수.cc without keeping the 김웅수.o file

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable name
TARGET = 김웅수

# Source file
SRC = 김웅수.cc

# Default target
all: $(TARGET)

# Rule to build the target executable without keeping the .o file
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean

