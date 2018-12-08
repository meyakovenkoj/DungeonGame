//
//  view.h
//  classes-for-game
//
//  Created by Ivan Yakovenko on 01/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef view_h
#define view_h
#define NON_USED
#include <SFML/Graphics.hpp>
using namespace sf;

//View view;

/*void setview(float x, float y){
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края
	Vector2f p = view.getSize();
	if (x < p.x/4) tempX = x/4;//убираем из вида левую сторону
	if (y < p.y/4) tempY = y/4;//верхнюю сторону
	if (y > p.y*3/4) tempY = y*3/4;//нижнюю сторону
	if (x > p.x*3/4) tempX = x*3/4;
	
	view.setCenter(tempX, tempY);
}*/
/*
void mouseview(RenderWindow& window, float time){
	Vector2i localPosition = Mouse::getPosition(window);

	if((localPosition.x < 3)&&(localPosition.x > -5)) { view.move(-0.2*time,0);}
	if((localPosition.y < 3)&&(localPosition.y > -5)) { view.move(0,-0.2*time);}
	if((localPosition.x > window.getSize().x - 3)&&(localPosition.x < window.getSize().x+5)) { view.move(0.2*time,0);}
	if((localPosition.y > window.getSize().y - 3)&&(localPosition.y < window.getSize().y+5)) { view.move(0,0.2*time);}
	

}*/

/*void viewmap(float time){
	if(Keyboard::isKeyPressed(Keyboard::D)){
		view.move(0.1*time, 0);
	}
	if(Keyboard::isKeyPressed(Keyboard::S)){
		view.move(0, 0.1*time);
	}
	if(Keyboard::isKeyPressed(Keyboard::A)){
		view.move(-0.1*time, 0);
	}
	if(Keyboard::isKeyPressed(Keyboard::W)){
		view.move(0, -0.1*time);
	}

}

void changeview(){
	
	
	if (Keyboard::isKeyPressed(Keyboard::U)) {
		view.zoom(1.0100f); //масштабируем, уменьшение
		//view.zoom(1.0006f); //тоже самое помедленнее соответственно
	}
	
	if (Keyboard::isKeyPressed(Keyboard::R)) {
		//view.setRotation(90);//сразу же задает поворот камере
		view.rotate(1);//постепенно поворачивает камеру (отрицательное значение - в обратную сторону)
	}
	
	
	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);//устанавливает размер камеры (наш исходный)
	}
	
	if (Keyboard::isKeyPressed(Keyboard::P)) {
		view.setSize(540, 380);//например другой размер
	}
	
	
	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));//таким образом делается раздельный экран для игры на двоих. нужно только создать ещё один объект View и привязывать к нему координаты игрока 2.
	}
	
	
	
}*/

#endif /* view_h */
