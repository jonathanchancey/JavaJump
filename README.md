# JavaJump

### Introduction
Java Jump is an OpenGL based endless runner video game starring the titular character Java, a black and white Rat Terrier, jumping over bones of various sizes to avoid colliding with them and as this would prompt a game over. While the dog the player character is based on would do everything in her power to retrieve every bone thrown her way this fictionalized version attempts to dodge them to earn a high score. Java Jump is heavily inspired by the Google Chrome Dinosaur endless runner game and as such the team tried to emulate the different facets of the original while making some changes the group personally felt would make the game more enjoyable and while adding our own charm to the project.


### Movement
The most crucial detail to nail in an endless runner is for the jump to feel good as this is one of the few inputs the player has that effects the game world. Without a satisfying jump the game will not be fun to play even if high quality assets are present. We started with a jump that emulated the one presented by the original template given for the final project but changed the jump height. fall speed, position of the player character, and removed the ability to move left in right. After we decided we were okay with the jump at that stage of development we immediately scrapped it in favor of a free form style of movement for about two days. In this style you could move all directions and the enemies would come at you from different angles. We changed the philosophy back to the original after we decided the gameplay deviated too much from the Google Dinosaur game and because we wanted to add animations and believed it would have been harder to make them believable in that environment. Following this stint into different genre we went back to having Java only being able to jump but this time we enhanced it to make it feel more fluid by using velocity and acceleration in the form of speed and gravity.


### Art/Animation
The art for the game was started even before the first project proposal was finished and we decided to go with a pixel art style to reflect the game that Java Jump was inspired by but also because it is is fairly easy to create assets in this style without having to have a particular eye, or talent, for art creation. The first assets we created were for the player character Java. These were eventually updated with Adobe Photoshop in the lowest resolution possible and then later scaled up so they would look higher quality in game. Throughout the development cycled we also added animations Java to give a greater sense of speed and interaction with the player. Before we had access to Photoshop, we had to use an online pixel art creator called Piskelapp. While its tools were limited, this website was what was used to create the different bone textures. The background was initially a 2400x600 pixel file, but that proved to be much too large for OpenGL to load consistently. We then cut the width in half and created two instances of the background that looped seamlessly.


### Enemy/Obstacle Implementation
Mob spawns are all handled in the Enemies class. This class handles everything to due with spawning mobs through using a vector of bones. As bones are created, they are put into a vector. Every game tick, the bones are moved to the left by the value of the speed variable in the class. Bones’ speed are also updated as the Enemies class speed is changed to make everything consistent. Bones are spawned at random intervals, from 25 ticks to up to 65. The Enemies class also deals with despawning bones after they leave the screen, this helps keep our vector small. 

### Installation

Linux:
 - Type make to compile the application
 - The makefile will compile all .cpp files in the folder
 - Edit the makefile to change the name of the executable
 - By default ./glutapp should run the program.

Windows:
 - Visual Studio 2015 is required although 2017 has been reported to work as well.
 - Just like macOS, setting the working directory may be required to run. 
 - Simply open the solution (glutapp.sln) in visualc15
 
macOS:
 - Use the glutapp.xcodeproj file to open the project in XCode
 - Navigate to Product->Scheme->Edit->Run->Options->Working Directory and check "Use cutom working directory" and enter $(SRCROOT)
 - It has been tested with XCode 8 on macOS Sierra 10.12
