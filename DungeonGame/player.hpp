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

class Player: public Creature{
private:
	int hp; //health
	unsigned int exp; //experience
	unsigned int lvl;
	float w, h, dx,dy, speed;
	int dir;
public:
	Player();
	Player( float X, float Y, float W, float H, const char * f);
	void takeObject();
	void useObject();
	virtual void move();
	int takeDamage(int attack);
	void addExperience(int _experience);
	Player& setDir(int d){dir = d; return *this;}
	//void update(float time, String TileMap[], float &CurrentFrame);
	float getX(){return x;}
	float getY(){return y;}
	//void checkCollisionWithMap(String TileMap[], float Dx, float Dy);
	int getHealth(){return health;}
	Player& upX(float dx){x += dx; return *this;}
	Player& upY(float dy){y += dy; return *this;}
	void upHealth(int h){health += h;}
	void upStr(int str){strength += str;}
	void upDef(int def){defence += def;}
	//void control(float time, float &CurrentFrame);
};

#endif /* player_hpp */
