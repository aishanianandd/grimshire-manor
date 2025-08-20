# Name of the program we want to create
TARGET = main

# src file to compile
SRC = src/main.cpp

# build program
$(TARGET): $(SRC)
	g++ $(SRC) -o $(TARGET)

# run program
run: $(TARGET)
	./$(TARGET)
