//
//  menu.h
//  classes-for-game
//
//  Created by Ivan Yakovenko on 03/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef menu_h
#define menu_h
#include <SFML/Graphics.hpp>
#include <sstream>
#include "../player/player.hpp"

using namespace sf;

class Menu
{
private:
	Sprite s_quest;
	bool showMissionText = true;
	Text text;
	Texture quest_texture;
	Font font;

public:
	Menu() {}
	Menu(View view);
	void create(View view);
	void getInfo(Player &p);
	void draw(RenderWindow &window);
	void setPos(View view);
};

#endif /* menu_h */
