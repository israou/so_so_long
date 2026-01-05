# So_long – 42 School Project

**So_long** is a 2D game development project from 42 School. The goal is to create a small game using the **MiniLibX** graphics library where the player must collect all collectibles and reach the exit while navigating through a map. This project introduces basic game development concepts, event handling, and graphical programming.

This project teaches fundamental concepts of graphics programming, game loops, sprite rendering, and user input handling.

## 📌 Project Overview

The objective of So_long is to create a simple 2D game where a player character moves through a map, collects items, and finds the exit. The game must be rendered using MiniLibX and handle keyboard events for player movement.

The project must demonstrate:
* **Graphics Rendering** – Display sprites and tiles using MiniLibX
* **Event Handling** – Process keyboard input for player movement
* **Map Parsing** – Read and validate map files
* **Game Logic** – Implement collectible gathering and win conditions
* **Error Handling** – Robust validation of map files and game states

## 🎮 Game Rules

### Objective
* Collect **all collectibles** (C) on the map
* Reach the **exit** (E) after collecting all items
* The game displays the **move count** in the terminal
* The game closes properly with ESC or clicking the window's close button

### Map Components

* `0` – Empty space (walkable)
* `1` – Wall (non-walkable)
* `C` – Collectible item
* `E` – Exit (only accessible after collecting all C)
* `P` – Player starting position

### Map Requirements

* Must be rectangular
* Must be surrounded by walls (1)
* Must contain exactly **one exit (E)**
* Must contain exactly **one player starting position (P)**
* Must contain **at least one collectible (C)**
* Must have a valid path from P to all C and to E

## 🛠️ Installation & Usage

### Requirements

* C compiler (gcc/clang)
* Make
* MiniLibX library
* Unix/Linux or macOS system
* X11 (for Linux)

### Build & Run
```bash
# Clone the repository
git clone https://github.com/ichaabi/so_long.git
cd so_long

# Compile
make

# Run with a map file
./so_long maps/map1.ber
./so_long maps/map2.ber
```

## 🗺️ Map Format

Maps must be saved with a `.ber` extension.

### Valid Map Example
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Map Validation

The program must check:
* ✅ Map is rectangular
* ✅ Map is surrounded by walls
* ✅ Contains exactly 1 player (P)
* ✅ Contains exactly 1 exit (E)
* ✅ Contains at least 1 collectible (C)
* ✅ Contains only valid characters (0, 1, C, E, P)
* ✅ Has a valid path to collect all items and reach the exit

### Invalid Map Examples
```
# Not rectangular
111111
1000001
10P0C1
1E01
111111

# Not surrounded by walls
111111
100001
10P0C1
10E001
111111

# No collectibles
111111
100001
10P001
10E001
111111

# Multiple players
111111
1P0001
10P0C1
10E001
111111

# No valid path
111111
10C0C1
111111
1P00E1
111111
```

## 🎮 Controls

| Key | Action |
|-----|--------|
| `W` or `↑` | Move up |
| `A` or `←` | Move left |
| `S` or `↓` | Move down |
| `D` or `→` | Move right |
| `ESC` | Exit game |

## 💡 Features

### Mandatory Features

* **Window Management**
  - Smooth window handling
  - Minimize, maximize, switch between windows
  - Close window with ESC or window close button

* **Graphics**
  - Display map with textures/sprites
  - Render walls, collectibles, exit, and player
  - Update display after each move

* **Game Mechanics**
  - Player movement with collision detection
  - Collectible gathering system
  - Exit unlocks after collecting all items
  - Move counter displayed in terminal

* **Map Validation**
  - Parse `.ber` files
  - Validate map format and rules
  - Check for valid paths using flood fill or BFS
  - Display appropriate error messages

## 📖 Usage Examples

### Running the Game
```bash
# Basic usage
$ ./so_long maps/simple.ber

# Example output in terminal
Moves: 1
Moves: 2
Moves: 3
Collectibles: 2/3
Moves: 4
Collectibles: 3/3
Moves: 5
You Win! Total moves: 5
```

### Error Handling
```bash
# Invalid map format
$ ./so_long maps/invalid.ber
Error
Invalid map: Not rectangular

# No collectibles
$ ./so_long maps/no_collectibles.ber
Error
Invalid map: No collectibles found

# No valid path
$ ./so_long maps/no_path.ber
Error
Invalid map: No valid path to exit

# Wrong file extension
$ ./so_long maps/map.txt
Error
Invalid file: Must be a .ber file
```

