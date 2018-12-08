//
//  enemy.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "enemy.hpp"

Enemy::Enemy(Map &map, unsigned int c){
	hp = 10;
	exp = 4;
	aimX = 224;
	aimY = 224;
	angry = false;
	alive = true;
	health = 5;
	defence = 3;
	strength = 3;
	name = "monster";
	
	int randomElementX = 0;
	int randomElementY = 0;
	bool cont = true;
	//srand(c);
	while (cont) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);
		//char C = map.getchar(randomElementY , randomElementX);
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
		health -= attack;

		if(health <= 0) {
			return exp;
		}
	}
	return 0;
	
}


int Enemy::getMove(int playerX, int playerY)
{
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


void Enemy::move() {
	makeAngry();
	
	int curX = x/32;
	int curY = y/32;
	
	int setX = curX + dirX;
	int setY = curY + dirY;
	
	bool can = true;
	
	int b = 0;
	
	/*while(can){
		if(map.TileMap[setY][setX] == '2'){
			can = false;
			break;
		}
		switch (b) {
			case 0:
				setX--;
				setY--;
				b++;
				break;
			case 1:
				setY++;
				b++;
				break;
			case 2:
				setX++;
				setY++;
				b++;
				break;
			case 3:
				can = false;
				break;
			default:
				break;
		}

	}
	if(map.TileMap[setY][setX] == '2'){
	x = setX*32;
	y = setY*32;
	}*/
}

void Enemy::setAim(float _x, float _y){
	aimX = _x;
	aimY = _y;
}

void Enemy::makeAngry(){
	float l = sqrt((x-aimX)*(x-aimX)+(y-aimY)*(y-aimY));
	if(l < 10.0){
		angry = true;
		float dx = aimX - x;
		float dy = aimY - y;
		dx /= l;
		dy /= l;
		dirX = (int) dx;
		dirY = (int) dy;
	}
	else{
		angry = false;
		dirY = 0;
		dirX = 1;
	}
	
}
