//
//  player.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "player.hpp"


Player::Player(){
	dx = 0;
	dy = 0;
	speed = 0;
	dir = 0;
	alive = true;
	hpMax = 100;
	hp = hpMax;
	exp = 0;
	lvl = 1;
	defence = 5;
	
	sp[STRENGTH].name = "Strength";
	sp[STRENGTH].shortname = "STR";
	
	sp[MANA].name = "Mana";
	sp[MANA].shortname = "MN";
	
	sp[LOVKOST].name = "Lovkost'";
	sp[LOVKOST].shortname = "LVK";
	
	sp[NECRO].name = "Necromant";
	sp[NECRO].shortname = "NCR";
	
	sp[NONE].name = "None";
	sp[NONE].shortname = "NN";
	
	for(auto & element : sp){
		element.points = 5;
	}
	log << "Initialization\nDone!\n";
}


int Player::takeDamage(int attack) {
	attack -= defence;
	
	if(attack > 0) {
		hp -= attack;
		log << "Monster \nattacked\n you with " << attack << '\n';
		
		if(hp <= 0) {
			return 1;
		}
	}
	return 0;
	
}

void Player::addExperience(int _experience) {
	exp += _experience;
	
	while(exp > 50) {
		log << "Leveled up!\n";
		exp -= 50;
		strength += 10;
		sp[STRENGTH].points += 10;
		defence += 5;
		hpMax += 10;
		lvl++;
	}
}

//void Player::takeObject(){
//}
//
//void Player::useObject(){
//}

Player::Player(float X, float Y){
	dx = 0;
	dy = 0;
	speed = 0;
	dir = 0;
	alive = true;
	hpMax = 100;
	hp = hpMax;
	exp = 0;
	lvl = 1;
	defence = 5;
	
	x = X;
	y = Y;
	
	sp[STRENGTH].name = "Strength";
	sp[STRENGTH].shortname = "STR";
	
	sp[MANA].name = "Mana";
	sp[MANA].shortname = "MN";
	
	sp[LOVKOST].name = "Lovkost'";
	sp[LOVKOST].shortname = "LVK";
	
	sp[NECRO].name = "Necromant";
	sp[NECRO].shortname = "NCR";
	
	sp[NONE].name = "None";
	sp[NONE].shortname = "NN";
	
	for(auto & element : sp){
		element.points = 5;
	}
}

std::string Player::setSTR(){
	std::ostringstream EString;
	EString << "Health: " << getHp();
	EString << "\nExpernc: " << getExp();
	EString << "\nLevel: " << getLvl();
	EString << "\nDefence: " << getDef();
	for (auto & elem : sp) {
		EString << '\n' << elem.name << ": " << elem.points;
	}
	return EString.str();
}

