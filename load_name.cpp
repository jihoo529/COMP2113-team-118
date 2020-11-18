#include <iostream>
#include <ifstream>
#include "load_name.h"
using namespace std;

void load_name(string* user, int* num){
        ifstream fin;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		exit(1);
	}
	while(getline(fin, line)){
		++num;
		int index = line.find(" ");
		user[i] = line.substr(0, index);
	}
	fin.close();
}
