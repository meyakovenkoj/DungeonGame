//
//  map.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace sf;

const int HEIGHT_MAP = 100;
const int WIDTH_MAP = 100;

class Map{
private:
	std::vector<std::string> TileMap;
	Texture map;
	Sprite s_map;

public:
	Map(){};
	Map(std::string filename);
	void create(std::string filename);
	friend class Enemy;
	friend class Entity;
	friend class Item;
	char getchar(int i, int j);
	void setMap(std::string filename);
	void drawMap(RenderWindow& window, View &view);
	//std::vector<std::string>& getMap(){ return TileMap;}//get one
};

#endif /* map_hpp */
