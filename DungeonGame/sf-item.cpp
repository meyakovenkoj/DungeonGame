//
//  sf-item.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 04/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "sf-item.hpp"

sfItem::sfItem(std::string F){
	File = F;
	texture.loadFromFile("images/" + File);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,0,32,32));

}

void sfItem::create(std::string F){
	File = F;
	texture.loadFromFile("images/" + File);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,0,32,32));
}

void sfItem::randomMapGenerate(Map & map){
	int randomElementX = 0;
	int randomElementY = 0;
	srand((int)time(NULL));
	int countStone = 20;
	while(countStone > 0){
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);
		
		if(map.getchar(randomElementY, randomElementX) == '2'){
			map.getchar(randomElementY, randomElementX) = '3';
			countStone--;
		}
	}
}
