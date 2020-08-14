//
//  main.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <iostream>
#include "core/engine.hpp"
#include <array>

using namespace sf;

int main()
{
	bool c = true;
    Engine engine;
    do
	{
        engine.startscreen();
		c = engine.start();
	} while (c);
	return 0;
}
