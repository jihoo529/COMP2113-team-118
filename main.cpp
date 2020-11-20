#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "load_data.h"
#include "new_user.h"
#include "village.h"
#include "store.h"
#include "dungeon.h"
//#include "common.h"
#include "save_data.h"
using namespace std;

void village(Game_data*, int*, int);
int location;
//extern int location;
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
	string *user = new string [0];
};
*/
void tutorial(){
	int run = 1;
	while(run == 1){
		system("clear");
		cout << "$$$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$$$" << endl;
		cout << "		     Welcome to our village !" << endl;
		sleep(1.5);
		cout << "You can either travel dungeon or visit store in this village." << endl; sleep(1);
		cout << "[Store] You can buy health potions or upgrade your weapon in the store." << endl; sleep(1);
		cout << "If you upgrade your weapon, it will give a critical damage to enemy more often." << endl; sleep(2);
		system("clear");
		cout << "[Dungeon] There are 3 types of monsters in dungeon. A weak, normal, and a mini boss" << endl; sleep(1);
		cout << "Stronger monsters will give more golds if you defeat them." << endl; sleep(1);
		cout << "You can level up and earn gold if you defeat your enemy. Your abilities will then be enhanced" << endl; sleep(1);
		cout << "You can either further travel the dungeon or go back to village if you defeat. Bonus gold will be given if you further travel the dungeon." << endl; sleep(1);
		cout << "But if you lose, you have to go back to village. Enemy will take some gold from you" << endl; sleep(2);
		system("clear");
		cout << "Then..... GOOD LUCK !!!" << endl;
		cout << endl;
		cout << "Do you want to go through the tutorial again? [1] Yes [2] No" << endl;
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
	system("clear");
	cout << "Welcome to Dungeon" << endl;
	cout << "[1] New Player [2] Continue" << endl;
	ifstream fin;
	ofstream fout;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		fin.close();
		fout.open("game_users.txt");
		fout.close();
	}
	else{
		while(getline(fin, line)){
			if(line.length() == 0){break;}
			string* temp = user.user;
			user.user = new string[user.num+1];
			for(int i = 0; i<user.num; ++i){
				user.user[i] = temp[i];
			}
			delete[] temp;
			int index = line.find(" ");
			user.user[user.num] = line.substr(0, index);
			++user.num;
		}
		fin.close();
	}
	int sel = 0;
	cin >> sel;
	if(sel == 1){
		New_player initial;
		new_user(&user, &data, &current_player, initial);
		//tutorial();
	}
	else if(sel == 2){
		cout << "Enter the number beside your username" << endl;
		for(int i = 0; i<user.num; ++i){
			cout << "[" << i << "] " << user.user[i] << endl;
		}
		cin >> current_player;
		load_data(current_player, user, &data);
	}
	location = 1;
	while(location != 0){
		if(data.play.hp < 0){data.play.hp = 0;}
		if(data.play.bp > 40){data.play.bp = 40;}
		if(data.play.cp > 60){data.play.cp = 40;}
		if(data.play.money < 0){data.play.money = 0;}
		if(data.play.level > 100){data.play.level = 100;}
		if(data.play.nump < 0){data.play.nump = 0;}
		
		if(location == 1){village(&data, &location, current_player);}
		else if(location == 2){store(&data, &location);}
		else if(location == 3){dungeon(&data, &location);}
	}
	cout << "Game quit... See you next time!" << endl;
}
