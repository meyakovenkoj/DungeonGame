//
//  sf-entity.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 01/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "sf-entity.hpp"

Entity::Entity(std::string F, float X, float Y, float W, float H){
	dx = 0;
	dy = 0;
	dir = 0;
	File = F;
	w = W;
	h = H;
	texture.loadFromFile("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/images/" + File);
	sprite.setTexture(texture);
	x = X;
	y = Y;
	sprite.setTextureRect(IntRect(32,0,w,h));
	sprite.setPosition(x, y);
}

void Entity::create(std::string F, float X, float Y, float W, float H){
	dx = 0;
	dy = 0;
	dir = 0;
	File = F;
	w = W;
	h = H;
	texture.loadFromFile("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/images/" + File);
	sprite.setTexture(texture);
	x = X;
	y = Y;
	sprite.setTextureRect(IntRect(0,0,w,h));
	sprite.setPosition(x, y);
}

void Entity::update(Map & Map){
	int c = control();
	switch (dir) {
		case 0:
			dx = 32;
			dy = 0;
			break;
		case 1:
			dx = -32;
			dy = 0;
			break;
		case 2:
			dx = 0;
			dy = 32;
			break;
		case 3:
			dx = 0;
			dy = -32;
			break;
	}
	
	if (c&&canMove(Map)){
		x += dx;
		y += dy;
		sprite.setPosition(x, y);
	}
}

bool Entity::canMove(Map & Map){
	int i = (y+dy)/32;
	int j = (x+dx)/32;
	
	if(Map.TileMap[i][j] == '1')
		return false;
	else
		if(Map.TileMap[i][j] == '3'){
			//Map.TileMap[i+1][j] = '3';
			Map.TileMap[i][j] = '2';
			return true;
		}
	return true;
}

int Entity::control(){
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		setDir(1);
		sprite.setTextureRect(IntRect(0,0,w,h));
		return 1;
	}
	if(Keyboard::isKeyPressed(Keyboard::Right)){
		setDir(0);
		sprite.setTextureRect(IntRect(64,0,w,h));
		return 1;
	}
	if(Keyboard::isKeyPressed(Keyboard::Up)){
		setDir(3);
		sprite.setTextureRect(IntRect(32,0,w,h));
		return 1;
	}
	if(Keyboard::isKeyPressed(Keyboard::Down)){
		setDir(2);
		sprite.setTextureRect(IntRect(96,0,w,h));
		return 1;
	}
	return 0;
}
