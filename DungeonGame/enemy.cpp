//
//  enemy.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "enemy.hpp"

Enemy::Enemy(int level)
{
	this->lvl = level;
	this->hpMax = rand()% (level * 10) + (level * 2);
	this->hp = this->hpMax;
	this->strength = this->lvl * 1;
	this->defence = rand() % lvl*5 + 1;
}

Enemy::Enemy(const Enemy &c){
	lvl = c.getLvl();
	hpMax = c.getHpMax();
	hp = c.getHP();
	strength = c.getStr();
	defence = c.getDef();
	exp = c.getExp();
	aimX = c.aimX;
	aimY = c.aimY;
	alive = true;
	x = c.getX();
	y = c.getY();
}

Enemy &Enemy::operator = (const Enemy &c){//test done
	if(this != &c){
		lvl = c.getLvl();
		hpMax = c.getHpMax();
		hp = c.getHP();
		strength = c.getStr();
		defence = c.getDef();
		exp = c.getExp();
		aimX = c.aimX;
		aimY = c.aimY;
		alive = true;
		x = c.getX();
		y = c.getY();
	}
	return *this;
}

Enemy::Enemy(Map &map){
	int level = rand() % 10 + 1;
	this->lvl = level;
	this->hpMax = (rand() % (level * 10)) + (level * 2);
	this->hp = this->hpMax;
	this->strength = this->lvl * 1;
	defence = rand() % 5 + 1;
	exp = lvl+1;
	aimX = 224;
	aimY = 224;
	alive = true;
	name = "monster";
	
	int randomElementX = 0;
	int randomElementY = 0;
	bool cont = true;
	while (cont) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);
		if(map.getchar(randomElementY , randomElementX) != '1'){
			x = randomElementX*32;
			y = randomElementY*32;
			cont = false;
		}
	}
	
}

int Enemy::takeDamage(int attack) {
	attack -= defence;

	if(attack > 0) {
		hp -= attack;

		if(hp <= 0) {
			alive = false;
			return exp;
		}
	}
	return 0;
	
}


int Enemy::getMove(int playerX, int playerY)
{
	if(!hp)
		return -1;
	static std::default_random_engine randEngine((unsigned int)time(NULL));
	std::uniform_int_distribution<int> moveRoll(0, 6);
	int distance;
	int dx = x/32 - playerX;
	int dy = y/32 - playerY;
	int adx = abs(dx);
	int ady = abs(dy);
	
	
	distance = adx + ady;
	
	if (distance <= 10) {
		//along x
		if (adx > ady) {
			if (dx > 0) {
				return 0;//left
			}
			else {
				return 3;//right
			}
		}//along y
		else {
			if (dy > 0) {
				return 1;//up
			}
			else {
				return 2;//down
			}
		}
		
	}
	int randomMove = moveRoll(randEngine);
	switch (randomMove) {
		case 0:
			return 0;
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 3;
		default:
			return -1;
	}
}



void Enemy::setAim(float _x, float _y){
	aimX = _x;
	aimY = _y;
}

int Enemy::distAim(){
	int _x = abs((int)(x-aimX));
	int _y = abs((int)(y-aimY));
	return _x + _y;
}
