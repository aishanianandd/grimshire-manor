cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# Game source files
file(GLOB_RECURSE GAME_SOURCES
    src/*.cpp
    src/Locations/*.cpp
)
list(REMOVE_ITEM GAME_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Include paths
include_directories(include)

# Game Executable
add_executable(game ${GAME_SOURCES} src/main.cpp)

# Google Test Setup
enable_testing()

# Add googletest directory
add_subdirectory(googletest)

# Test source files
set(TEST_SOURCES
    test/gameTest.cpp
    test/suspectTest.cpp
)

add_executable(runtests ${TEST_SOURCES} ${GAME_SOURCES})
target_include_directories(runtests PRIVATE include)
target_link_libraries(runtests gtest gtest_main)

# Register tests
add_test(NAME AllTests COMMAND runtests)