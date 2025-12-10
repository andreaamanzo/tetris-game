cmake_minimum_required(VERSION 3.15)

project(Tetris LANGUAGES CXX)

# Standard C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Colleziona i sorgenti automaticamente
file(GLOB_RECURSE SOURCES
    src/main.cpp
    src/*.cpp
)

# Crea l'eseguibile
add_executable(Tetris ${SOURCES})

# Directory include pubblica
target_include_directories(Tetris
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  sfml-graphics
  sfml-window
  sfml-system
)

# Opzioni di compilazione
target_compile_options(Tetris PRIVATE
    -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion 
    -Wcast-align -Wcast-qual -Wold-style-cast -Woverloaded-virtual 
    -Wnon-virtual-dtor -Weffc++ -Wundef -Wuninitialized 
)