#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "load_data.h"
#include "new_user.h"
#include "village.h"
#include "store.h"
#include "dungeon.h"
#include "save_data.h"
using namespace std;

void village(Game_data*, int*, int);
int location;

void tutorial(){
	//This function prints the instructions and the general rule of the game, explaining each locations (village, store, dungeon), what kind of monsters there are, what
	//the player can do with the gold they earned, and so on. There is no input nor output for this function. This function is called only when a new player is created.
	int run = 1; int con  = 0;
	while(run == 1){
		system("clear");
		cout << "$$$~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$$$" << endl;
		cout << "		     Welcome to our village !" << endl;
		sleep(1.5);
		cout << "You can either travel dungeon or visit store in this village." << endl; sleep(1);
		cout << "[Store] You can buy health potions or upgrade your weapon in the store." << endl; sleep(1);
		cout << "If you upgrade your weapon, it will give a critical damage to enemy more often." << endl; sleep(2);
		cout << "[1] Continue" << endl;
		cin >> con;
		if(con == 1){}
		con = 0;
		system("clear");
		cout << "[Dungeon] There are 3 types of monsters in dungeon. A weak, normal, and a mini boss" << endl; sleep(1);
		cout << "Stronger monsters will give more golds if you defeat them." << endl; sleep(1);
		cout << "You can level up and earn gold if you defeat your enemy. Your abilities will then be enhanced" << endl; sleep(1);
		cout << "You can either further travel the dungeon or go back to village if you defeat. Bonus gold will be given if you further travel the dungeon." << endl; sleep(1);
		cout << "But if you lose, you have to go back to village. Enemy will take some gold from you" << endl; sleep(2);
		cout << "[1] Continue" << endl;
		cin >> con;
		if(con == 1){}
		con = 0;
		system("clear");
		cout << "You can enter the BOSS dungeon if you reach level 5." << endl;
		cout << "The boss is very powerful, make sure to enhance your abilities enough before the battle with boss." << endl;
		cout << endl;
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
		tutorial();
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
		if(data.play.bp > 60){data.play.bp = 60;}
		if(data.play.cp > 100){data.play.cp = 100;}
		if(data.play.money < 0){data.play.money = 0;}
		if(data.play.level > 100){data.play.level = 100;}
		if(data.play.nump < 0){data.play.nump = 0;}
		
		if(location == 1){village(&data, &location, current_player);}
		else if(location == 2){store(&data, &location);}
		else if(location == 3){dungeon(&data, &location);}
		else if(location == 10){
			system("clear");
			cout << "Congratulations! You defeated Demogorgon and saved the village.." << endl;
			sleep(2);
			cout << "Now you can enjoy the game freely by earning golds and XPs to further strengthen yourself." << endl;
			sleep(2);
			cout << "Thank you for playing." << endl;
			sleep(2);
			cout << endl;
			cout << "<Credits>" << endl;
			cout << endl;
			cout << "Eunhye Yang" << endl; cout << endl;
			cout << "Jihoo Lee" << endl;
			sleep(4);
			location = 1;
		}
	}
	cout << "Game quit... See you next time!" << endl;
}
\
