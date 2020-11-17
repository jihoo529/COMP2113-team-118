#include <iostream>
#include <string>
#include "load_data.h"
using namespace std;

void load_data(int current_player, Game_data* data){
	ifstream fin;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		exit(1);
	}
	for(int i=0; i<MAXUSERS; ++i){
		if(i == current_player){
			getline(fin, line);
			int index = line.find(" ");
			data.username = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			data.play.level = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			data.play.max_xp = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			data.play.current_xp = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			data.play.hp = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			data.play.ad = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			data.play.bp = line.substr(0, index);
			line = line.erase(0, index);
			data.play.cp = line;
		}
	}
	fin.close();
}
