# Tetris Game

A simple Tetris game written in modern C++ and built with CMake.  
This project implements the essential mechanics of the classic Tetris: falling tetrominoes, rotation, movement, line clearing, scoring, and game-over detection.

The goal of this project is to provide a clean and readable codebase for learning game logic and SFML rendering.

## Requirements

- C++20 compiler (g++, clang, or MSVC)
- CMake 3.15+
- **SFML 2.5.x (Linux/macOS)** 
  > ⚠️ On macOS, Homebrew now installs SFML 3 by default, which is not compatible with this project.  
  > You must install SFML 2.5 manually.

## Install Dependencies

### Linux (Ubuntu / Debian-based)

```bash
sudo apt update
sudo apt install -y build-essential cmake libsfml-dev
```

### Linux (Arch-based)

```bash
sudo pacman -Syu
sudo pacman -S gcc cmake make sfml
```

## Build Instructions

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

### Gameplay
- **Up Arrow**: rotate the block  
- **Left Arrow**: move block left  
- **Right Arrow**: move block right  
- **Down Arrow**: soft drop  
- **Enter**: hard drop  

### Game actions
- **P**: pause  
- **R**: restart  
- **Q**: quit  

## Project Status

Work in progress.
