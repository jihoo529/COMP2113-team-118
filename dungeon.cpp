#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dungeon.h"
//#include "common.h"

using namespace std;

//const stat[] = { }
//int* try = 0;


void dungeon(Game_data* data, int* location){
	srand(time(0));
	//int* try;
	
 	int turn = random() % 2;
	
	int win = 2;
	int run = 1; int ult = 1;
	int damage;
	int init = 0; 
	while(run == 1){
		int monAD; int monHP; float monBP; int gold; int monType; int totalmonHP; int winXP;
		if(init == 0){
			//int try = 0;
			srand(time(0));
			int mon = random() % 10;
			if(0 <= mon && mon <= 3){
				monAD = 0.5 * data->play.ad;
				monHP = 0.5 * data->play.totalHP;
				monBP = 0.5 * data->play.bp;
				gold = 20;
				monType = 0;
				winXP = 15;

			}
			else if(3 < mon && 9 > mon){
				monAD = 0.8 * data->play.ad;
				monHP =   data->play.totalHP;
				monBP = 0.8 * data->play.bp;
				gold = 30;
				monType = 1;
				winXP = 25;
			}
			else if(mon == 9){
				monAD = 1.5 * data->play.ad;
				monHP = 1.2 * data->play.totalHP;
				monBP = 1 * data->play.bp;
				gold = 50;
				monType = 2;
				winXP = 50;
			}
			totalmonHP = monHP;
			init = 1;
		}
		
		std::system("clear");
		if(monType == 0){cout << "weak" << endl;}
		else if(monType == 1){cout << "normal" << endl;}
		else if(monType == 2){cout << "strong !!" << endl;}
		cout << "[HP] " << data->play.hp << " / " << data->play.totalHP << endl;
		cout << "[Enemy] " << monHP << " / " << totalmonHP << endl;
		int input;
		float prob;
		if(turn == 1){
			cout << endl;
			cout << "What will you do ?" << endl;
			cout << "[1] Attack" << endl;
			cout << "[2] Health potion (" <<data->play.nump << " left)" << endl;
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
				if(data->play.nump < 1){
					cout << "Not enough health potion !" << endl;
					turn = 1;
					sleep(2);
					continue;
				}
				else{
					int heal_amount = (data->play.totalHP-data->play.hp) *0.8;
					cout << heal_amount << " healed !" << endl;
					data->play.hp = heal_amount + data->play.hp ;//Reset HP
					data->play.nump -= 1;
				}
			}
			turn = 0;
			sleep(2);
		}
		
		else if(turn == 0){//monster's turn
			int monDamage = monAD;
			cout << endl;
			cout << "Monster attacked you !" << endl;
			//cout << ult << endl;
			if(ult % 3 == 0){
				monDamage = 1.2 * monAD;
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
			cout << "-------------------------------------------------" << endl;
			cout << "....." << endl;
			cout << "You seriously injured... heading back to village" << endl;
			cout << "You lost " << 20 << " golds..." << endl;
			data->play.money -= 20;
			run = 0;
			win = 0;
			sleep(2);
		}
		if(monHP <= 0){
			std::system("clear");
			cout << "YOU: [HP] " << data->play.hp << " / " << data->play.totalHP << endl;
			cout << "ENEMY: [HP] 0 / " << totalmonHP << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "You defeated the monster!" << endl;
			cout << winXP << " xp gained !" << endl;
			cout << gold << " gold gained !" << endl;
			//
			data->play.money += gold;
			//level up
			if(data->play.current_xp + winXP >= data->play.max_xp){
				data->play.current_xp = data->play.current_xp + winXP - data->play.max_xp;
				data->play.level ++;
				data->play.totalHP += 20;
				data->play.ad += 5;
				data->play.bp += 5;
				data->play.max_xp = data->play.max_xp * 1.5;
				cout << "Level up ! Level : " << data->play.level << endl;
			}else{
				data->play.current_xp += winXP;
			}
				
			run = 0;
			win = 1;
		}
		if(win == 1){
			cout << "Continue with dungeon ?" << endl;
			int input;
			cout << "[1] Yes [2] No" << endl;
			cin >> input;
			if(input == 1){
				location[0] = 3;
				cout <<"Bonus gold [" << gold*0.2 << "] gained !" << endl; sleep(2);
				data->play.money += gold*0.2;
				
				//try += 1;
				continue;
				
			}
			else if(input == 2){
				location[0] = 1;
				cout << "Returning to village ... " << endl;
				//try = 0;
				run = 0;
			}
		}
		else if(win == 0){
			sleep(2);
			location[0] = 1;
			//try = 0;
			run = 0;
		}
		
	}//end of while (run == 1) loop
	
}




