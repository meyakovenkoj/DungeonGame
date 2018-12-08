//
//  player.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "player.hpp"


Player::Player(){
	
}

void Player::move(){
	
}


int Player::takeDamage(int attack) {
	attack -= defence;
	
	if(attack > 0) {
		health -= attack;
		
		if(health <= 0) {
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
		health += 10;
		lvl++;
	}
}


void Player::takeObject(){
	
}

void Player::useObject(){
	
}

Player::Player(float X, float Y, float W, float H, const char * _File){
	dx = 0;
	dy = 0;
	speed = 0;
	dir = 0;
	w = W;
	h = H;
	setName(_File);
	alive = true;
	health = 100;
	hp = health;
	exp = 0;
	lvl = 1;
	
	x = X;
	y = Y;
}

/*void Player::update(float time, String TileMap[], float &CurrentFrame){
	control(time, CurrentFrame);
	switch (dir) {
		case 0:
			dx = speed;
			dy = 0;
			break;
		case 1:
			dx = -speed;
			dy = 0;
			break;
		case 2:
			dx = 0;
			dy = speed;
			break;
		case 3:
			dx = 0;
			dy = -speed;
			break;
	}
	
	x += dx*time;
	checkCollisionWithMap(TileMap, dx, 0);
	y += dy*time;
	checkCollisionWithMap(TileMap, 0, dy);
	sprite.setPosition(x, y);
	if(health <= 0){
		alive = false;
		speed = 0;
	}
}*/

/*void Player::checkCollisionWithMap(String TileMap[], float Dx, float Dy){
	for(int i = y/32; i < (y+h)/32;i++)
		for(int j = x/32; j < (x+w)/32; j++){
			if (TileMap[i][j] == '0'){
				if(dy>0){
					y = i*32 - h;
					dy = 0;
				}
				if(dy<0){
					y = i*32 + 32;
					dy = 0;
				}
				if(dx>0){
					x = j*32 - w;
					dx = 0;
				}
				if(dx<0){
					x = j*32 + 32;
					dx = 0;
				}
			}
			if(TileMap[i][j] == 's'){
				exp++;
				TileMap[i][j] = ' ';
			}
			if(TileMap[i][j] == 'f'){
				health -= 40;
				TileMap[i][j] = ' ';
			}
			if(TileMap[i][j] == 'h'){
				health += 20;
				TileMap[i][j] = ' ';
			}
		}
}*/


/*void Player::control(float time, float &CurrentFrame){
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		setDir(1);
		setSpeed(0.1);
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(96 * (int)CurrentFrame+6,136,89,55));
		//getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
	}
	if(Keyboard::isKeyPressed(Keyboard::Right)){
		setDir(0);
		setSpeed(0.1);
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(96 * (int)CurrentFrame+6,231,89,55));
		//getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
	}
	if(Keyboard::isKeyPressed(Keyboard::Up)){
		setDir(3);
		setSpeed(0.1);
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(96 * (int)CurrentFrame+27,305,39,89));
		//getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
	}
	if(Keyboard::isKeyPressed(Keyboard::Down)){
		setDir(2);
		setSpeed(0.1);
		CurrentFrame += 0.005*time;
		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(IntRect(96 * (int)CurrentFrame+27,6,39,89));
		//getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
	}
}*/
