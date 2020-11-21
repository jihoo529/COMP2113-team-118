#ifndef COMMON_H
#define COMMON_H
#include <string>
struct Player{
	int level, max_xp, current_xp, totalHP, hp, ad, bp, cp, money, nump;
	
};

struct Game_data{
	std::string username;
	Player play;
};

struct New_player{
	int level = 1;
	int max_xp = 50;
	int current_xp = 0;
	int totalHP = 50, hp = 50, ad = 10, bp = 10;
	int cp = 0;
	int money = 0;
	int nump = 3;
};

struct Usernames{
	int num = 0;
	std::string *user = new std::string [0];
};

#endif
