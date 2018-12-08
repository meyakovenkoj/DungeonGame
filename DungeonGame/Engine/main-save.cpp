//
//  main.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "sf-player.hpp"
//#include "sf-map.h"
#include "view.h"
#include "map.hpp"
#include "menu.hpp"

using namespace sf;

int main()
{
	//int tempX = 0;
	//int tempY = 0;
	//float distance = 0;
	
	
	
	float CurrentFrame = 0;
	
	Clock clock;
	
	RenderWindow window(VideoMode(1368, 788), "Lesson 5.");
	
	view.reset(FloatRect(0,0,1368,788));
	
	Player p("hero.png", 250, 250, 96.0, 96.0);
	Map map;
	try{
		map.setMap("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/level.lvl");
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		return -1;
	}
	
	Menu menu(view);
	
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/800;
		
		
		//text.setPosition(view.getCenter().x+125, view.getCenter().y-130);
		//s_quest.setPosition(view.getCenter().x+115, view.getCenter().y -130);
		
		//Vector2i pixelPos;
		//Vector2f pos;
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			
			/*if(event.type == Event::MouseButtonPressed)
				if(event.key.code == Mouse::Left){
					pixelPos = Mouse::getPosition(window);
					pos = window.mapPixelToCoords(pixelPos);
					if(p.sprite.getGlobalBounds().contains(pos.x, pos.y)){
						p.sprite.setColor(Color::Green);
						p.isSelect = true;
					}
				}*/
			
			if(event.type == Event::KeyPressed)
				if(event.key.code == Keyboard::Tab){
					menu.getInfo(p);
				}
			
			/*if(p.isSelect)
				if(event.type == Event::MouseButtonPressed)
					if(event.key.code == Mouse::Right){
						p.isMove = true;
						p.isSelect = false;
						p.sprite.setColor(Color::White);
						pixelPos = Mouse::getPosition(window);
						pos = window.mapPixelToCoords(pixelPos);
						tempX = pos.x;
						tempY = pos.y;
						float dX = pos.x-p.getplayercoordinateX();//вектор , колинеарный прямой, которая пересекает спрайт и курсор
						float dY = pos.y-p.getplayercoordinateY();//он же, координата y
						float rotation = (atan2(dY, dX)) * 180 / 3.14159265;//получаем угол в радианах и переводим его в градусы
						std::cout << rotation << "\n";//смотрим на градусы в консольке
						p.sprite.setRotation(rotation);
					}*/
		}
		
		/*if(p.isMove){
			distance = sqrt((tempX - p.getplayercoordinateX())*(tempX - p.getplayercoordinateX()) + (tempY - p.getplayercoordinateY())*(tempY - p.getplayercoordinateY()));
			if(distance > 2.0){
				p.upX(0.1*time*(tempX - p.getplayercoordinateX())/distance);
				p.upY(0.1*time*(tempY - p.getplayercoordinateY())/distance);
			}else{
				p.isMove = false;
				std::cout << "im here\n";
			}
		}*/
		
		
		
		
		
		mouseview(window, time);
		
		
		p.update(time, map.getMap(), CurrentFrame);
		
		window.setView(view);
		
		window.clear(Color(128,106,89));
		
		map.drawMap(window);
		
		/*if(getCurrentMission(p.getplayercoordinateX()) == 0){
		for(int i = 0; i < HEIGHT_MAP; i++)
			for(int j = 0; j < WIDTH_MAP; j++){
				if(TileMap[i][j] == ' ') s_map.setTextureRect(IntRect(0,0,32,32));
				if(TileMap[i][j] == 's') s_map.setTextureRect(IntRect(32,0,32,32));
				if(TileMap[i][j] == '0') s_map.setTextureRect(IntRect(64,0,32,32));
				if(TileMap[i][j] == 'f') s_map.setTextureRect(IntRect(96,0,32,32));
				if(TileMap[i][j] == 'h') s_map.setTextureRect(IntRect(128,0,32,32));
				
				s_map.setPosition(j*32, i*32);
				
				window.draw(s_map);
			}
		}
		if(getCurrentMission(p.getplayercoordinateX()) >= 1){
			for(int i = 0; i < HEIGHT_MAP; i++)
				for(int j = 0; j < WIDTH_MAP; j++){
					if(TileMap[i][j] == ' ') s_map.setTextureRect(IntRect(64,0,32,32));
					if(TileMap[i][j] == 's') s_map.setTextureRect(IntRect(32,0,32,32));
					if(TileMap[i][j] == '0') s_map.setTextureRect(IntRect(0,0,32,32));
					if(TileMap[i][j] == 'f') s_map.setTextureRect(IntRect(96,0,32,32));
					if(TileMap[i][j] == 'h') s_map.setTextureRect(IntRect(128,0,32,32));
					
					s_map.setPosition(j*32, i*32);
					
					window.draw(s_map);
				}
		}*/
		//std::ostringstream playerScoreString;
		//playerScoreString << p.getScore();
		//text.setString("You have " + playerScoreString.str() + " stones");
		//text.setPosition(view.getCenter().x-100, view.getCenter().y-200);
		
		menu.draw(window);
		
		window.draw(p.sprite);
		window.display();
	}
	
	return 0;
}
