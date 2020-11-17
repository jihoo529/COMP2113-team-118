#include <iostream>
#include <string>
#include <fstream>
#include "load_data.h"
#include "load_name.h"
#include "tutorial.h"
using namespace std;

const int MAXHP = 10000;
const int MAXAD = 10000;
const int MAXBP = 40;
const int MAXLEVEL = 100;
const int MAXUSERS = 5;

struct Player{
	int level, max_xp, current_xp, hp, ad, bp, cp;
};
struct Game_data{
	string username;
	Player play;
};
struct New_player{
	int level = 1;
	int max_xp = level*50;
	int current_xp = 0;
	int hp = 50, ad = 10, bp = 5;
	int cp = 0;
};
struct Usernames{
	string user[MAXUSERS];
	int num = 0;
};

void save_data();

int main(){
	ofstream fout;
	ifstream fin;
	Usernames user;
	Game_data data;
	int current_player = -1;
	cout << "Welcome to Dungeon" << endl;
	cout << "[1] New Player [2] Continue" << endl;
	load_name(*user.user[0], *user.num);
	int sel = 0;
	cin >> sel;
	cout << "Username : " << endl;
	string newname;
	cin >> newname;
	if(sel == 1){
		bool run = 1;
		while(run == 1){
			int count = 0;
			for(int i = 0; i<user.num; ++i){
				if(user.user[i] == newname){
					cout << "This username is unavailable." << endl;
				}
				else{++count;}
			}
			if(user.num == count){
				New_player initial;
				user.user[user.num] = newname;
				data.username = user.user[user.num];
				data.play.level = initial.level;
				data.play.max_xp = initial.max_xp;
				data.play.current_xp = initial.current_xp;
				data.play.hp = initial.hp;
				data.play.ad = initial.ad;
				data.play.bp = initial.bp;
				data.play.cp = initial.cp;
				current_player = user.num;
				++user.num;
				run = 0;
			}
		}
		tutorial();
	}
	else if(sel == 2){
		for(int i = 0; i<user.num; ++i){
			if(user.user[i] == newname){
				current_player = i;
				break;
			}
		}
		load_data(current_player, &data.username, &data.play.level, &data.play.max_xp, &data.play.current_xp, &data.play.hp, &data.play.ad, &data.play.bp, &data.play.cp);
	}
}
