#include <iostream>
#include <string>
#include <fstream>
#include "load_data.h"
#include "load_name.h"
#include "new_user.h"
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
		new_user(&user, &data, initial);
		tutorial();
	}
	else if(sel == 2){
		for(int i = 0; i<user.num; ++i){
			if(user.user[i] == newname){
				current_player = i;
				break;
			}
		}
		load_data(current_player, &data);
	}
}
