# Tetris Game

A simple Tetris game written in modern C++ and built with CMake.  
This project implements the essential mechanics of the classic Tetris: falling tetrominoes, rotation, movement, line clearing, scoring, and game-over detection.

---

## Requirements

- C++20 compiler (g++, clang, or MSVC)
- CMake 3.15+
- **SFML 3**

> ⚠️ Some package managers (especially on Ubuntu / Debian) still provide **SFML 2.5**, which is not compatible with this project.

If your system does **not** provide **SFML 3**, you can install it manually using the script included in this repository:

```
./install_sfml3.sh
```

This script automatically downloads, builds and installs SFML 3 into `/usr/local`.

---

## Install Dependencies

### Linux (Ubuntu / Debian-based)

Most distros do **not** ship SFML 3 yet.  
You may install SFML 2.5 from apt (not compatible) **or install SFML 3 using the script above**.

Minimal system dependencies:

```bash
sudo apt update
sudo apt install -y build-essential cmake git
```

Then install SFML 3:

```bash
./install_sfml3.sh
```

---

### Linux (Arch-based)

Arch may provide SFML 3 earlier than other distros.  
If available:

```bash
sudo pacman -Syu
sudo pacman -S gcc cmake make sfml
```

If your Arch repository still provides SFML 2.x, you must build SFML 3 manually
(from source using CMake), because the provided install_sfml3.sh script is intended
for Ubuntu/Debian and will **not** work on Arch.

---

### macOS (Homebrew)

Homebrew provides **SFML 3**, which is fully compatible with this project.

Install dependencies:

```bash
brew update
brew install cmake sfml
```

---

## Build Instructions

```bash
git clone https://github.com/andreaamanzo/tetris-game.git
cd tetris-game
mkdir build
cd build
cmake ..
make
```

---

## Run the Game

From the `build` directory:

```bash
./Tetris
```

---

## Controls

### Gameplay
- **Up Arrow**: rotate block  
- **Left Arrow**: move block left  
- **Right Arrow**: move block right  
- **Down Arrow**: soft drop  
- **Enter**: hard drop  

### Game actions
- **P**: pause  
- **R**: restart  
- **Q**: quit  

---

## Project Status

Work in progress.
