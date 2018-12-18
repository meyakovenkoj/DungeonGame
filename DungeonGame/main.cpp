//
//  main.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

//#include "start-menu.h"
#include <iostream>
//#include "start-menu.h"
#include "engine.hpp"
#include "myarray.hpp"



using namespace sf;

int main()
{
	bool c = 1;
	do{
		Engine engine;
	
	//startmenu(engine.window);
		engine.startscreen();
		c = engine.start();
	}while (c);
	//engine.gameRunning();
	
	return 0;
}
//TODO std::array - DONE
//Movement for undead - ALMOST
//get items - DONE
//fix enemies - DONE
