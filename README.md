*This project has been created as part of the 42 curriculum by yueli.*

# so_long

## Overview

**so_long** is a small 2D game project developed in C using the **MiniLibX (Linux)** graphics library.  
The goal is to create a simple tile-based game where the player collects items and reaches the exit while respecting strict project constraints.

This project includes both the **Mandatory** and **Bonus** parts.

## Mandatory Part

### Objective
- Parse and validate a `.ber` map file
- Display the map using MiniLibX
- Allow the player to move, collect all collectibles, and reach the exit
- End the game correctly when the win condition is met

### Map Rules
- The map is composed of:
  - `1` : Wall  
  - `0` : Empty space  
  - `P` : Player  
  - `C` : Collectible  
  - `E` : Exit
- The map must be rectangular and fully surrounded by walls
- There must be exactly one player and one exit, and at least one collectible

### Controls
- Move: `W A S D` or arrow keys  
- Exit game: `ESC`

### Move Counter
- The number of player moves is printed **in the terminal**

### Compile & Run
make
./so_long maps/map.ber

## Bonus Part

The bonus version extends the mandatory game with additional gameplay and visual features.

### Added Features
- **Enemies** (`O`) added to the map  
  - Contact with an enemy results in game over
- **Player animation**
- **On-screen move counter**
  - The number of moves is displayed directly in the game window

### Bonus Controls
- Same as mandatory

## Compilation & Usage

### Compile & Run
make bonus
./so_long_bonus maps/map_bonus.ber
