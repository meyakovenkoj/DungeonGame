//
//  creature.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "creature.hpp"




void Creature::update(float t){
	
}

int Creature::attack() {
	static std::default_random_engine randomEngine((unsigned int)time(NULL));
	std::uniform_int_distribution<int> attackRoll(1, strength);
	
	return attackRoll(randomEngine);
}
