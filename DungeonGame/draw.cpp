//
//  draw.cpp
//  DungeonGame
//
//  Created by Ivan Yakovenko on 17/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <stdio.h>
#include "engine.hpp"

void Engine::startscreen(){
	Texture menuBackground;
	//menuTexture1.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/images/111.png");
	Text menuText1, menuText2, menuText3;
//	Sound startS;
//	SoundBuffer startBuffer;
//	startBuffer.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/audio/start.wav");
//	startS.setBuffer(startBuffer);
//	startS.play();
	menuText1.setFont(font);
	menuText1.setCharacterSize(30);
	menuText1.setStyle(Text::Bold);
	menuText1.setString("NEW GAME");
	menuText1.setPosition(100, 30);
	menuText2.setFont(font);
	menuText2.setCharacterSize(30);
	menuText2.setStyle(Text::Bold);
	menuText2.setString("LOAD GAME");
	menuText2.setPosition(100, 90);
	menuText3.setFont(font);
	menuText3.setCharacterSize(30);
	menuText3.setStyle(Text::Bold);
	menuText3.setString("EXIT");
	menuText3.setPosition(100, 150);
	//menuTexture2.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/images/222.png");
	//menuTexture3.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/images/333.png");
	//aboutTexture.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/images/about.png");
	menuBackground.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/images/knight.png");
	//Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	Sprite menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	std::string str;
	//menu1.setPosition(100, 30);
	//menu2.setPosition(100, 90);
	//menu3.setPosition(100, 150);
	menuBg.setPosition(640, 0);
	menuBg.setScale(-0.9, 0.9);
	
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		if(window.waitEvent(event))
		{
			menuText1.setFillColor(Color::White);
			menuText2.setFillColor(Color::White);
			menuText3.setFillColor(Color::White);
			menuNum = 0;
			
			if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menuText1.setFillColor(Color::Red); menuNum = 1; }
			if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menuText2.setFillColor(Color::Red); menuNum = 2; }
			if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window)))  { menuText3.setFillColor(Color::Red); menuNum = 3; }
			
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				event.mouseButton.~MouseButtonEvent();
				switch (menuNum) {
					case 1:
						me.load("init.txt");
						isMenu = false;
						break;
					
					case 2:
						str.erase();
						window.clear(Color(128,106,89));
						loadScreen(str);
						me.load(str);
						str.erase();
						isMenu = false;
						break;
						
					case 3:
						window.close();
						isMenu = false;
						break;
						
					default:
						break;
				}
			}
		}
		window.clear(Color(128,106,89));
		
		window.draw(menuBg);
		window.draw(menuText1);
		window.draw(menuText2);
		window.draw(menuText3);
		
		window.display();
	}
}

void Engine::loadScreen(std::string & str){
	Vector2f origin = {(window.getView().getCenter().x-window.getSize().x/2), (window.getView().getCenter().y-window.getSize().y/2)};
	Text save1, save2, save3, save4;
	save1.setFont(font);
	save1.setCharacterSize(30);
	save1.setStyle(Text::Bold);
	save1.setString("SLOT 1");
	save1.setPosition(origin.x + 100, origin.y + 30);
	save2.setFont(font);
	save2.setCharacterSize(30);
	save2.setStyle(Text::Bold);
	save2.setString("SLOT 2");
	save2.setPosition(origin.x + 100, origin.y + 90);
	save3.setFont(font);
	save3.setCharacterSize(30);
	save3.setStyle(Text::Bold);
	save3.setString("SLOT 3");
	save3.setPosition(origin.x + 100, origin.y + 150);
	save4.setFont(font);
	save4.setCharacterSize(30);
	save4.setStyle(Text::Bold);
	save4.setString("SLOT 4");
	save4.setPosition(origin.x + 100, origin.y + 210);
	bool isLoad = 1;
	str = "init.txt";
	window.clear(Color(128,106,89));
	
	//////////////////////////////МЕНЮ///////////////////
	while (isLoad)
	{
		if(window.waitEvent(event))
		{
			save1.setFillColor(Color::White);
			save2.setFillColor(Color::White);
			save3.setFillColor(Color::White);
			save4.setFillColor(Color::White);
			window.clear(Color(128,106,89));
			
			if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { save1.setFillColor(Color::Red); str = "save1.txt"; }
			if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { save2.setFillColor(Color::Red); str = "save2.txt"; }
			if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { save3.setFillColor(Color::Red); str = "save3.txt"; }
			if (IntRect(100, 210, 300, 50).contains(Mouse::getPosition(window))) { save4.setFillColor(Color::Red); str = "save4.txt"; }
			
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				isLoad = false;
			}
		}
		//save1.setPosition(window.getView().getCenter().x-window.getSize().x/2, window.getView().getCenter().y-window.getSize().y/2);
		//view.setCenter(window.getView().getCenter());
		window.draw(save1);
		window.draw(save2);
		window.draw(save3);
		window.draw(save4);
		
		window.display();
	}
}

//void Engine::getText(std::string & str){
//	Text text("", font, 50);
//	text.setFillColor(Color::White);
//	text.setStyle(Text::Bold);
//	text.setPosition(100, 150);
//
//	while(event.type != Event::Closed){
//	// в event цикле...
//	if (event.type == Event::TextEntered)
//	{
//		// отсекаем не ASCII символы
//		if (event.text.unicode < 128)
//		{
//			str += static_cast<char>(event.text.unicode);
//			text.setString(str);
//		}
//	}
//
//
//	window.draw(text);
//}
//}
