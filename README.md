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
