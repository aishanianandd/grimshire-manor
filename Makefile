# Name of the program
TARGET = game

# Compiler + flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Source files (all .cpp in src + subfolders)
SRC := $(wildcard src/*.cpp src/Locations/*.cpp)

# Objects
OBJ := $(SRC:.cpp=.o)

# Build
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Run
run: $(TARGET)
	./$(TARGET)

# Clean
clean:
	rm -f $(OBJ) $(TARGET)
