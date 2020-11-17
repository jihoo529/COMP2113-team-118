#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const MAXHP = 10000;
const MAXAD = 10000;
const MAXBP = 40;
const MAXLEVEL = 100;
const MAXUSERS = 5;
struct Player{
	int level, max_xp, current_xp, hp, ad, bp, cp, debuff;
};
struct Game_data{
	string username;
	Player play;
};
struct New_player{
	int level = 1;
	int max_xp = level*50;
	int current_xp = 0;
	int hp = 50, ad = 10, bp = 1;
	int cp = 0, debuff = 0;
};

void load_data(string* username, int* level, int* max_xp, int* current_xp, int* hp, int* ad, int* bp, int* cp, int* debuff);
void save_data();
string check_name();

int main(){
	ofstream fout;
	ifstream fin;
	Game_data data[MAXUSERS];
	cout << "Welcome to Dungeon" << endl;
	cout << "[1] New Player [2] Continue" << endl;
	load_data(&data[0].username, &data[0].play.level, &data[0].play.max_xp, &data[0].play.current_xp, &data[0].play.hp, &data[0].play.ad, &data[0].play.bp, &data[0].play.cp, &data[0].play.debuff);
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

}

void load_data(string* username, int* level, int* max_xp, int* current_xp, int* hp, int* ad, int* bp, int* cp, int* debuff){
	ifstream fin;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		exit(1);
	}
	for(int i=0; i<MAXUSERS; ++i){
		getline(fin, line);
		int index = line.find(" ");
		username[i] = line.substr(0, index);
		line = line.erase(0, index);
		index = line.find(" ");
		level[i] = line.substr(0, index);
		line = line.erase(0, index);
		index = line.find(" ");
		max_xp[i] = line.substr(0, index);
		line = line.erase(0, index);
		index = line.find(" ");
		current_xp[i] = line.substr(0, index);
		line = line.erase(0, index);
		index = line.find(" ");
		hp[i] = line.substr(0, index);
		line = line.erase(0, index);
		index = line.find(" ");
		ad[i] = line.substr(0, index);
		line = line.erase(0, index);
		index = line.find(" ");
		bp[i] = line.substr(0, index);
		line = line.erase(0, index);
		index = line.find(" ");
		cp[i] = line.substr(0, index);
		line = line.erase(0 , index);
		debuff[i] = line;
	}
}
