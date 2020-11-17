#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

//const stat[] = { }

int main(/*double &stat[]*/){
	//sponMon(); //spnMon has 2 arguments, monLv and monBP (monBP is between 0 and 1)
	srand(time(0));
	int hp = 100;
	int ad = 20;
	int bp = 30;
	double xp = 50;
	int cp = 30;
	int monAD = 30;
	int monHP = 80;
	int monBP = 40;

 	int turn = random() % 10;
	//int totalHP = stat[INDEX];//totalHP = initial HP 
	int totalHP = hp;
	int totalmonHP = monHP;
	int win;
	if(turn >= 5){
		turn = 1;
	}else{turn = 0;}
	
	
	int run = 1; int ult = 1;
	int damage;
	while(run == 1){
		srand(time(0));
		std::system("clear");
		cout << "[HP] " << hp << " / " << totalHP << endl;
		cout << "[Enemy] " << monHP << " / " << totalmonHP << endl;
		int input;
		double winXP = xp * 0.25; float prob;
		if(turn == 1){
			cout << endl;
			cout << "What will you do ?" << endl;
			cout << "1. Attack" << endl;
			cout << "2. Health potion" << endl;
			cin >> input ;
			if(input == 1){
				prob = rand() % 100; //double between 0 and 1
				if(prob < monBP){//Monster's blocking probability
					cout << "Attack BLOCKED !"<< endl;
				}
				else{
					prob = rand() % 100; 
					if(prob < cp){
						damage = ad * 2; // calculating critical damage
						cout << "Critical HIT !!" << endl;
					}
					else{
						damage = ad;
					}

					cout << damage << " damage dealt !" << endl;
					//cout << monHP - damage << "/" << monHP << endl; ; //damage dealt to monster
					monHP = monHP - damage;
				}
			}
			else if(input == 2){
				cout << (totalHP-hp) *0.5 << " healed !" << endl;
				hp = (totalHP - hp)*0.5 + hp ; //Reset HP
			}
			turn = 0;
			sleep(2);
		}
		
		else if(turn == 0){//monster's turn
			int monDamage = monAD;
			cout << endl;
			cout << "Monster attaced you !" << endl;
			//cout << ult << endl;
			if(ult % 3 == 0){
				monDamage = 2 * monAD;
			}else{
				monDamage = monAD;
			}
			prob = rand() % 100;
			if(prob < bp){
					cout << "Blocked enemy's attack !" << endl;
			}else{
				if(ult % 3 == 0){
					cout << "Enemy got angree !" << endl;
					cout << "Damaged by " << monDamage <<"!!!" << endl; //monster gives double damage every 3 times of attack
				}else{
					cout << "Damaged by " << monDamage <<"!"<< endl;
				}
				hp = hp - monDamage;
				//cout << "[HP] " << HP << " / " << totalHP << endl;
			}
			
			
			
			ult += 1;
			turn = 1;
			sleep(2);
		}
		//sleep(2);

		if(hp <= 0){
			std::system("clear");
			cout << "YOU: [HP] 0 / " << totalHP << endl;
			cout << "ENEMY: [HP] " << monHP << " / " << totalmonHP << endl;
			cout << "....." << endl;
			cout << "You seriously injured... heading back to village" << endl;

			win = 0;
			run = 0;
		}
		if(monHP <= 0){
			std::system("clear");
			cout << "YOU: [HP] " << hp << " / " << totalHP << endl;
			cout << "ENEMY: [HP] 0 / " << totalmonHP << endl;
			cout << "You defeated the monster!" << endl;
			cout << winXP << " xp gained !" << endl;
			XP += winXP;
			win = 1;
			run = 0;
		}
		
	}

	cout << "game ended " << endl;
	return win;
	
}
