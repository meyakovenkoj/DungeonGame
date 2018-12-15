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
	texture.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/images/" + File);
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
	texture.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/images/" + File);
	sprite.setTexture(texture);
	x = X;
	y = Y;
	sprite.setTextureRect(IntRect(0,0,w,h));
	sprite.setPosition(x, y);
}

void Entity::update(Map & Map){
	if (canMove(Map)){
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
	return true;
}

void Entity::control(int c, Map& Map){
	switch(c){
		case 0:
			setDir(0);
			dx = 32;
			dy = 0;
			sprite.setTextureRect(IntRect(64,0,w,h));
			break;
		case 1:
			setDir(1);
			dx = -32;
			dy = 0;
			sprite.setTextureRect(IntRect(0,0,w,h));
			break;
		case 2:
			setDir(2);
			dx = 0;
			dy = 32;
			sprite.setTextureRect(IntRect(96,0,w,h));
			break;
		case 3:
			setDir(3);
			dx = 0;
			dy = -32;
			sprite.setTextureRect(IntRect(32,0,w,h));
			break;
		default:
			break;
	}
	update(Map);
}
