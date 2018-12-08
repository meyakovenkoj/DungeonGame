//
//  sf-item.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 04/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "sf-item.hpp"

Item::Item(std::string F){
	File = F;
	texture.loadFromFile("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/images/" + File);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,0,32,32));

}

void Item::create(std::string F){
	File = F;
	texture.loadFromFile("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/images/" + File);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,0,32,32));
}

void Item::randomMapGenerate(Map & map){
	int randomElementX = 0;
	int randomElementY = 0;
	srand((int)time(NULL));
	int countStone = 20;
	while(countStone > 0){
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);
		
		if(map.TileMap[randomElementY][randomElementX] == '2'){
			map.TileMap[randomElementY][randomElementX] = '3';
			countStone--;
		}
	}
}
