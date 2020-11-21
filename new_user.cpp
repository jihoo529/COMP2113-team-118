#include <iostream>
#include <string>
#include "new_user.h"
//#include "common.h"
using namespace std;

Usernames user;
Game_data data;
New_player initial;
int current_player;

void new_user(Usernames* user, Game_data* data, int* current_player, New_player initial){
	//This function creates a new player by checking the duplication of the usernames and initializing all the player statistics.
	//The input of this function is the New_player structure and Usernames structure. The New_player structure is used for initializing the new player's statistics by saving the
	//values into Game_data structure, and the Usernames structure is used for checking the duplication of the new username.
	//The output of this function is the Game_data structure and current_player integer. The New_player structure values are copied to Game_data structure so the the new player
	//can begin the game with this statistics. The current_player integer indicates the ID of the user, allowing the program to load and save the data in the correct place.
	bool run = 1;
	while(run == 1){
		cout << "Username : ";
		string newname;
		cin >> newname;
		int count = 0;
		for(int i = 0; i<user->num; ++i){
			if(user->user[i] == newname){
				cout << "This username is unavailable." << endl;
			}
			else{++count;}
		}//end of for loop 1
		
		if(user->num == count){
			data->username = newname;
			data->play.level = initial.level;
			data->play.max_xp = initial.max_xp;
			data->play.current_xp = initial.current_xp;
			data->play.totalHP = initial.totalHP;
			data->play.hp = initial.hp;
			data->play.ad = initial.ad;
			data->play.bp = initial.bp;
			data->play.cp = initial.cp;
			data->play.money = initial.money;
			data->play.nump = initial.nump;
			current_player[0] = user->num;
			++user->num;
			run = 0;
		}
	}
}
