#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dungeon.h"
#include "common.h"

using namespace std;

//const stat[] = { }



void dungeon(Game_data* data, int* location){
	srand(time(0));
		
 	int turn = random() % 10;
	//int totalHP = stat[INDEX];//totalHP = initial HP 
	//int totHP = data.hp;

	int totalmonHP = monHP;
	int win;
	if(turn >= 5){
		turn = 1;
	}else{turn = 0;}
	
	
	int run = 1; int ult = 1;
	int damage;
	while(run == 1){
		srand(time(0));
		int monAD; int monHP; int monBP; int gold;
		int mon = random() % 10;
		if(0 <= mon && mon <= 5){
			monAD = 0.8 * data->play.ad;
			monHP = 0.8 * data->play.hp;
			monBP = 0.8 * data->play.bp;
			gold = 20;

		}
		else if(5 < mon && 9 > mon){
			monAD = data->play.ad;
			monHP = data->play.hp;
			monBP = data->play.bp;
			gold = 30;
		}
		else if(mon == 9){
			monAD = 1.2 * data->play.ad;
			monHP = 1.2 * data->play.hp;
			monBP = 1.2 * data->play.bp;
			gold = 50;
		}
		std::system("clear");
		cout << "[HP] " << data->play.hp << " / " << data->play.totalHP << endl;
		cout << "[Enemy] " << monHP << " / " << totalmonHP << endl;
		int input;
		int winXP = 25; float prob;
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
					if(prob < data->play.cp){
						damage = data->play.ad * 2; // calculating critical damage
						cout << "Critical HIT !!" << endl;
					}
					else{
						damage = data->play.ad;
					}

					cout << damage << " damage dealt !" << endl;
					//cout << monHP - damage << "/" << monHP << endl; ; //damage dealt to monster
					monHP = monHP - damage;
				}
			}
			else if(input == 2){
				cout << (data->play.totalHP-data->play.hp) *0.5 << " healed !" << endl;
				data->play.hp = (data->play.totalHP - data->play.hp)*0.5 + data->play.hp ; //Reset HP
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

			if(prob < data->play.bp){
					cout << "Blocked enemy's attack !" << endl;
			}else{
				if(ult % 3 == 0){
					cout << "Enemy got angree !" << endl;
					cout << "Damaged by " << monDamage <<"!!!" << endl; //monster gives double damage every 3 times of attack
				}else{
					cout << "Damaged by " << monDamage <<"!"<< endl;
				}
				data->play.hp = data->play.hp - monDamage;
				//cout << "[HP] " << HP << " / " << totalHP << endl;
			}
			
			ult += 1;
			turn = 1;
			sleep(2);
		}
		//sleep(2);

		if(data->play.hp <= 0){
			std::system("clear");
			cout << "YOU: [HP] 0 / " << data->play.totalHP << endl;
			cout << "ENEMY: [HP] " << monHP << " / " << totalmonHP << endl;
			cout << "....." << endl;
			cout << "You seriously injured... heading back to village" << endl;
			cout << "You lost " << gold << " golds..." << endl;
			data->play.money -= gold;
			run = 0;
			win = 0;
		}
		if(monHP <= 0){
			std::system("clear");
			cout << "YOU: [HP] " << data->play.hp << " / " << data->play.totalHP << endl;
			cout << "ENEMY: [HP] 0 / " << totalmonHP << endl;
			cout << "You defeated the monster!" << endl;
			cout << winXP << " xp gained !" << endl;
			cout << gold << " gained !" << endl;
			data->play.money += gold;
			//level up
			if(data->play.current_xp + winXP > data->play.max_xp){
				data->play.current_xp = data->play.current_xp + winXP - data->play.max_xp;
				data->play.level ++;
				cout << "Level up ! Level : " << data->play.level << endl;
			}
			run = 0;
			win = 1;
		}
		if(win == 1){
			cout << "Continue with dungeon ?" << endl;
			int input;
			cout << "1.Yes 2.No" << endl;
			cin >> input;
			if(input == 1){
				location[0] = 2;
				continue;
				
			}
			else if(input == 2){
				location[0] = 1;
				cout << "Returning to village ... " << endl;
				run = 0;
			}
		}
		else if(win == 0){
			location[0] = 1;
			run = 0;
		}
		
	}//end of while (run == 1) loop
	
}




