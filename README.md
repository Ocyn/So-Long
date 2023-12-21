<br/>
<p>
  <a href="https://github.com/Ocyn/So-Long">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/768px-42_Logo.svg.png" alt="Logo" width="80" height="80">
  </a>

  <h1>So Long</h1>

  <p>
    42 School Project | Made in 2023 - 2024
    <br/>
    <br/>
  </p>
</p>

![Contributors](https://img.shields.io/github/contributors/Ocyn/So-Long?color=dark-green) ![Issues](https://img.shields.io/github/issues/Ocyn/So-Long) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

The so_long project is a 2D game developed in C using the MiniLibX library. 
The objective of the game is for the player, represented by a character, to collect all items on the map and then escape by taking the shortest path possible. 
The game is controlled using the W, A, S, and D keys to move the character in four directions: up, down, left, and right.
Here's a brief overview of how the get_next_line function typically works:

## Built With

Here are a few examples.

* [C](https://en.wikipedia.org/wiki/C_(programming_language))

## Getting Started

**Warning: Compatibility Notice**

This project, so_long, has been entirely developed and tested on a Linux Ubuntu system. As a result, there may be compatibility issues when running the project on different operating systems. The usage of Linux-specific features, libraries, or commands may lead to unexpected behavior on non-Linux platforms.
It is strongly recommended to run this project on a Linux environment, preferably Ubuntu, to ensure optimal performance and compatibility. Attempting to execute the project on other operating systems may result in errors or unintended behavior.

Please take this compatibility notice into consideration before proceeding with the compilation and execution of the so_long project.

### Prerequisites

If you don't have Make
* Make

```sh
apt-get install build-essential make
```

### Installation

Clone the repo

```sh
git clone https://github.com/Ocyn/So-Long.git
cd So-Long/
```

### Compilation and Usage:

1. **Makefile:**
   - The project includes a Makefile with the following rules: `NAME`, `all`, `clean`, `fclean`, and `re`.

2. **Compilation:**
   - Compile the project using the provided Makefile.

   ```bash
   make
   ```
# Execution
Run the game with a map file (format: *.ber).
```bash
./so_long maps/example_map.ber
```
# Controls
Use the W, A, S, and D keys to move the player character.
Collect all items ('C') and reach the exit ('E') to win.
Displayed movement count in the shell.
Clean Up:

Clean up object files and executable.
```bash
make clean
```
Map Format (*.ber):
0: Empty space.
1: Wall.
C: Collectible item.
E: Exit.
P: Player's starting position.

# Map Examples
```plaintext

1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
```plaintext

1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```
## Rules and Requirements:
The game must use the MiniLibX library for graphical display.
The player's goal is to collect items and reach the exit.
The map must be rectangular, closed, and contain a valid path.
Proper error handling for map configuration.
Detailed controls and instructions are provided within the game.
Follow the provided instructions in the README file for successful compilation and execution of the game.

This project provides a convenient way to handle file input in C programs, allowing you to read lines from different file descriptors seamlessly.
## Authors

* **Ocyn** - *A Random Dev* - [Ocyn](https://github.com/Ocyn) - *Made the project*

## Acknowledgements

* [42 School](https://github.com/42School)
* 
