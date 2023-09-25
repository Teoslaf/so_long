SoLong - 2D Escape Game
SoLong is a simple 2D escape game where your character, whether it's a dolphin, hero, or any other creature, must collect valuables on a map and then make an escape. The game is built using the miniLibX library and follows specific rules and constraints.

Table of Contents
Usage
Map Format
Controls
Exiting the Game
Error Handling

Map Format
Maps for SoLong are constructed using three components: walls (1), collectibles (C), and free spaces (0). The player's goal is to collect all the collectibles and escape with minimal movement.

Map legend:

0: Empty space
1: Wall
C: Collectible
E: Exit
P: Player's starting position

Maps must be surrounded by walls, have at least one exit, one collectible, and one starting position. They must also be rectangular and follow the rules of the map. If any misconfiguration is encountered, the program will exit with an error message.

Controls
Use the W, A, S, and D keys to move the main character.
The game is not real-time, and movements are discrete.
The current number of movements is displayed in the shell.

Exiting the Game
You can exit the game by:
Pressing the ESC key (closes the window and quits the program).
Clicking on the red cross on the window's frame (also closes the window and quits).

Error Handling
If the program encounters any misconfiguration or errors in the map file, it will exit properly and display an error message, such as "Error: Invalid map format."
