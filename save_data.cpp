#include <iostream>
#include <fstream>
#include <string>
#include "save_data.h"
using namespace std;

void save_data(Game_data* data, Game_data.play* play, int* location){
	ifstream fin;
	ofstream fout;
	int total_player=0;
	int player=0;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		cout << "There was a problem in accessing the game memory (1)" << endl;
		exit(1);
	}
	while(getline(fin, line)){
		int index = line.find(" ");
		if(data.username == line.substr(0, index)){
			player = i;
		}
		++total_player;
	}
	line.erase();
	string* text = new string[total_player];
	for(int i = 0; i<total_player; ++i){
		if(i == player){
			line = data.username + " ";
			line = play.level + " ";
			line = play.max_xp + " ";
			line = play.current_xp + " ";
			line = play.totalHP + " ";
			line = play.hp + " ";
			line = play.ad + " ";
			line = play.bp + " ";
			line = play.cp + " ";
			line = play.money;
			text[i] = line;
			++i;
		}
		getline(fin, text[i]);
	}
	fin.close();
	fout.open("game_users.txt");
	if(fout.fail()){
		cout << "There was a problem in accessing the game memory (2)" << endl;
		exit(1);
	}
	for(int i = 0; i<total_player; ++i){
		fout << text[i] << endl;
	}
	fout.close();
	cout << "Continue? [1] Yes [2] Quit" << endl;
	int sel = 0;
	if(sel == 1){
		location = 1;
	}
	else if(sel == 2){
		location = 0;
	}
}
