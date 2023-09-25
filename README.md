# So_Long - 2D Escape Game

 SoLong is a simple 2D escape game where your character, whether it's a dolphin, hero, or any other creature, must collect valuables on a map and then make an escape. The game is built using the miniLibX library and follows specific rules and constraints.

## Installation

Use the package manager [pip](https://pip.pypa.io/en/stable/) to install foobar.

```bash
git clone https://github.com/your_username/so_long.git
cd so_long
make all

```

## Usage
To play SoLong, run the executable with a map description file in .ber format as the first argument:
```python
./so_long map.ber
```

## Map Format

```bash
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

```
Map legend:

0: Empty space
1: Wall
C: Collectible
E: Exit
P: Player's starting position

Maps must be surrounded by walls, have at least one exit, one collectible, and one starting position. They must also be rectangular and follow the rules of the map. If any misconfiguration is encountered, the program will exit with an error message.
## Controls

Use the W, A, S, and D keys to move the main character.
The game is not real-time, and movements are discrete.
The current number of movements is displayed in the shell.

## Exiting the Game

You can exit the game by:

Pressing the ESC key (closes the window and quits the program).
Clicking on the red cross on the window's frame (also closes the window and quits).
