# Name of the program
TARGET = game

# Compiler + flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Igoogletest/googletest/include

# Source files
SRC := $(wildcard src/*.cpp src/Locations/*.cpp)
TEST_SRC := test/gameTest.cpp test/suspectTest.cpp
GTEST_SRC := googletest/googletest/src/gtest-all.cc googletest/googletest/src/gtest_main.cc

# Executables
TEST_BIN = runtests

# Build final executable directly (no .o rules)
$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Build test executable
$(TEST_BIN): $(SRC) $(TEST_SRC) $(GTEST_SRC)
	$(CXX) $(CXXFLAGS) $^ -o $(TEST_BIN)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(TARGET) $(TEST_BIN) *.o