## 🔧 Technical Implementation

### Key Functions (MiniLibX)
```c
// Window management
void *mlx_init(void);
void *mlx_new_window(void *mlx, int width, int height, char *title);

// Image handling
void *mlx_xpm_file_to_image(void *mlx, char *file, int *width, int *height);
int mlx_put_image_to_window(void *mlx, void *win, void *img, int x, int y);

// Event handling
int mlx_hook(void *win, int event, int mask, int (*f)(), void *param);
int mlx_key_hook(void *win, int (*f)(), void *param);
int mlx_loop(void *mlx);

// Cleanup
int mlx_destroy_image(void *mlx, void *img);
int mlx_destroy_window(void *mlx, void *win);
```

### Game Loop Structure
```c
1. Initialize MiniLibX
2. Load sprites/textures
3. Parse and validate map
4. Create game window
5. Render initial game state
6. Register event hooks
   - Keyboard events
   - Window close event
7. Enter main loop (mlx_loop)
8. On player move:
   - Validate move (collision)
   - Update player position
   - Increment move counter
   - Check collectibles
   - Re-render game
   - Print moves to terminal
9. On win condition:
   - Display victory message
   - Close game properly
```

### Map Validation Algorithm
```c
1. Read map file
2. Check file extension (.ber)
3. Validate rectangular shape
4. Check wall boundaries
5. Count and validate components:
   - Exactly 1 player (P)
   - Exactly 1 exit (E)
   - At least 1 collectible (C)
6. Verify valid path:
   - Use flood fill from player position
   - Mark all reachable positions
   - Verify all collectibles are reachable
   - Verify exit is reachable
7. Return success or specific error
```

## 🧪 Test Cases

### Valid Maps to Test
```bash
# Simple map
./so_long maps/simple.ber

# Medium complexity
./so_long maps/medium.ber

# Large map
./so_long maps/large.ber

# Minimum valid map (3x3)
./so_long maps/minimal.ber
```

### Invalid Maps to Test
```bash
# Test error handling
./so_long maps/not_rectangular.ber
./so_long maps/no_walls.ber
./so_long maps/multiple_exits.ber
./so_long maps/no_player.ber
./so_long maps/no_collectibles.ber
./so_long maps/invalid_path.ber
./so_long maps/invalid_chars.ber
```

### Memory Tests
```bash
# Check for memory leaks
valgrind --leak-check=full ./so_long maps/map1.ber

# Play and close with ESC
# Play and collect all items
# Play and close window
```

## ✅ Project Requirements Respected

* Window remains smooth (minimize, switch, etc.)
* ESC closes window and exits cleanly
* Click on window close button exits cleanly
* Proper use of MiniLibX functions
* Map must be parsed from a `.ber` file
* Map validation with appropriate error messages
* Player cannot move through walls
* Move count displayed in terminal
* 2D view (top-down or profile)
* No memory leaks
* Proper error handling

## 📚 Skills & Concepts Learned

* **Graphics Programming** – Rendering with MiniLibX
* **Game Development** – Game loops, sprites, collision detection
* **Event Handling** – Keyboard and window events
* **File Parsing** – Reading and validating map files
* **Pathfinding** – Flood fill algorithm for map validation
* **Memory Management** – Image and window cleanup
* **Error Handling** – Robust validation and error messages
* **Data Structures** – 2D arrays for map representation

## 👤 Author

**Israa Chaabi** – 42 Student | Software Engineering  
42 Login: `ichaabi`

## 📚 Resources

* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
* [MiniLibX Man Pages](https://qst0.github.io/ft_libgfx/man_mlx.html)
* [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)
* [Game Loop Pattern](https://gameprogrammingpatterns.com/game-loop.html)
* [2D Game Development Basics](https://www.gamedev.net/tutorials/_/technical/game-programming/your-first-step-to-game-development-starts-here-r2976)

## ⚠️ Disclaimer

This project is part of the 42 curriculum and is shared for educational purposes only. If you are a 42 student, do not copy this repository—use it to understand the concepts and build your own implementation.

---
