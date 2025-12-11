cmake_minimum_required(VERSION 3.15)

project(Tetris LANGUAGES CXX)

# C++ standard configuration
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatically collect source files
file(GLOB_RECURSE SOURCES
  src/main.cpp
  src/*.cpp
)

# Create executable
add_executable(Tetris ${SOURCES})

# Public include directory for project headers
target_include_directories(Tetris
  PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# Use SFML static libraries (SFML 3 was built statically on your system)
set(SFML_STATIC_LIBRARIES TRUE)

# Find SFML 3 components
find_package(SFML 3 COMPONENTS System Window Graphics REQUIRED)

# Link against SFML libraries
target_link_libraries(Tetris PRIVATE
  SFML::System
  SFML::Window
  SFML::Graphics
)

# Compiler warnings and safety checks
target_compile_options(Tetris PRIVATE
  -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion 
  -Wcast-align -Wcast-qual -Wold-style-cast -Woverloaded-virtual 
  -Wnon-virtual-dtor -Weffc++ -Wundef -Wuninitialized 
)
