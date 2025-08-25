# Name of the program
TARGET = game

# Compiler + flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Source files
SRC := $(wildcard src/*.cpp src/Locations/*.cpp)

# Build final executable directly (no .o rules)
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
