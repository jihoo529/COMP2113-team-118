#include <iostream>
#include "village.h"
using namespace std;

void village(Game_data* data, int* location){
	int sel = 0;
	cout << "Village : [1] Go to store [2] Go to dungeon [3] Heal HP" << endl;
	if(sel == 1){location = 2;}
	else if(sel == 2){location = 3;}
	else if(sel == 3){}
}
