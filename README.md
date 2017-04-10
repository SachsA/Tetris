# tetris
Epitech, first year project. System_unix : game that reproduce the tetris ! The game is made is ncurses. This is a game over game : there is no ending, you have to make the bast score. The objective is to make line, when you make a line with the differents tetriminos the line disapear, if the map is full, you loose.

To compile : make To compile again and clean ".o" and the binary : make re. To clean all : make fclean.

to use it : ./tetris
(it search the directory : tetriminos where there are the forms = tetriminos, you can add as many as you want, the programm will check if they are valid or not, the file have to end in ".tetrimino")


TO SHOW THE HELP :
./tetris -h

commmands :
right arrow : move tetrimino to the rigth.
left arrow : move tetrimino to the left.
upper arrow : can rotate the tetrimino.
space bar : pause in the game.

If you reduce the size of the window, it will pause the game and ask you to put it in fullscreen.

On the left you can see the name of the next tetrimino, the score and teh level.
