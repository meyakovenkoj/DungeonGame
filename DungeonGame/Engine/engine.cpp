//
//  engine.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "engine.hpp"

Engine::Engine()
{
	window.create(VideoMode(640, 480), "Dungeon");
	
	view.reset(FloatRect(0,0,640,480));
	it.create("walls.png");
	p.create("player2.png", 224, 224, 32, 32);
	undead.create("monster.png",0, 0, 32, 32);
	map.create("map.tmx");
	enemy.create("monster.png", 224, 256, 32, 32);
	menu.create(view);
	it.randomMapGenerate(map);
	
	unsigned int c = (unsigned int)time(0);
	
	for(int i = 0; i < 100; i++){
		Enemy buf(map, c);
		enemies.push_back(buf);
	}
}

void Engine::start()
{
	while (window.isOpen())
	{
		if(window.waitEvent(event))
		//while (window.waitEvent(event))
		{
			switch (event.type)
			{
					
				case sf::Event::Closed:
					window.close();
					break;
					
					
				case sf::Event::KeyPressed:
					//menu.unshow();
					input();
					//p.update(map);
					me.setPnt(p.getSprite().getPosition().x, p.getSprite().getPosition().y);
					updateEnemies();
					break;
					
					
				default:
					break;
			}
			
			//break;
		}
		
		if(me.getHp() <= 0){
			Text dead;
			Font font;
			font.loadFromFile("/Users/yakovenko/Documents/Infa/DungeonGame/DungeonGame/CyrilicOld.TTF");
			dead.setFont(font);
			dead.setCharacterSize(30);
			dead.setFillColor(Color::Red);
			dead.setStyle(Text::Bold);
			dead.setString("\tYOU'RE DEAD\n\nPRESS ESC TO OUT");
			dead.setPosition(view.getCenter().x - 150, view.getCenter().y-50);
			window.draw(dead);
			window.display();
			while (window.waitEvent(event))
			{
				if(event.type == Event::Closed)
				   window.close();
				
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
				}
				
			}
		}
					
		
		view.setCenter(p.getX(), p.getY());
		
		window.setView(view);
		
		window.clear(Color(128,106,89));
		
		map.drawMap(window, view);
		
		window.draw(p.getSprite());
		
		drawEnemies();
		
		drawUndead();
		
		menu.getInfo(me);
		
		menu.setPos(view);
		
		menu.draw(window);
		
		window.display();
	}
}

/*void Engine::updateEnemies(){
	for (auto & element : enemies) {
		element.setAim(me.getX(), me.getY());
		element.move(map);
	}
}*/

void Engine::updateEnemies() {
	int aiMove;
	int playerX = me.getX()/32;
	int playerY = me.getY()/32;
	int enemyX;
	int enemyY;
	
	
	for (int i = 0; i < enemies.size(); i++) {
		enemyX = enemies[i].getX()/32;
		enemyY = enemies[i].getY()/32;
		enemies[i].setAim(playerX*32, playerY*32);
		aiMove = enemies[i].getMove(playerX, playerY);
		
		switch (aiMove) {
			case 1: //Up
				processEnemyMove(i, enemyX, enemyY - 1);
				break;
			case 2: //Down
				processEnemyMove(i, enemyX, enemyY + 1);
				break;
			case 0: //Left
				processEnemyMove(i, enemyX - 1, enemyY);
				break;
			case 3: //Right
				processEnemyMove(i, enemyX + 1, enemyY);
				break;
		}
	}
}


void Engine::processEnemyMove(int enemyIndex, int targetX, int targetY)
{
	char moveTile = map.getchar(targetY, targetX);
	
	if((targetX == p.getX()/32)&&(targetY == p.getY()/32))
		return;
	
	switch (moveTile) {
		case '2':
			for (int i = 0; i < enemies.size(); i++) {
				if((i != enemyIndex)&&(targetX == enemies[i].getX()/32)&&(targetY == enemies[i].getY()/32))
					return;
			}
			enemies[enemyIndex].setPnt(targetX*32, targetY*32);
			break;
		case '1':
			break;
			// something TODO
		default:
			break;
	}
	
}

void Engine::drawEnemies(){
	for (auto & element : enemies) {
		enemy.getSprite().setPosition(element.getX(), element.getY());
		window.draw(enemy.getSprite());
	}
}

void Engine::drawUndead(){
	for (auto & element : undeads) {
		undead.getSprite().setPosition(element.getX(), element.getY());
		window.draw(undead.getSprite());
	}
}
