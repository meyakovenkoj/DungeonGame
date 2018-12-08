//
//  input.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <stdio.h>
#include "engine.hpp"

void Engine::input()
{
	// Обрабатываем нажатие Escape
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}
	
	// Обрабатываем нажатие клавиш движения
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_Player.move();
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_Player.move();
	}
	
}
