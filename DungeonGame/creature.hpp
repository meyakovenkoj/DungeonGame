//
//  creature.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef creature_hpp
#define creature_hpp

#include <stdio.h>
#include <string>
#include <random>
#include <ctime>


class Creature{
protected:
	float x,y;
	int hpMax;
	int defence;
	int strength;
	bool alive;
	std::string name;
public:
	Creature(){}
	
	float getX() const {return x;}
	float getY() const {return y;}
	int getHpMax() const {return hpMax;}
	int getStr() const {return strength;}
	std::string getName() const {return name;}
	int getDef() const {return defence;}
	bool isAlive(){return alive;}
	
	
	void setPnt(float _x, float _y){x = _x; y = _y;}
	void setName(const char * _name){ name = _name;}
	void setHealth(int h){hpMax = h;}
	void setAlive(bool a){alive = a;}
	void setStr(int str){strength = str;}
	void setDef(int def){defence = def;}
	
	
	virtual int takeDamage(int attack) = 0;
	void update(float t);
	int attack();
	virtual ~Creature() = default;
};

#endif /* creature_hpp */
