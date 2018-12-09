//
//  player.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "player.hpp"


Player::Player(){
	dx = 0;
	dy = 0;
	speed = 0;
	dir = 0;
	//setName(_File);
	alive = true;
	hpMax = 100;
	hp = hpMax;
	exp = 0;
	lvl = 1;
}

/*void Player::move(){
	
}*/


int Player::takeDamage(int attack) {
	attack -= defence;
	
	if(attack > 0) {
		hp -= attack;
		
		if(hp <= 0) {
			return 1;
		}
	}
	return 0;
	
}

void Player::addExperience(int _experience) {
	exp += _experience;
	
	while(exp > 50) {
		//printf("Leveled up!\n");
		exp -= 50;
		strength += 10;
		defence += 5;
		hpMax += 10;
		lvl++;
	}
}


void Player::takeObject(){
	
}

void Player::useObject(){
	
}

Player::Player(float X, float Y){
	dx = 0;
	dy = 0;
	speed = 0;
	dir = 0;
	//setName(_File);
	alive = true;
	hpMax = 100;
	hp = hpMax;
	exp = 0;
	lvl = 1;
	
	x = X;
	y = Y;
}

