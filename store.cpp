#include <iostream>
#include <unistd.h>
#include "store.h"
using namespace std;

void store(Game_data* data, int* location){
	//Game_data data
	int money = 1000;
	int run = 1;
	while(run == 1){
		system("clear");
		cout << "What do you wanna buy? You have " << money << " golds." << endl;
		cout << "1. Health potion - 30 gold" << endl;
		cout << "2. Upgrade weapon - 200 gold" << endl;
		cout << "3. No thanks" << endl;
		int input;
		cin >> input;
		if(input == 1){
			cout << "How many?" << endl;
			int n;
			cin >> n;
			if(money - n*30 < 0){
				cout << "Not enough gold !" << endl;
				sleep(3);
				continue;
			}
			else{
				cout << "Thank you" << endl;
				cout << "You got " << n << " health potions !" << endl;
				money = money - n* 30;
				cout << "You have " << money << " golds left" << endl;
				sleep(3);
				continue;
			}
		}
		else if(input == 2){
			if(money < 200){
				cout << "Not enough money... !" << endl;
				sleep(2);
				continue;
			}else{
				cout << "Black smith: upgraded completed ..!" << endl;
				cout << "Your critical probability has increased by 5" << endl;
				//data.play.cp += 5;
				money = money - 200;
				cout << "You have " << money << " golds left" << endl;
				sleep(3);
				continue;
			}
		}
		else if(input == 3){
			break;
		}
	}
	int location = 1;
	village(&data, &location);

}
