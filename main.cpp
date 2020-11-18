#include <iostream>
#include <string>
#include <fstream>
#include "load_data.h"
#include "load_name.h"
#include "new_user.h"
#include "tutorial.h"
#include "village.h"
#include "store.h"
#include "dungeon.h"
using namespace std;

const int MAXHP = 10000;
const int MAXAD = 10000;
const int MAXBP = 40;
const int MAXLEVEL = 100;

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

\\ void save_data(Gace_data* data, int* location);
\\ void village(Game_data* data, int* location);
\\ void store(Game_data* data, int* location);
\\ void dungeon(Game_data* data, int* location);

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
		string temp = new string [user.num + 1];
		for(int i = 0; i<user.num; ++i){
			temp[i] = user.user[i];
		}
		temp[user.num] = p;
		++user.num;
		user.user = temp;
		delete[] temp;
	}
	int sel = 0;
	cin >> sel;
	if(sel == 1){
		new_user(&user, &data, initial);
		tutorial();
	}
	else if(sel == 2){
		for(int i = 0; i<user.num; ++i){
			cout << "[" << i << "]" << user.user[i] << endl;
		}
		cin >> current_player;
		load_data(current_player, &data);
	}
	int location = 1;
	while(location != 0){
		if(location == 1){village(&data, &location);}
		else if(location == 2){store(&data, &location);}
		else if(location == 3){dungeon(&data, &location);}
	}
	cout << "Game quit... See you next time!" << endl;
}
