#include <iostream>
#include <string>
#include <fstream>
#include "load_data.h"
//#include "common.h"
using namespace std;

void load_data(int current_player, Usernames user, Game_data* data){
	ifstream fin;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		exit(1);
	}
	for(int i=0; i<user.num; ++i){
		if(i == current_player){
			getline(fin, line);
			int index = line.find(" ");
			data->username = line.substr(0, index);
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.level = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.max_xp = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.current_xp = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.totalHP = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.hp = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.ad = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.bp = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.cp = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			index = line.find(" ");
			data->play.nump = std::stoi(line.substr(0, index));
			line = line.erase(0, index+1);
			data->play.money = std::stoi(line);
		}
	}
	fin.close();
}
