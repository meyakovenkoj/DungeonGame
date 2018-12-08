//
//  menu.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 03/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <stdio.h>
#include "menu.hpp"

Menu::Menu(View view){
	Texture quest_texture;
	quest_texture.loadFromFile("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/images/missionbg.jpg");
	s_quest.setTexture(quest_texture);
	s_quest.setTextureRect(IntRect(0,0,340,510));
	s_quest.setScale(0.6f, 0.6f);
	
	Font font;
	font.loadFromFile("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/CyrilicOld.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::Black);
	text.setStyle(Text::Bold);
	text.setPosition(view.getCenter().x+125, view.getCenter().y-130);
	s_quest.setPosition(view.getCenter().x+115, view.getCenter().y -130);
}

void Menu::getInfo(Entity& p){
	if (showMissionText) {
		//std::ostringstream EntityHealthString;
		//EntityHealthString << p.getHealth();
		//std::ostringstream EntityScoreString;
		//EntityScoreString << p.getScore();
		text.setString("Health: \n\n\nYou have \nstones");
		showMissionText = false;
	} else {
		text.setString("");
		showMissionText = true;
	}
}

void Menu::draw(RenderWindow &window){
	if (!showMissionText) {
		window.draw(s_quest);
		//window.draw(text);
		
	}
}

