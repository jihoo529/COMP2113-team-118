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
	cout << "Username : ";
	bool run = 1;
	while(run == 1){
		string newname;
		cin >> newname;
		int count = 0;
		for(int i = 0; i<user->num; ++i){
			if(user->user[i] == newname){
				cout << "This username is unavailable." << endl;
			}
			else{++count;}
		}//end of for loop 1
		if((user->num+1) == count){
			string* temp = new string[user->num +1];
			for(int i = 0; i<user->num; ++i){
				temp[i] = user->user[i];
			}
			temp[user->num] = newname;
			user->user = temp;
			delete[] temp;
			data->username = user->user[user->num];
			data->play.level = initial.level;
			data->play.max_xp = initial.max_xp;
			data->play.current_xp = initial.current_xp;
			data->play.hp = initial.hp;
			data->play.ad = initial.ad;
			data->play.bp = initial.bp;
			data->play.cp = initial.cp;
			data->play.money = initial.money;
			current_player[0] = user->num;
			++user->num;
			//run = 0;
		}
		run = 0;
	}
}
