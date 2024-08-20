cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(includes)

# Add source files
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/snake.cpp
    src/util.cpp
)

# Add executable
add_executable(SnakeGame ${SOURCES})

# Link libraries (if necessary)
# target_link_libraries(SnakeGame ${LIBS})

# Set the build type to Release by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()