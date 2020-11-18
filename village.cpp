#include <iostream>
#include <fstream>
#include "village.h"
using namespace std;

void village(Game_data* data, int* location){
	ofstream fout;
	int sel = 0;
	cout << "Welcome to village" << endl;
	cout << "Village : [1] Go to store [2] Go to dungeon [3] Heal HP [4] Save" << endl;
	cin >> sel;
	if(sel == 1){location = 2;}
	else if(sel == 2){location = 3;}
	else if(sel == 3){
		hp = totalHP;
		cout << "Healed... [HP] " << hp << " / " << totalHP << endl;
	}
	else if(sel == 4){
		\\ save_data();
	}
}
