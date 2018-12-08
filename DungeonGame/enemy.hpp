//
//  enemy.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef enemy_hpp
#define enemy_hpp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "creature.hpp"
#include "map.hpp"

class Enemy: public Creature{
private:
	int hp;
	int exp;
	int dirX, dirY;
	float aimX, aimY;
	bool angry;
public:
	Enemy(Map &map, unsigned int c);
	int getHP(){return hp;}
	int getExp(){return exp;}
	bool isAngry(){return angry;}
	
	int takeDamage(int attack);
	void makeAngry();
	void setAim(float _x, float _y);

	virtual void move();

	int getMove(int playerX, int playerY);
};

#endif /* enemy_hpp */
