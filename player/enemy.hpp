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
#include "../core/map.hpp"

class Enemy : public Creature
{
private:
	int hp;
	int lvl;
	int exp;
	int dirX, dirY;
	float aimX, aimY;

public:
	Enemy(int level);
	Enemy(Map &map);
	Enemy(const Enemy &c); //clone
	int getHP() const { return hp; }
	int getExp() const { return exp; }
	int getLvl() const { return lvl; }
	int takeDamage(int attack);
	Enemy &operator=(const Enemy &);
	void setAim(float _x, float _y);
	int distAim();

	int getMove(int playerX, int playerY);
	~Enemy();
};

#endif /* enemy_hpp */
