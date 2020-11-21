Group 118
Name 1: Jihoo LEE (3035720386)
Name 2: Eunhye YANG (3035603497)

Basic rule of the game:
For this project, we will make a text Adventure game, where the user travels through the dungeon to conquer monsters and earn money. As the adventurer kills monsters, they earn certain amounts of money and experience points (xp) according to the monster level. With the money earned, the adventurer can go to the store and upgrade weapons, armor, or buy health potions that can be used during battle.

Level up:
With the xp gained, the player can level up, and for each level up, the player’s ability will be upgraded. However, as the level goes up, the maximum xp increases so that it takes more time to level up. Since the boss monster has very high health power and blocking probability, the player is required to earn money to buy items to clear the final stage.

Abilities of the player:
There are 3 main abilities of the player. They are health (HP), attack damage (AD), and blocking probability (BP). These 3 abilities can be upgraded by either buying items or by leveling up a player. There are other two special abilities, which can only be upgraded by buying items from the store. These abilities are critical probability (CP) and de-buff (decreasing enemy’s blocking probability).

Battle system:
The basic rule is the user and monster each take a turn attack. For the player, they can either choose to attack the monster or heal themselves using the potions they bought from the store. The monster’s HP will increase as the player’s level increases, making each level more difficult so that it fits the player’s level.

Locations:

Village: Starting point of the game; the player can return to village and heal themselves. The players can also save their game data here.

Store: Allows the player to buy items or upgrade their abilities with the money they earned from killing the monster.

Dungeon: Where the player encounters monsters of various strengths. When the player successfully kills a monster, the player gains money and xp.


Coding requirements

1.Generation of random game sets or events: In the dungeon, the player will encounter monsters with random levels. As the player’s level increases, the level of the monsters that player encounters will also increase.

2.Data structures for sorting game status: During the game, the player’s ability points will be saved via an array in heap memory, and when saving the player’s status, the array of abilities will be copied into a file.

3.Dynamic memory management: The abilities of a player (input) will be copied into the heap memory in the form of an array as the game starts. The array will be a 2D array, where each array is the game data of a player, and each player array has its own game data (HP, AD, BP, etc.). In the home menu of the game, the player can create or delete their account. As the player creates or deletes the account, the array in heap memory will be managed according to the player’s order (create/delete).

4.File input/output (e.g., for loading/saving game status): The players data is stored as an output text file, which includes the nickname and the player’s ability point. In the beginning of the game, the system inputs the text file and allows the player to choose its own account and continue the game once the account is created. The output of the code will be the players game data. The game data will be stored in heap memory, so the data in heap memory will be copied into the file, overwriting the file. To save the game data, the player should go to the village.

5.Program codes in multiple files: We will create several files when coding this game. Each function, such as the battle system, will be written in another file and used in the main file as a function.

UPDATED:

Group 118
Name 1: Jihoo LEE (3035720386)
Name 2: Eunhye YANG (3035603497)

Basic rule of the game:
This game is a simple text-based adventure game where the user escapades the dungeon to defeat the monsters in the dungeon. The player will earn experience points (xp) and gold that corresponds to the monster level. In the dungeon, there are three types of monsters, easy, intermediate, and difficult (mini boss). The player and the monster take turns to attack each other. With the gold earned, the player can buy hp potion or upgrade their weapon. Each time the player upgrades their weapon, the critical point increases. Critical point increases the probability of the player's critical hit (high damage). With the xp earned by defeating the monster, the player can level up. When the player reaches level 5, the game reveals a hidden dungeon, where the player encounters the final boss. Once the player defeats the boss, the player can still continue the game and keep on level up until they reach the maximum level. When the player's hp reaches 0, the player is returned back to the village.

Player abilities:

Level: The higher the player's level gets, the monsters also get stronger. So, the players should continue to earn gold and buy potions and upgrade their weapons.

HP: Health point of the player. When it reaches 0, the player is severely injured and is returned back to the village.

AD: Attack damage of the player. The player damages the monster as much as their ad each time they attack the monster.

BP: Blocking point of the player. The higher the bp, the more frequent the player blocks the monster's attack.

CP: Critical point of the player. The higher the cp, the more frequent the player achieves critical hit on the monster. Critical hit = 1.2*ad.

Locations:
Village: The player can heal themselves and save their game data.

Store: The player can buy health potions and/or upgrade their weapons (increase cp).

Dungeon: The player encounters monsters of random strength. After defeating a monster, the player can either choose to continue with the dungeon or can go back to the village. If the player chooses to continue with the dungeon, the player gains extra gold for combo. However, if the player dies in the middle of a battle with a monster, the player loses 20 gold.

Features (Coding requirements):
1. Random monsters (generation of random game sets or events): In the dungeon, the player encounters monsters of different strength randomly. Weak: 40%, Intermediate: 50%, Hard: 10%
2. Data structures for sorting game status: As soon as the game is loaded, the player data is moved to the Game_data structure, and this structure will be used throughout the game.
3. Multiple players continue (dynamic memory management): The players can continue with the game from where they left off. Multiple accounts can be made. When the program starts, the player can press 2 to continue. Then, a list of usernames is printed. To print the usernames, the program loads usernames from the file “game_users.txt” and appends it to the user.user array by dynamic memory management, because we don’t know how many accounts there are in the file “game_users.txt”.
4. Continue (File input/output): File input and output was utilized to implement the “continue” feature. When a new player is formed and saved for the first time, the program creates a text file called “game_users.txt”. Then, when the player loads their game data, the program reads the user data from the file and saves it to the Game_data structure to use it in the game.
5. Program codes in multiple files: To make the code lighter, we wrote one main.cpp file and wrote each of the functions in separate .cpp files (except tutorial()) and for each .cpp file, we wrote a header file, and compiled all of them with makefile. We have included our structures in another separate header file called “common.h”.

How to compile and execute the program:
1. In ubuntu or terminal, input '''make main''' to compile the codes.
2. Then, input '''./main''' to execute the program.
3. Enjoy the game.
4. In village, press 4 to save the game and then press 2 to quit the game.
5. To reload the game, input '''./main'''
6. The "game_users.txt" formed after game execution is for the game data. Do not delete this file unless you want to reset the whole program.
