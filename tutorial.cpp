#include <iostream>
#include <unistd.h>
using namespace std;

void tutorial(){
	int run = 1;
	while(run == 1){
		system("clear");
		cout << "Welcome to our village !" << endl;
		sleep(1.5);
		cout << "You can either travel dungeon or visit store in this village" << endl;
		sleep(1.5);
		cout << "You can buy health potions or upgrade your weapon in the store" << endl;
		cout << "If you upgrade your weapon, you will give more critical damage to enemy." << endl;
		sleep(1.5);
		cout << "You can level up if you defeat your enemy. Your abilities will then be enhanced" << endl;
		cout << "But if you lose, you have to get back to village. Enemy will take some gold from you" << endl;
		sleep(1.5);
		cout << "Then..... GOOD LUCK !!!" << endl;
		cout << endl;
		cout << "If you want to go through again, please enter 1. Enter 2 other wise" << endl;
		int input;
		cin >> input;
		if(input == 1){
			continue;
		}else if(input == 2){
			break;
		}
	}
	
}
