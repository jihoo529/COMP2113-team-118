#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "village.h"
#include "save_data.h"
//#include "common.h"
using namespace std;

//struct Game_data;
//Game_data data;
//void save_data(Game_data* data, int* location);

void village(Game_data* data, int* location, int current_player){
	system("clear");
	ofstream fout;
	int sel = 0;
	cout << "Welcome to village " << data->username << endl;
	cout << "[LV] " << data->play.level << endl;
	cout << "[XP] " << data->play.current_xp << "/" << data->play.max_xp << endl;
	cout << "[HP] " << data->play.hp << "/" << data->play.totalHP << endl;
	cout << "[AD] " << data->play.ad << endl;
	cout << "[CP] " << data->play.cp << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "Village : [1] Go to store [2] Go to dungeon [3] Heal HP [4] Save" << endl;
	
	
	
	cin >> sel;
	if(sel == 1){location[0] = 2;}
	else if(sel == 2){location[0] = 3;}
	else if(sel == 3){
		data->play.hp = data->play.totalHP;
		cout << "Healed... [HP] " << data->play.hp << " / " << data->play.totalHP << endl;
		sleep(2);
	}
	else if(sel == 4){
		save_data(data, location, current_player);
	}
	/*else if(data->play.level >=2){
		cout << "Hidden underground dungeon is revealed. Enter [5] to enter..." << endl;
		if(sel == 5){
			location[0] = 3;
		}
	}*/
}
