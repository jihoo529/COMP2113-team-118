#include <iostream>
#include <fstream>
#include <string>
#include "save_data.h"
//#include "common.h"
using namespace std;

//Game_data data;

void save_data(Game_data* data, int* location, int current_player){
	ifstream fin;
	ofstream fout;
	int total_player = 0; //initially 0
	int player = 0; //initially 0
	int count = 0;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		cout << "There was a problem in accessing the game memory (1)" << endl;
		exit(1);
	}
	while(getline(fin, line)){
		int index = line.find(" ");
		++total_player;
		if(data->username == line.substr(0, index) && current_player != -1){
			player = current_player;
		}
		else{++count;}
	}
	if(total_player == count){
		player = count;
	}
	++count;
	fin.close();
	//cout << player << endl;
	//cout << total_player << endl;
	string* text = new string[count];
	line.erase();
	fin.open("game_users.txt");
	for(int i = 0; i<count; ++i){
		if(i == player){
			line += data->username + " ";
			line += to_string(data->play.level) + " ";
			line += to_string(data->play.max_xp) + " ";
			line += to_string(data->play.current_xp) + " ";
			line += to_string(data->play.totalHP) + " ";
			line += to_string(data->play.hp) + " ";
			line += to_string(data->play.ad) + " ";
			line += to_string(data->play.bp) + " ";
			line += to_string(data->play.cp) + " ";
			line += to_string(data->play.nump) + " ";
			line += to_string(data->play.money);
			text[i] = line;
		}
		else{getline(fin, text[i]);}
	}
	fin.close();
	fout.open("game_users.txt");
	if(fout.fail()){
		cout << "There was a problem in accessing the game memory (2)" << endl;
		exit(1);
	}
	for(int i = 0; i<count; ++i){
		fout << text[i];
		if(i<(count-1)){fout << endl;}
	}
	fout.close();
	cout << "Continue? [1] Yes [2] Quit" << endl;
	int sel = 0;
	cin >> sel;
	if(sel == 1){location[0] = 1;}
	else if(sel == 2){location[0] = 0;}
}
