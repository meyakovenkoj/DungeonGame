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
	it.create("items1.png");
	p.create("player2.png", me.getX(), me.getY(), 32, 32);
	undead.create("undead.png",0, 0, 32, 32);

	
	font.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/CyrilicOld.TTF");
	
	map.create("map.tmx");
	enemy.create("monster.png", 224, 256, 32, 32);
	menu.create(view);
	
	
	shootBuffer.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/audio/quietShaker.ogg");
	shoot.setBuffer(shootBuffer);
	
	dieBuffer.loadFromFile("/Users/yakovenko/Documents/Infa/Programs_3_sem/DungeonGame/DungeonGame/audio/death.ogg");
	die.setBuffer(dieBuffer);
	
	
	
	for(int i = 0; i < 100; i++){
		Enemy buf(map);
		enemies.push_back(buf);
	}
	for(int i = 0; i < 100; i++){
		Item* buf;
		int c = rand()%10;
		switch (c) {
			case 1:
			case 2:
			case 3:
				buf = new Armor();
				break;
			case 4:
			case 5:
			case 6:
				buf = new Weapon();
				break;
			case 7:
			case 8:
			case 9:
				buf = new Potion();
				break;
			default:
				buf = new Potion();
				break;
		}
		buf->setCOORD(map);
		items.push_back(buf);
	}
	
}



bool Engine::start()
{
	
	p.getSprite().setPosition(me.getX(), me.getY());
	p.setX(me.getX());
	p.setY(me.getY());
	Vector2i pixelPos;
	Vector2f pos;
	bool select = false;
	
	while (window.isOpen())
	{
		view.setCenter(p.getX(), p.getY());
		
		window.setView(view);
		
		window.clear(Color(128,106,89));
		
		map.drawMap(window, view);
		
		drawEnemies();
		
		drawUndead();
		
		drawItem();
		
		window.draw(p.getSprite());
		
		menu.getInfo(me);
		
		menu.setPos(view);
		
		menu.draw(window);
		
		window.display();

		if(window.waitEvent(event))
		{
			switch (event.type)
			{
					
				case Event::Closed:
					window.close();
					break;
					
				case Event::MouseButtonPressed:
					if (event.key.code == Mouse::Left){
						pixelPos = Mouse::getPosition(window);
						pos = window.mapPixelToCoords(pixelPos);
							if (p.getSprite().getGlobalBounds().contains(pos.x, pos.y))
							{
								p.getSprite().setColor(Color::Green);
								select = true;
							}

					}
					if (select)
						if (event.key.code == Mouse::Right){
							p.getSprite().setColor(Color::White);
							pixelPos = Mouse::getPosition(window);
							pos = window.mapPixelToCoords(pixelPos);
							
							for(auto & elem : undeads)
								elem.setAim(pos.x, pos.y);
						}
					break;
					
					
				case sf::Event::KeyPressed:
					input();
					me.setPnt(p.getSprite().getPosition().x, p.getSprite().getPosition().y);
					updateEnemies();
					updateUndead();
					break;
					
				
					
				default:
					break;
			}
			
		}
		
		if(me.getHp() <= 0){
			Text dead;
			dead.setFont(font);
			dead.setCharacterSize(30);
			dead.setFillColor(Color::Red);
			dead.setStyle(Text::Bold);
			dead.setString("\tYOU'RE DEAD\n\nPRESS ESC TO OUT\n\nPRESS TAB TO\nRESTART");
			dead.setPosition(view.getCenter().x - 150, view.getCenter().y-50);
			window.draw(dead);
			window.display();
			die.play();
			while (window.waitEvent(event))
			{
				if(event.type == Event::Closed){
					window.close();
					return 0;
				}
				
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
					return 0;
				}
				if (Keyboard::isKeyPressed(Keyboard::Tab))
				{
					return 1;
				}
				
			}
		}
		
		

	}
	return 0;
}

void Engine::gameRunning(){
	if (start()) { gameRunning(); }
}

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

void Engine::updateUndead() {
	int aiMove;
	int undeadX;
	int undeadY;
	
	
	for (int i = 0; i < undeads.size(); i++) {
		undeadX = undeads[i].getX()/32;
		undeadY = undeads[i].getY()/32;
		aiMove = undeads[i].getMove();
		
		switch (aiMove) {
			case 1: //Up
				processUndeadMove(i, undeadX, undeadY - 1);
				break;
			case 2: //Down
				processUndeadMove(i, undeadX, undeadY + 1);
				break;
			case 0: //Left
				processUndeadMove(i, undeadX - 1, undeadY);
				break;
			case 3: //Right
				processUndeadMove(i, undeadX + 1, undeadY);
				break;
		}
	}
}


void Engine::processUndeadMove(int undeadIndex, int targetX, int targetY)
{
	char moveTile = map.getchar(targetY, targetX);

	
	switch (moveTile) {
		case '2':
			for (int i = 0; i < undeads.size(); i++) {
				if((i != undeadIndex)&&(targetX == undeads[i].getX()/32)&&(targetY == undeads[i].getY()/32))
					return;
			}
			undeads[undeadIndex].setPnt(targetX*32, targetY*32);
			break;
		case '1':
			break;
			// something TODO
		default:
			break;
	}
	
}

void Engine::drawUndead(){
	for (auto & element : undeads) {
		undead.getSprite().setPosition(element.getX(), element.getY());
		window.draw(undead.getSprite());
	}
}

void Engine::drawItem(){
	for (auto & element : items) {
		it.getSprite().setPosition(element->getX(), element->getY());
		switch (element->what()) {
			case 0:
				it.getSprite().setTextureRect(IntRect(96,0,32,32));
				break;
			case 1:
				it.getSprite().setTextureRect(IntRect(32,0,32,32));
				break;
			case 2:
				it.getSprite().setTextureRect(IntRect(128,0,32,32));
				break;
			default:
				break;
		}
		window.draw(it.getSprite());
	}
}

void Engine::processItems(){
	int playerX = me.getX()/32;
	int playerY = me.getY()/32;
	for (int i = 0; i < items.size(); i++) {
		if((playerX == items[i]->getX()/32)&&(playerY == items[i]->getY()/32)){
			items[i]->makeEffect(me);
			items[i] = items.back();
			items.pop_back();
			i--;
		}
	}
}
