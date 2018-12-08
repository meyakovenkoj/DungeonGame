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
}

void Weapon::makeEffect(Player &player){
	player.upStr(effect);
}

void Potion::makeEffect(Player &player){
	player.upHealth(effect);
}

