//
//  Item.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 03/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "Item.hpp"

//void Armor::makeEffect(Player &player){
//	player.upDef(effect);
//}
//
//void Weapon::makeEffect(Player &player){
//	player.upStr(effect);
//}
//
//void Potion::makeEffect(Player &player){
//	player.upHealth(effect);
//}
Armor::~Armor()
{
	
}

Armor* Armor::clone()const
{
	return new Armor(*this);
}

Weapon::~Weapon()
{
	
}

Weapon* Weapon::clone()const
{
	return new Weapon(*this);
}

Potion::~Potion()
{
	
}

Potion* Potion::clone()const
{
	return new Potion(*this);
}
