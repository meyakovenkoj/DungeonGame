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
		window.close();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		p.control(1, map);
	}
	if(Keyboard::isKeyPressed(Keyboard::Right)){
		p.control(0, map);
	}
	if(Keyboard::isKeyPressed(Keyboard::Up)){
		p.control(3, map);
	}
	if(Keyboard::isKeyPressed(Keyboard::Down)){
		p.control(2, map);
	}
	
	if(Keyboard::isKeyPressed(Keyboard::LShift)){
		
		processItems();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Space)){
		for (int i = 0; i < enemies.size(); i++) {
			//std::cout << enemies[i].distAim()/32 << std::endl;
			if(enemies[i].distAim()/32 <= 1){

				shoot.play();
				me.getLog().str("");
				me.getLog().clear();
				me.takeDamage(enemies[i].attack());
				int c = me.attack();
				me.getLog() << "You try to hit\nmonster \nwith " << c <<'\n';
				int exp = enemies[i].takeDamage(c);
				me.addExperience(exp);
				me.getLog() << "You earned " << exp << "\nof experience\n";
				if(!enemies[i].isAlive()){
					Undead buf(enemies[i]);
					undeads.push_back(buf);
					enemies[i] = enemies.back();
					enemies.pop_back();
					i--;
					//std::cout << "killed\n";
				}
			}
		}
		//std::cout << "----------------\n";
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Tab)){
		menu.getInfo(me);
	}
}
