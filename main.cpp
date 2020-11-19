#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "load_data.h"
#include "new_user.h"
#include "village.h"
#include "store.h"
#include "dungeon.h"
#include "common.h"
using namespace std;

const int MAXHP = 10000;
const int MAXAD = 10000;
const int MAXBP = 40;
const int MAXLEVEL = 100;
/*
struct Player{
	int level, max_xp, current_xp, totalHP, hp, ad, bp, cp, money;
};
struct Game_data{
	string username;
	Player play;
};
struct New_player{
	int level = 1;
	int max_xp = level*50;
	int current_xp = 0;
	int totalHP = 50, hp = 50, ad = 10, bp = 5;
	int cp = 0;
	int money = 100;
};
struct Usernames{
	int num = 0;
	string *user = new string [num];
};
*/
void tutorial(){
	int run = 1;
	while(run == 1){
		system("clear");
		cout << "Welcome to our village !" << endl;
		sleep(1.5);
		cout << "You can either travel dungeon or visit store in this village" << endl;
		sleep(1.5);
		cout << "You can buy health potions or upgrade your weapon in the store" << endl;
		cout << "If you upgrade your weapon, you will give more critical damage to enemy." << endl;
		sleep(1.5);
		cout << "You can level up if you defeat your enemy. Your abilities will then be enhanced" << endl;
		cout << "But if you lose, you have to get back to village. Enemy will take some gold from you" << endl;
		sleep(1.5);
		cout << "Then..... GOOD LUCK !!!" << endl;
		cout << endl;
		cout << "If you want to go through again, please enter 1. Enter 2 other wise" << endl;
		int input;
		cin >> input;
		if(input == 1){
			continue;
		}else if(input == 2){
			break;
		}
	}
	
}

/* void save_data(Gace_data* data, int* location);
\\ void village(Game_data* data, int* location);
\\ void store(Game_data* data, int* location);
\\ void dungeon(Game_data* data, int* location);*/

int main(){
	Usernames user;
	Game_data data;
	int current_player = -1;
	cout << "Welcome to Dungeon" << endl;
	cout << "[1] New Player [2] Continue" << endl;
	ifstream fin;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){exit(1);}
	while(getline(fin, line)){
		int index = line.find(" ");
		string p = line.substr(0, index);
		string* temp = new string[user.num + 1];
		for(int i = 0; i<user.num; ++i){
			temp[i] = user.user[i];
		}
		temp[user.num] = p;
		++user.num;
		user.user = &temp;
		delete[] &temp;
	}
	int sel = 0;
	cin >> sel;
	if(sel == 1){
		New_player initial;
		new_user(&user, &data, &current_player, initial);
		tutorial();
	}
	else if(sel == 2){
		for(int i = 0; i<user.num; ++i){
			cout << "[" << i << "]" << user.user[i] << endl;
		}
		cin >> current_player;
		load_data(current_player, data);
	}
	location[0] = 1;
	while(location != 0){
		if(location == 1){village(data, location);}
		else if(location == 2){store(data, location);}
		else if(location == 3){dungeon(data, location);}
	}
	cout << "Game quit... See you next time!" << endl;
}
