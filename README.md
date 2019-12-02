# Tetris

### Goal
###### The project : game that reproduce the tetris !
###### The game is made is NCURSES.
###### This is a game over game : there is no ending, you have to make the best score.
###### The objective is to make line, when you make a line with the differents tetriminos the line disapear, if the map is full, you loose.

### Program compilation and launch:
  ```sh
        make
```
  ```sh
        ./tetris
```

##### HELP :
  ```sh
./tetris -h
```

The binary searches the directory : **"tetriminos"** where there are the shapes = tetriminos.
You can add as many as you want, the programm will check if they are valid or not, the file have to end in **".tetrimino"**.

### Commands :
- Right arrow : move tetrimino to the rigth.
- Left arrow : move tetrimino to the left.
- Upper arrow : can rotate the tetrimino.
- Space bar : pause in the game.

### Usage
- If you reduce the size of the window, it will pause the game and ask you to put it in fullscreen.
- On the left you can see the name of the next tetrimino, the score and the level.

#### Project realised by:
- **Alexandre Sachs : [alexandre.sachs@outlook.fr](https://github.com/SachsA)**
- **Corentin Thomazeau : [corentin.thomazeau@epitech.eu]()**
