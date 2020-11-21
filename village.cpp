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
	//This function gives the player 4 choices: 1.Go to store, 2.Go to dungeon, 3.Heal HP, 4.Save
	//Also, the player can view their basic statistics in the village (LV, XP, HP, AD, CP) [BP is deliberately excluded, since it is not the ability that the player can access]
	//The input of this function is Game_data structure, location integer, and current_player integer. Game_data structure is used to print the player statistics, the loation
	//integer is used to take the player to the location they want to move to, and the current_player is not used in the village function, but in the save_data function.
	//The output of thsi function is location integer. When the player input the number corresponding to the location, the village outputs the location and takes the player to
	//the location that they want to move to.
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
