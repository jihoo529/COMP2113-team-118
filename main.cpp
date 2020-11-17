#include <iostream>
#include <string>
#include <fstream>
#include "load_data.h"
using namespace std;
const int MAXHP = 10000;
const int MAXAD = 10000;
const int MAXBP = 100;
const int MAXCP = 100;
const int MAXLEVEL = 100;
const int MAXUSERS = 5;
struct Player{
	int level, max_xp, current_XP, HP, AD, BP, CP; // debuff; removed debuff
};
struct Game_data{
	string username;
	Player play;
};
struct New_player{
	int level = 1;
	int max_xp = level*50;
	int current_xp = 0;
	int HP = 50, AD = 10//, BP = 1;
	int BP = 10
	int CP = 0;
};
struct Usernames{
	string user[MAXUSERS];
}

void save_data();
string check_name();
string load_name();

int main(){
	ofstream fout;
	ifstream fin;
	Usernames user;
	Game_data data;
	cout << "Welcome to Dungeon" << endl;
	cout << "[1] New Player [2] Continue" << endl;
	load_name(*user.user[0]);
	int sel = 0;
	cin >> sel;
	if(sel == 1){
		bool run = 1;
		while(run == 1){
			int count = 0;
			cout << "Username : " << endl;
			string username;
			cin >> username;
			for(int i = 0; i<5; ++i){
				if(username == names.username[i]){
					cout << "Username already exists" << endl;
					break;
				}
				else{++count;}
			}
			if(count == 5){
				break;
			}
		}
	}
	else if(sel == 2){
		check_name(*user.);
	}
	load_data(&data.username, &data.play.level, &data.play.max_xp, &data.play.current_xp, &data.play.hp, &data.play.ad, &data.play.bp, &data.play.cp, &data.play.debuff);

}
