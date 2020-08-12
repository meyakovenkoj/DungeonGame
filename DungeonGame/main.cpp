//
//  main.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <iostream>
#include "engine.hpp"
#include "myarray.hpp"


using namespace sf;

int main()
{
	bool c = 1;
	do{
		Engine engine;
		engine.startscreen();
		c = engine.start();
	}while (c);
	return 0;
}

