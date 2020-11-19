#ifndef COMMON_H
#define COMMON_H
#include <string>
struct Player{
	int level, max_xp, current_xp, totalHP, hp, ad, bp, cp, money;
};

struct Game_data{
	string username;
	Player play;
};

struct New_player{
	int level = 1;
	int max_xp = level*50;
	int current_xp = 0;
	int totalHP = 50, hp = 50, ad = 10, bp = 5;
	int cp = 0;
	int money = 100;
};

struct Usernames{
	int num = 0;
	string *user = new string [num];
};

#endif
