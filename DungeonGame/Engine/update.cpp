//
//  update.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <stdio.h>
#include "engine.hpp"

void Engine::update(float dtAsSeconds)
{
	m_Player.Creature::update(dtAsSeconds);
}
