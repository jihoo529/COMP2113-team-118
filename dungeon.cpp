#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include "dungeon.h"
using namespace std;

void dungeon(Game_data* data, int* location){
	//Dungeon function provides the display of monsters and the battle system. The battle system is based on probabilities, 3 types of monsters (weak, normal, and strong)
	//appears by certain probabilities. Normal monsters have the highest probability to appear, and strong monsters have the lowest. 
	//Inputs of the funcition are struct Game_data and location. Since abilities of monsters are based on player's abilities, and player's abilities should be modified
	//during the battle, dungeon function can access to these data by input Game_data* data. After the battle, player can either go back to village or further travel
	//dungeon. These can be done by changing int* location input.
	srand(time(0));
 	int turn = random() % 2;
	int win = 2;
	int run = 1; int ult = 1;
	int damage;
	int init = 0; 
	while(run == 1){
		int monAD; int monHP; float monBP; int gold; int monType; int totalmonHP; int winXP; string monName = "";	
		if(init == 0){
			srand(time(0));
			if(data->play.level >= 5){
			int sel;
			cout << "Hidden dungeon has been revealed. Do you want to go in?" << endl;
			cout << "[1] Yes [2] No, take me to normal dungeon" << endl;
			cin >> sel;
			if(sel == 1){
				monAD = 1.2* data->play.ad;
				monHP = 1.2* data->play.totalHP;
				monBP = 0.4*data->play.bp;
				monType = 3;
				monName = "Demogorgon";
				winXP = 100;
				gold = 300;
			}//boss stage
			else if(sel == 2){
				cout << "Returning back to original dungeon" << endl;
				sleep(2);
				}
			}
			int mon = random() % 10;
			if(0 <= mon && mon <= 3 && monType != 3){
				monAD = 0.5 * data->play.ad;
				monHP = 0.5 * data->play.totalHP;
				monBP = 0.2 * data->play.bp;
				gold = 30;
				monType = 0;
				winXP = 15;
				monName = "Slimer";

			}
			else if(3 < mon && 9 > mon && monType != 3){
				monAD = 0.8 * data->play.ad;
				monHP = 0.8 * data->play.totalHP;
				monBP = 0.4 * data->play.bp;
				gold = 50;;
				monType = 1;
				winXP = 25;
				monName = "Gorillta";
			}
			else if(mon == 9 && monType != 3){
				monAD = 1 * data->play.ad;
				monHP = 1 * data->play.totalHP;
				monBP = 0.6 * data->play.bp;
				gold = 100;
				monType = 2;
				winXP = 50;
				monName = "Spider Queen";
			}
			totalmonHP = monHP;
			init = 1;
		}
		std::system("clear");
		if(monType == 3 && init == 1){
			cout << "You have reached to the deepest part of underground dungeon ... " << endl; cout << endl;
			sleep(3);
			cout << "The ancient horror is now awaken ... " << endl; cout << endl;
			sleep(3);
			cout << "There is no way to hide." << endl; cout << endl;
			sleep(2);
			system("clear");
			init = 2;
		}
		cout << "[HP] " << data->play.hp << " / " << data->play.totalHP << endl;
		if(monType == 0){cout << "[Slimer] ";}
		else if(monType == 1){cout << "[Gorillta] " ;}
		else if(monType == 2){cout << "[Spider Queen] ";}
		else if(monType == 3){cout << "[Demogorgon] " ;}
		cout << monHP << " / " << totalmonHP << endl;
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
					cout << "Enemy BLOCKED your attact !"<< endl;
				}
				else{	
					int reflect = rand() % 3;
					int pass = 0;
					prob = rand() % 100; 
					int reflect_dam = 0.3 * data->play.ad;
				
					if(monType == 3 && reflect == 1){
						cout << "Monster REFLECTED your attack ...!" << endl;
						cout << "You are damaged by " << reflect_dam <<"!!"<< endl;
						data->play.hp -= reflect_dam;	
						pass = 1;
						
					}
					if(prob < data->play.cp && pass != 1){
						damage = data->play.ad * 2; // calculating critical damage
						cout << "CRITICAL HIT !!!" << endl;
						cout << damage << " damage dealt to enemy!" << endl;
						monHP = monHP - damage;
					}
					else if(prob >= data->play.cp && pass != 1){
						damage = data->play.ad;
						cout << damage << " damage dealt to enemy!" << endl;
						monHP = monHP - damage;
					}	
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
			if(monType == 0){cout << "[Slimer] ";}
			else if(monType == 1){cout << "[Gorillta] " ;}
			else if(monType == 2){cout << "[Spider Queen] ";}
			else if(monType == 3){cout << "[Demogorgon] " ;}
			cout <<" attacked you !" << endl;
			//cout << ult << endl;
			if(ult % 3 == 0){
				monDamage = 1.2 * monAD;
			}else{
				monDamage = monAD;
			}
			prob = rand() % 100;
			if(prob < data->play.bp){
					cout << "You BLOCKED enemy's attack !" << endl;
			}else{
				if(ult % 3 == 0){
					cout << "Enemy is on RAMPAGE !" << endl;
					cout << "You are damaged by " << monDamage <<"!!!" << endl; //monster gives double damage every 3 times of attack
				}else{
					cout << "You are damaged by " << monDamage <<"!"<< endl;
				}
				data->play.hp = data->play.hp - monDamage;
			}
			ult += 1;
			turn = 1;
			sleep(2);
		}
		if(data->play.hp <= 0){
			std::system("clear");
			cout << "YOU: [HP] 0 / " << data->play.totalHP << endl;
			cout << "ENEMY: [HP] " << monHP << " / " << totalmonHP << endl;
			cout << "-------------------------------------------------" << endl;
			cout << "....." << endl;
			cout << "You are seriously injured... heading back to village" << endl;
			cout << "You lost " << 20 << " golds..." << endl;
			data->play.money -= 20;
			data->play.hp = data->play.totalHP;
			run = 0;
			win = 0;
			sleep(2);
		}
		if(monHP <= 0){
			std::system("clear");
			if(monType == 3){
				cout << "You finally defeated the final boss of dungeon, the Demogorgon, hero..." << endl;
				win = 3;
				sleep(3);
			}
			if(monType != 3){
				cout << "YOU: [HP] " << data->play.hp << " / " << data->play.totalHP << endl;
				cout << "ENEMY: [HP] 0 / " << totalmonHP << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "You defeated "<<monName <<"!" << endl;
				cout << winXP << " xp gained !" << endl;
				cout << gold << " gold gained !" << endl;
				win = 1;
			}
			//
			data->play.money += gold;
			if(data->play.current_xp + winXP >= data->play.max_xp){
				data->play.current_xp = data->play.current_xp + winXP - data->play.max_xp;
				data->play.level ++;
				data->play.totalHP += 20;
				data->play.ad += 5;
				data->play.bp += 10;
				data->play.max_xp = data->play.max_xp * 1.5;
				cout << "Level up ! Level : " << data->play.level << endl;
			}else{
				data->play.current_xp += winXP;
			}
			run = 0;
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
				continue;
			}
			else if(input == 2){
				location[0] = 1;
				cout << "Returning to village ... " << endl;
				sleep(1);
				run = 0;
			}
		}
		else if(win == 0){
			sleep(2);
			location[0] = 1;
			run = 0;
		}
		else if(win == 3){
			location[0] = 10;
			run = 0;
		}
	}//end of while (run) loop
}
