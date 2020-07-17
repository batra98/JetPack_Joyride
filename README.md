# JetPack Joyride

## About the game
It is a replica of the famous game [Jetpack Joyride](https://halfbrick.com/our-games/jetpack-joyride/) written in OpenGL 3.0.

![World](./gifs/World.gif)

## :file_folder: File Structure
```bash
.
├── CMakeLists.txt
├── README.md
├── assets
├── build
└── src

2 directories, 2 files
```
- **src** - Contains all the code for the game in cpp.

## :running: Running the game
* To build the game enter these command:
```bash
mkdir output
cd output
cmake ..
make all
```
* To run the game enter these command in the output directory:
```bash
./graphics_asgn1
```

## Overview
- The game has been themed on Batman vs Superman.
- The player plays as batman.
- The prime objective of the game is to score as much as possible.
- After a certain amount of time, a villian appears which needs to be defeated.
- In order to reach the villian, we need to avoid a number of obstacles.

![Villian](./gifs/Villian.gif)


## :video_game: Controls
- **Movement**
	- Move Forward: :arrow_right:
	- Move Backward: :arrow_left:
	- Jetpack: :arrow_up:
	- Shoot the villian (Superman): **F**
	- Zoom In/Out: Mouse Wheel
	- Water Balls: **Space**
	- Shield: **S**


### World
- **Flying Coins**: They have random velocity, random color. If the player hits the coin, coin disappears and player's score increases by 5.
- **Powerups** ​-There are 2 kinds of powerups, one which increases score and other which gives a
speed boost.
- **Firelines​** - Lines of fire appear at random angles which need to be avoided. -5 if collision occurs.
- **FireBeams** ​- Fire Beams move periodically on y-axis. -5 if touched.
- **Magnet** ​- Magnet causes a constant attractive force in its direction.
- **Water Balloons​** - Can be used to extinguish the firelines.
- **Semi-circular Ring** ​- Forces the player to move in a semi-circular fashion when touched.

**Score** ​is displayed on​ top right ​of window.


### Scoring
- Collision with normal coin : +5
- Collision with special flying coin : +10
- Collision with firelines: -5
- Collision with boomerang: -1

___________________________________________

Feel free to Contribute :heart:




