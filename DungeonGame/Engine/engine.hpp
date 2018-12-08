//
//  engine.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

#include "player.hpp"
#include "sf-item.hpp"
#include "sf-entity.hpp"
#include "enemy.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Engine
{
private:
	
	View view;
	RenderWindow window;
	Item it;
	Entity p;
	Entity enemy;
	Map map;
	Event event;
	
	Player me;
	
	std::vector<Enemy> enemies;
	
public:

	Engine();
	
	void start();
	void updateEnemies();
	void drawEnemies();
	void processEnemyMove(int enemyIndex, int targetX, int targetY);
};
#endif /* engine_hpp */
