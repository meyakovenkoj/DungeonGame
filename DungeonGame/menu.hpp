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
#include "sf-entity.hpp"


class Menu{
private:
	Sprite s_quest;
	bool showMissionText = true;
	Text text;
public:
	Menu(View view);
	void getInfo(Entity& p);
	void draw(RenderWindow& window);
};


#endif /* menu_h */
