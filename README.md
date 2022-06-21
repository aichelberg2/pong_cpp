# Pong in C++
My first attempt to create a C++ game:

## Motivation
In this project I'm trying to understand the basics of c++ based game development. I choose the most basic game out there: Pong.

## Process
I don't want any help from a youtube tutorial guiding me through everything. First steps are finding a starting point. I figure you need some kind of framework or engine to not start from complete scratch. I find [this reddit post](https://www.reddit.com/r/gamedev/comments/20mgt7/c_game_engines/) suggesting sfml in combination with OpenGL for the biggest part.  
I spent a long time getting everything running so now this project is a pretty solid template for stuff to follow. It's really important to adjust the CMakeList.txt to the packages you need in the "find_package(...)" command. When you add files to the project, they have to be mentioned in the "add_executable(...)" function.  

### Controls
The idea is to create two modes, single player and splitscreen. On controlers, the L-Stick moves the players whereas on the keyboard, W and S or ARROW UP and ARROW DOWN do.

