//
//  engine.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

#include "../player/player.hpp"
#include "../graphics/sf-item.hpp"
#include "../graphics/sf-entity.hpp"
#include "../player/game-item.hpp"
#include "../player/enemy.hpp"
#include "menu.hpp"
#include "../player/undead.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
	Event event{};
	Menu menu;
	Player me;
	SoundBuffer shootBuffer;
	Sound shoot;
	SoundBuffer dieBuffer;
	Sound die;
	Font font;

	std::vector<Enemy> enemies;
	std::vector<Undead> undeads;
	std::vector<game *> items;

public:
	Engine();
	void input();
	bool start();
	void startscreen();
	void gameRunning();
	void loadScreen(std::string &str);
	void updateEnemies();
	void updateUndead();
	void drawEnemies();
	void drawUndead();
	void drawItem();
	void processItems();
	void processEnemyMove(int enemyIndex, int targetX, int targetY);
	void processUndeadMove(int undeadIndex, int targetX, int targetY);
	~Engine();
};
#endif /* engine_hpp */
