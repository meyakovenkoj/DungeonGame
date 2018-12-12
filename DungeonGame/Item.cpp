//
//  Item.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 03/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "Item.hpp"

void Armor::makeEffect(Player &player){
	player.upDef(effect);
	player.getLog().str("");
	player.getLog().clear();
	player.getLog() << "Upped \ndefence\nwith " << effect << '\n';
}

void Weapon::makeEffect(Player &player){
	player.upStr(effect);
	player.getLog().str("");
	player.getLog().clear();
	player.getLog() << "Upped \nstrength\nwith " << effect << '\n';
}

void Potion::makeEffect(Player &player){
	player.upHp(effect);
	player.getLog().str("");
	player.getLog().clear();
	player.getLog() << "Upped \nhealth\nwith " << effect << '\n';
}

void Item::setCOORD(Map &map){
	int randomElementX = 0;
	int randomElementY = 0;
	//srand((int)time(NULL));
	int countStone = 1;
	while(countStone > 0){
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);
		
		if(map.getchar(randomElementY, randomElementX) == '2'){
			x = randomElementX*32;
			y = randomElementY*32;
			countStone--;
		}
	}
}

Armor::Armor(){
	is = 0;
	type = rand()%3;
	switch (type) {
		case 1:
			name = "head";
			break;
		case 2:
			name = "leg";
			break;
		case 0:
			name = "body";
			break;
		default:
			name = "body";
			break;
	}
	setEff(5);
}

Armor::~Armor()
{
	
}

Armor* Armor::clone()const
{
	return new Armor(*this);
}

Weapon::Weapon(){
	is = 1;
	coef = rand()%10+3;
	switch (coef) {
		case 4:
			name = "sword";
			break;
		case 8:
			name = "sheild";
			break;
		default:
			name = "saber";
			break;
	}
	setEff(5);
}

Weapon::~Weapon()
{
	
}

Weapon* Weapon::clone()const
{
	return new Weapon(*this);
}

Potion::Potion(){
	is = 2;
	type = rand()%3;
	switch (type) {
		case 1:
			name = "health+";
			break;
		case 2:
			name = "strength+";
			break;
		case 0:
			name = "smth+";
			break;
		default:
			name = "none+";
			break;
	}
	setEff(5);
}

Potion::~Potion()
{
	
}

Potion* Potion::clone()const
{
	return new Potion(*this);
}
