#include <iostream>
#include <string>
#include "load_data.h"
using namespace std;

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
