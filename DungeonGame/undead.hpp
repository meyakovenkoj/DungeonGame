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

class Undead: public Creature{
private:
	float aimX, aimY;
	int lvl;
public:
	Undead(int level);
	void searchAim();
	virtual void move();
	void attack();
	void setAim(float _x, float _y);
};

#endif /* undead_hpp */
