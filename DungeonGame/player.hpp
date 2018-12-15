//
//  player.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 30/11/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef player_hpp
#define player_hpp


#include <string>
#include <sstream>
#include "creature.hpp"
#include "myarray.hpp"

/*!
 \brief Структура, объявляющая объект таблицы характеристик
 
Данная структура хранит пункты характеристики, полное и краткое её название.
 */
struct Spec {
	int points;
	std::string name;
	std::string shortname;
};

/*!
 \brief Дочерний класс игрока, наследуемый от базового класса Creature
 
 Данный класс хранит основые характеристики персонажа (жизнь, опыт, координаты, размеры спрайта), а так же таблицу остальных характеристик персонажа.
 */

class Player: public Creature{
private:
	int hp; ///<Текущее значение здоровья
	unsigned int exp; ///<Текущий опыт
	unsigned int lvl;///<Уровень персонажа
	float w, h;///<Ширина и высота спрайта
	float dx,dy;///<Смещение персонажа на карте
	int dir;///<Направление движение персонажа
	/// Набор индексов характеристик объекта
	enum {
		STRENGTH, ///Сила персонажа
		MANA,///Мана
		LOVKOST,///Ловкость
		NECRO,///Уровень некромантии
		NONE///Резерв
	};
	std::ostringstream log;///<Строковый поток для записи логов игры
	array<Spec, 5> sp;///<Таблица из 5 характеристик
public:
	/*!
	 Инициализирует игрока без установки его позиции. (*в разработке*)Загрузка характеристик из конфигурационных файлов
	 */
	Player();
	/*!
	 Инициализирует игрока с установкой его позиции. (*в разработке*)Загрузка характеристик из конфигурационных файлов
	 \param[in] X x-координата персонажа на карте (используется для установки спрайта)
	 \param[in] Y y-координата персонажа на карте (используется для установки спрайта)
	 */
	Player( float X, float Y);
	
//	void takeObject();
//	void useObject();
	/*!
	 Обрабатывает удар врага. Если сила удара превышает защиту персонажа, то получившаяся разница вычитается из здоровья персонажа
	 \param[in] attack Пункты атаки врага
	 \return dead Умер ли пероснаж (1) или нет (0)
	 */
	int takeDamage(int attack);
	/*!
	 Повышает уровень опыта, на входе пункты опыта полчаемые от врага.
	 \param[in] _experience Пункты опыта, возвращаемые игроку
	 */
	void addExperience(int _experience);
	
	Player& setDir(int d){dir = d; return *this;}///<Установка позиции персонажа
	/*!
	 Геттер х-координаты
	 \return x Координата
	 */
	float getX(){return x;}
	/*!
	 Записывает характеристики персонажа в обычную строку. Запись идёт в объект std::ostringstream.
	 \return y Координата
	 */
	float getY(){return y;}
	/*!
	 Геттер переменной текущего здоровья
	 \return hp Здоровье
	 */
	int getHp(){return hp;}
	/*!
	 Геттер переменной текущего уровня
	 \return lvl Уровень
	 */
	int getLvl(){return lvl;}
	/*!
	 Геттер переменной текущего опыта
	 \return exp Опыт
	 */
	int getExp(){return exp;}
	/*!
	 Повышает здоровье на некую величину
	 \param[in] h Инкремент здоровья
	 */
	void upHp(int h){hp += h;}
	/*!
	Повышает силу персонажа
	 \param[in] str Инкремент силы
	 */
	void upStr(int str){strength += str;  sp[STRENGTH].points += str;}
	/*!
	 Повышает уровень защиты персонажа
	 \param[in] def Инкремент защиты
	 */
	void upDef(int def){defence += def;}
	/*!
	 Записывает характеристики персонажа в обычную строку. Запись идёт в объект std::ostringstream.
	 \return Estring.str() Выходная строка
	 */
	std::string setSTR();
	/*!
	 Геттер для приватной переменной строкового потока
	 \return log Строка логов
	 */
	std::ostringstream & getLog(){return log;}
};

#endif /* player_hpp */
