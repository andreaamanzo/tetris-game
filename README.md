# Tetris Game

A simple Tetris game written in C++ and built with CMake.  
This project implements the basic mechanics of the classic Tetris: falling pieces, movement, rotation, collision detection, and line clearing.

## Requirements

- C++ compiler (g++, clang, or MSVC)
- CMake 3.x or higher

## Install g++ and CMake

### Linux (Debian/Ubuntu-based)

```bash
sudo apt update
sudo apt install -y build-essential cmake
```

This will install `g++`, `make`, and `cmake`.

### macOS (with Homebrew)

First install Homebrew if you don't have it:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Then install the tools:

```bash
brew install gcc cmake
```

## Build

```bash
git clone https://github.com/andreaamanzo/tetris-game.git
cd tetris-game
mkdir build
cd build
cmake ..
make
```

## Run

From the `build` directory, you can start the game with:

```bash
./Tetris
```

## Controls

- **Up Arrow**: rotate the block  
- **Left Arrow**: move block left  
- **Right Arrow**: move block right  
- **Down Arrow**: soft drop (faster descent)  
- **Enter**: hard drop (instantly place the block)

## Project Status

Work in progress.
