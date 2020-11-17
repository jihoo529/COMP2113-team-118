#include <iostream>
#include <ifstream>
using namespace std;

void load_name(string* user){
        ifstream fin;
	string line;
	fin.open("game_users.txt");
	if(fin.fail()){
		exit(1);
	}
	for(int i=0; i<MAXUSERS; ++i){
		getline(fin, line);
		int index = line.find(" ");
		user[i] = line.substr(0, index);
	}
	fin.close();
}
