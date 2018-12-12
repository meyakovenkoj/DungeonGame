//
//  map.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "map.hpp"

Map::Map(std::string filename){
	setMap("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/" + filename);
}

void Map::create(std::string filename){
	setMap("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/" + filename);
}

void Map::setMap(std::string filename){
	std::ifstream f(filename);
	if (!f.is_open()){ 
		std::cout << "Файл не может быть открыт!\n";
		throw std::invalid_argument("can't open map");
	}
	else
	{
		std::string buf;

		while (std::getline(f, buf)) {
			TileMap.push_back(buf);
		}
		map.loadFromFile("/Users/yakovenko/Documents/Infa/classes-for-game/classes-for-game/images/walls.png");
		s_map.setTexture(map);

	}
	
}

void Map::drawMap(RenderWindow& window, View &view){
	Vector2f st = view.getCenter();
	Vector2u win = window.getSize();
	
	int c, v,n,m;
	
	if((st.y - win.y/2) > 0)
		c = (int)((st.y - win.y/2)/32);
	else c = 0;
	
	if((st.x - win.x/2) > 0)
		v = (int)((st.x - win.x/2)/32);
	else v = 0;
	
	if((st.y + win.y/2) < HEIGHT_MAP)
		n = (int)((st.y + win.y/2)/32) + 1;
	else n = HEIGHT_MAP;
	
	if((st.x + win.x/2) < WIDTH_MAP)
		m = (int)((st.x + win.x/2)/32) + 1;
	else m = WIDTH_MAP;
	
	for(int i = c; i < n; i++)
		for(int j = v; j < m; j++){
			if(TileMap[i][j] == '1') s_map.setTextureRect(IntRect(0,32,32,32));
			if(TileMap[i][j] == '2') s_map.setTextureRect(IntRect(32,0,32,32));
			if(TileMap[i][j] == '3') s_map.setTextureRect(IntRect(0,0,32,32));
			s_map.setPosition(j*32, i*32);
			
			window.draw(s_map);
		}
}

char& Map::getchar(int i, int j){
	return TileMap[i][j];
}
