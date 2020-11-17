#include <iostream>
#include <string>
#include "load_data.h"
using namespace std;

void load_data(int current_player, string* username, int* level, int* max_xp, int* current_xp, int* hp, int* ad, int* bp, int* cp, int* debuff){
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
			username = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			level = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			max_xp = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			current_xp = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			hp = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			ad = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			bp = line.substr(0, index);
			line = line.erase(0, index);
			index = line.find(" ");
			cp = line.substr(0, index);
			line = line.erase(0 , index);
			debuff = line;
		}
	}
	fin.close();
}
