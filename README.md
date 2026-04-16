# Sudoku

A fully playable Sudoku game built in C++ using SDL2. The board is procedurally generated each run using a constraint-propagation algorithm.

## Features

- Procedural board generation — a new valid puzzle every time
- Mouse-driven cell selection with row/column highlighting
- Press Enter to check your answers — wrong cells highlight red
- Press Space to auto-solve the puzzle
- Win detection — all cells turn green when the board is complete

## Controls

| Input | Action |
|-------|--------|
| Mouse | Hover to select a cell |
| 1–9 | Place a number in the selected cell |
| Backspace | Clear the selected cell |
| Enter | Check answers (wrong cells turn red) |
| Space | Auto-solve the puzzle |
| Q | Quit |

## Build Instructions

**Requirements**
- CMake
- SDL2, SDL2_image, SDL2_mixer, SDL2_ttf

On macOS with Homebrew:
```
brew install cmake sdl2 sdl2_image sdl2_mixer sdl2_ttf
```

**Build**
```
mkdir cmake-build-debug
cd cmake-build-debug
cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ..
make
./game
```

## Tech Stack

- C++
- SDL2 (via the [ge211](https://github.com/tov/ge211) graphics library)
- CMake
