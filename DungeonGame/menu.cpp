//
//  menu.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 03/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <stdio.h>
#include "menu.hpp"

void Menu::create(View view){

	quest_texture.loadFromFile("/Users/yakovenko/Documents/Infa/DungeonGame/DungeonGame/images/missionbg.jpg");
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0,0,340,510));
	s_quest.setScale(0.6f, 0.6f);
	
	font.loadFromFile("/Users/yakovenko/Documents/Infa/DungeonGame/DungeonGame/CyrilicOld.TTF");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setStyle(Text::Bold);
	text.setPosition(view.getCenter().x+125, view.getCenter().y-130);
	s_quest.setPosition(view.getCenter().x+115, view.getCenter().y -130);
}

Menu::Menu(View view){

	quest_texture.loadFromFile("/Users/yakovenko/Documents/Infa/DungeonGame/DungeonGame/images/missionbg.jpg");
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0,0,340,510));
	s_quest.setScale(0.6f, 0.6f);
	
	font.loadFromFile("/Users/yakovenko/Documents/Infa/DungeonGame/DungeonGame/CyrilicOld.TTF");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setStyle(Text::Bold);
	text.setPosition(view.getCenter().x+125, view.getCenter().y-130);
	s_quest.setPosition(view.getCenter().x+115, view.getCenter().y -130);
}

void Menu::getInfo(Player& p, View view){
	if (showMissionText) {
		std::ostringstream EntityHealthString;
		EntityHealthString << p.getHp();
		std::ostringstream Expstr;
		Expstr << p.getExp();
		std::ostringstream Lvlstr;
		Lvlstr << p.getLvl();
		text.setString("Health: " + EntityHealthString.str() + "\n\n\nExperience: " + Expstr.str() + "\n\n\nLevel: " + Lvlstr.str());
		text.setPosition(view.getCenter().x+125, view.getCenter().y-130);
		s_quest.setPosition(view.getCenter().x+115, view.getCenter().y -130);
		showMissionText = false;
	}
}

void Menu::draw(RenderWindow &window){
	if (!showMissionText) {
		window.draw(s_quest);
		window.draw(text);
		
	}
}

