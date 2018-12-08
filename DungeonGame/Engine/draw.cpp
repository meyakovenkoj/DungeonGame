//
//  draw.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include <stdio.h>
#include "engine.hpp"

void Engine::draw()
{
	// Стираем предыдущий кадр
	m_Window.clear(Color::White);
	
	// Отрисовываем фон
	m_Window.draw(m_BackgroundSprite);
	//m_Window.draw(m_Player.getSprite());
	
	// Отображаем все, что нарисовали
	m_Window.display();
}
