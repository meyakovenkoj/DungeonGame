//
//  undead.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef undead_hpp
#define undead_hpp

#include <stdio.h>
#include "creature.hpp"
#include "player.hpp"
#include "enemy.hpp"

class Undead: public Creature{
private:
	float aimX, aimY;
	int lvl;
	int hp;
public:
	Undead(int level);
	Undead(Enemy c);
	void searchAim();
	int getMove();
	virtual int takeDamage(int attack);
	void setAim(float _x, float _y);
};

#endif /* undead_hpp */
