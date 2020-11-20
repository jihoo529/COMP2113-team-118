#include <iostream>
#include <fstream>
#include <string>
#include "save_data.h"
//#include "common.h"
using namespace std;

//Game_data data;

void save_data(Game_data* data, int* location){
	ifstream fin;
	ofstream fout;
	int total_player=1; //initially 0
	int player=1; //initially 0
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		cout << "There was a problem in accessing the game memory (1)" << endl;
		exit(1);
	}
	while(getline(fin, line)){
		int index = line.find(" ");
		if(data->username == line.substr(0, index)){
			player = index;
		}
		++total_player;
	}
	line.erase();
	string* text = new string[total_player];
	for(int i = 0; i<total_player; ++i){
		if(i == player){
			line = data->username + " ";
			line = data->play.level + " ";
			line = data->play.max_xp + " ";
			line = data->play.current_xp + " ";
			line = data->play.totalHP + " ";
			line = data->play.hp + " ";
			line = data->play.ad + " ";
			line = data->play.bp + " ";
			line = data->play.cp + " ";
			line = data->play.nump + " ";
			line = data->play.money + '\n';
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
	cin >> sel;
	if(sel == 1){
		location[0] = 1;
	}
	else if(sel == 2){
		location[0] = 0;
	}
}
