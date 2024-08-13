# Rock_Paper_Scissors
I made a program that recreates the childhood game of rock paper scissors in the form of a command-line game. In this game, the player is competing against their "friend" over who gets to fly a space ship that they have just stumbled upon. Once one of them wins (best 2 out of 3), a countdown sequence is initiated and either the player flys away, or the friend does. 

## What I learned 
In making this project I learned how to utilize 'strcmp()', a string comparison function, to validate the user's input. The countdown sequence utilizes a recursive function that starts from 10, subtracts 1 and repeats these steps until it reaches 0. Various 'sleep()' functions are sprinkled throughout the program for a cohesive flow, namely for the countdown sequence.

## Features
- Little short story
- Best 2 out of 3 rounds of rock paper scissors gameplay
- Randomized computer move against player
- Recursive countdown
- Sleep functions for added suspense 

## Winning Example
You and your bestfriend have stumbled upon an abandoned spaceship that you both want for yourselves!<br>
After arguing for hours, the decision was made to play rock paper scissors over who gets leave with <br>
the spaceship and who gets left behind...<br>

Round 1<br>
Enter your choice (rock/paper/scissors): rock<br>
Your friend chose: scissors<br>
You win!! Here's a point!!<br>

Round 2<br>
Enter your choice (rock/paper/scissors): paper<br>
Your friend chose: rock<br>
You win!! Here's a point!!<br>

Final Score - You: 2, Friend: 0<br>
Congratulations! You won the game and get to launch the spaceship!<br>
Initiating launch sequence...<br>
10<br>
9<br>
8<br>
7<br>
6<br>
5<br>
4<br>
3<br>
2<br>
1<br>
Liftoff!<br>
You've ditched your bestfriend... hope you're happy!<br>

## Losing Example
You and your bestfriend have stumbled upon an abandoned spaceship that you both want for yourselves! 
After arguing for hours, the decision was made to play rock paper scissors over who gets leave with 
the spaceship and who gets left behind...

Round 1<br>
Enter your choice (rock/paper/scissors): rock<br>
Your friend chose: paper<br>
You lose!!<br>

Round 2<br>
Enter your choice (rock/paper/scissors): scissors<br>
Your friend chose: rock<br>
You lose!!<br>

Final Score - You: 0, Friend: 2<br>
Your friend has won, prepare to be left behind...<br>
Initiating launch sequence...<br>
10<br>
9<br>
8<br>
7<br>
6<br>
5<br>
4<br>
3<br>
2<br>
1<br>
Liftoff!<br>
Your best friend has ditched you... you will never see them again...<br>
