//
//  sf-entity.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 01/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef sf_entity_hpp
#define sf_entity_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "../core/map.hpp"

using namespace sf;

class Entity
{
protected:
	float x, y, dx, dy;
	int w, h;
	int dir;
	std::string File;
	Texture texture;
	Sprite sprite;

public:
	Entity(){};
	Entity(std::string F, float X, float Y, float W, float H);
	void create(std::string F, float X, float Y, float W, float H);
	void update(Map &Map);
	float getX() { return x; }
	float getY() { return y; }

	void setDir(int d) { dir = d; }
	void setX(int _x) { x = _x; }
	void setY(int _y) { y = _y; }
	Texture &getTexture() { return texture; }
	Sprite &getSprite() { return sprite; }
	void control(int c, Map &Map);
	bool canMove(Map &Map);
};

#endif /* sf_entity_hpp */
