#include <iostream>
#include <fstream>
#include "village.h"
#include "save_data.h"
#include "common.h"
using namespace std;

//struct Game_data;
Game_data data;

void village(Game_data* data, int* location){
	ofstream fout;
	int sel = 0;
	cout << "Welcome to village" << endl;
	cout << "Village : [1] Go to store [2] Go to dungeon [3] Heal HP [4] Save" << endl;
	cin >> sel;
	if(sel == 1){location[0] = 2;}
	else if(sel == 2){location[0] = 3;}
	else if(sel == 3){
		data->play.hp = data->play.totalHP;
		cout << "Healed... [HP] " << data->play.hp << " / " << data->play.totalHP << endl;
	}
	else if(sel == 4){
		Save_data(data, location);
	}
}
