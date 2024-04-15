# Makefile for the C++ project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = ./main.cpp ./AVLtrees.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = program

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Phony target to clean the project
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
