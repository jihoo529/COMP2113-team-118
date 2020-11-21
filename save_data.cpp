#include <iostream>
#include <fstream>
#include <string>
#include "save_data.h"
using namespace std;

void save_data(Game_data* data, int* location, int current_player){
	//This function saves the game data into the text file "game_users.txt". This function is included in the village.
	//The input of the function is Game_data structure, and current_player integer. With the current_player integer, the function can recognize the player and overwrite the
	//data in the correct line of the text file, so that it will be easy for the program to access the correct game data when it tries to load it next time. The Game_data
	//structure is the data to overwrite on top of the existing data.
	//The output ofthe function is location integer. After saving the data, the function asks the player whether they will continue the game or not. If the player chooses to
	//continue playing the game, the location is set to 1, so that the player goes back to the village. If the player chooses to quit, then the location is set to 0, so that
	//the player quits the game.
	ifstream fin;
	ofstream fout;
	int total_player = 0; //initially 0
	int player = 0; //initially 0
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		cout << "There was a problem in accessing the game memory (1)" << endl;
		exit(1);
	}
	while(getline(fin, line)){++total_player;}
	if(current_player == -1){
		player = total_player;
		++total_player;
	}
	else{
		player = current_player;
		++total_player;
	}
	
	fin.close();
	string* text = new string[total_player];
	fin.open("game_users.txt");
	for(int i = 0; i<total_player; ++i){
		if(i == player){
			line.erase();
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
			getline(fin, line);
		}
		else{getline(fin, text[i]);}
	}
	fin.close();
	fout.open("game_users.txt");
	if(fout.fail()){
		cout << "There was a problem in accessing the game memory (2)" << endl;
		exit(1);
	}
	for(int i = 0; i<total_player; ++i){
		fout << text[i];
		if(i<(total_player-1)){fout << endl;}
	}
	fout.close();
	cout << "Continue? [1] Yes [2] Quit" << endl;
	int sel = 0;
	cin >> sel;
	if(sel == 1){location[0] = 1;}
	else if(sel == 2){location[0] = 0;}
}
