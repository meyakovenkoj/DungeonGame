//
//  engine.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

//

#include "player.hpp"
#include "sf-item.hpp"
#include "sf-entity.hpp"
#include "enemy.hpp"
#include "menu.hpp"
#include "undead.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Engine
{
private:
	
	View view;
	RenderWindow window;
	sfItem it;
	Entity p;
	Entity enemy;
	Entity undead;
	Map map;
	Event event;
	Menu menu;
	Player me;
	
	std::vector<Enemy> enemies;
	std::vector<Undead> undeads;
	
public:

	Engine();
	
	void input();
	void start();
	void updateEnemies();
	void drawEnemies();
	void drawUndead();
	void processEnemyMove(int enemyIndex, int targetX, int targetY);
};
#endif /* engine_hpp */
