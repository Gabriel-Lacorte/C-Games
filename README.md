# C-Games

🕹 This repository contains a collection of classic games implemented in C.

## Game List

### 1. Snake Game 🐍

The Snake Game is a game where the player controls a snake that grows by eating food that appears in. The goal is to eat as much food as possible.

[![asciicast](https://asciinema.org/a/eOzppKRyROpcfo63ar1kkEu0b.svg)](https://asciinema.org/a/eOzppKRyROpcfo63ar1kkEu0b)

To compile the game, use the following command:
```bash
gcc snake.c -o snake -lncurses
```

---
For most games, you may need to install the 'ncurses' library. 
Here are the commands to install 'ncurses' on different Linux distributions: 

**Debian/Ubuntu:** 
```bash 
sudo apt-get install libncurses5-dev libncursesw5-dev
```
**Fedora/CentOS:** 
 ```bash 
sudo dnf install ncurses-devel
```
**Arch Linux:** 
 ```bash 
 sudo pacman -s ncurses
```

---
## License 
This project is licensed under the MIT license.
