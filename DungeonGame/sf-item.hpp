//
//  sf-item.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 04/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef sf_item_hpp
#define sf_item_hpp

#include <stdio.h>
#include "player.hpp"
#include "map.hpp"

using namespace sf;

class Item{
private:
	std::string File;
	Texture texture;
	Sprite sprite;
public:
	Item(){};
	Item(std::string F);
	void create(std::string F);
	void randomMapGenerate(Map &map);
};

#endif /* sf_item_hpp */
