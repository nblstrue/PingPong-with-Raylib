# Stellar Pong Game

A simple game of ping pong in space (actually that makes no sense but whatever).

You can find the code itself in the folder "1st Game", or the game itself with songs in the folder "Stellar Pong Game".

## To be able to play this game, you need:
- RayLib 5.0 (in the C:/ disk) ; ( https://www.raylib.com )
- Visual Studio Code (to change the code or see what it looks like) with the C/C++ extension ;
( https://code.visualstudio.com )
- MinGW as the compiler (v6.3.0 or later, and in the C:/ disk) ; ( https://sourceforge.net/projects/mingw/files/MinGW/Base/gcc/Version6/gcc-6.3.0/ )

The configuration to make Raylib 5.0 work with VS Code is already done in the folder, so you don't need to do it youself.

If you are interested in this library, join our discord server linked in the official site.

### Version 1.2 (Mid January 2024): 

- Game ends with a text saying that you beat the game (obtainable with a score of 40) ;
- My name on the top right corner :) .

### Version 1.5 (10th February 2024):

- Changing musics depending on the score (no way ?!) ;
- Changing backgrounds depending on the score ;
- Starting window showing you how to control the platform .

### Version 1.8 (14th February 2024):

- Saving progress in "spg.save" ;
- score incrementation from 10 to 2 ;
- Screenshots possible with  CTRL_Key + S_Key .

### Version 1.8.5 (1st of March 2024)

- Two starting window showing you the objective and how to control the platform .

### Update 1.0 (10th of March 2024)

- Bug n°1 = When score decrement to 10, when it was above 10, score reset to 0 (problem is the (score < 10) if condition) ;
- Issue n°1 = The music function if conditions were not optimal ;
- Bug n°2 = The ball could be stuck at the limit of the Window. Added a simple function to reload the ball's positions .

### What will happen in the Future ?

This game is going to have a sequel: Stellar Pong Game 2. It will be build on this game and upgraded to the M.A.X :

- It will be much more colorful ;
- Changing textures that actually WORKS and doesn't bring lots of lag ;
- A better score and saving system ;
- Much mroe things that i will think about during the developpement .
