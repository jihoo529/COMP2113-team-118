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
	cout << "Username : " << endl;
	string newname;
	cin >> newname;
	bool run = 1;
	while(run == 1){
		int count = 0;
		for(int i = 0; i<user->num; ++i){
			if(user->user[i] == newname){
				cout << "This username is unavailable." << endl;
			}
			else{++count;}
		}
		if(user->num == count){
			user->user[user->num] = newname;
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
			run = 0;
		}
	}
}
