//
//  undead.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "undead.hpp"

Undead::Undead(int level)
{
}

Undead::Undead(Enemy c)
{
	defence = c.getDef();
	strength = c.getStr();
	name = "undead";
	x = c.getX();
	y = c.getY();
	setAlive(true);
	lvl = c.getLvl();
}

void Undead::searchAim()
{
}

int Undead::getMove()
{
	int dx = x / 32 - aimX;
	int dy = y / 32 - aimY;
	int adx = abs(dx);
	int ady = abs(dy);

	//along x
	if (adx > ady)
	{
		if (dx > 0)
		{
			return 0; //left
		}
		else
		{
			return 3; //right
		}
	} //along y
	else
	{
		if (dy > 0)
		{
			return 1; //up
		}
		else
		{
			return 2; //down
		}
	}
}

void addExp(Player &p, int exp)
{
	p.addExperience(exp);
}

int Undead::takeDamage(int attack)
{
	attack -= defence;

	if (attack > 0)
	{
		hp -= attack;

		if (hp <= 0)
		{
			return 1;
		}
	}
	return 0;
}

void Undead::setAim(float _x, float _y)
{
	aimX = _x;
	aimY = _y;
}
