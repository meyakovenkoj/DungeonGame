//
//  player.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>

//#include <vector>
#include "creature.hpp"
#include "Inventory.h"

class Player: public Creature{
private:
	int hp; //health
	unsigned int exp; //experience
	unsigned int lvl;
	float w, h, dx,dy, speed;
	int dir;
	Inventory inventory;
	Weapon weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;
public:
	Player();
	Player( float X, float Y);
	void takeObject();
	void useObject();
	int takeDamage(int attack);
	void addExperience(int _experience);
	Player& setDir(int d){dir = d; return *this;}
	float getX(){return x;}
	float getY(){return y;}
	int getHp(){return hp;}
	int getLvl(){return lvl;}
	int getExp(){return exp;}
	Player& upX(float dx){x += dx; return *this;}
	Player& upY(float dy){y += dy; return *this;}
	void upHp(int h){hp += h;}
	void upStr(int str){strength += str;}
	void upDef(int def){defence += def;}
};

#endif /* player_hpp */
