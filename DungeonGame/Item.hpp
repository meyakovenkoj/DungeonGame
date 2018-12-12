//
//  Item.hpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 03/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <string>
#include <stdio.h>
#include "map.hpp"
#include "player.hpp"

class Item{
protected:
	float x, y;
	std::string name;
	int effect;
	int is;
public:
	float getX(){return x;}
	float getY(){return y;}
	std::string getName(){return name;}
	int getEff(){return effect;}
	
	int what(){return is;}
	virtual Item* clone()const = 0;
	inline std::string debugPrint() const { return this->name; }
	void setPnt(float _x, float _y){x = _x; y = _y;}
	void setName(const char * _name){ name = _name;}
	void setEff(int eff){effect = eff;}
	void setCOORD(Map &map);
	
	virtual ~Item(){};
	
	virtual void makeEffect(Player &player) = 0;
};


/////////ARMOR////////
class Armor : public Item{
private:
	int type;
public:
	Armor();
	
	virtual void makeEffect(Player &player);
	virtual Armor* clone()const;
	void setType(int _type){type = _type;}
	
	int getType(){return type;}
	virtual ~Armor();
};


/////////WEAPON////////
class Weapon : public Item{
private:
	int coef;
public:
	Weapon();
	
	virtual void makeEffect(Player &player);
	virtual Weapon* clone()const;
	void setCoef(int c){coef = c;}
	
	int getCoef(){return coef;}
	virtual ~Weapon();
};


/////////POTION////////
class Potion : public Item{
private:
	int type;
public:
	Potion();
	
	virtual void makeEffect(Player &player);
	virtual Potion* clone()const;
	void setType(int _type){type = _type;}
	
	int getType(){return type;}
	virtual ~Potion();
};


#endif /* Item_hpp */
