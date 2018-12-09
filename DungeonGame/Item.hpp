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
//#include "player.hpp"

class Item{
protected:
	float x, y;
	std::string name;
	int effect;
public:
	float getX(){return x;}
	float getY(){return y;}
	std::string getName(){return name;}
	int getEff(){return effect;}
	
	virtual Item* clone()const = 0;
	inline std::string debugPrint() const { return this->name; }
	void setPnt(float _x, float _y){x = _x; y = _y;}
	void setName(const char * _name){ name = _name;}
	void setEff(int eff){effect = eff;}
	
	virtual ~Item(){};
	
	//virtual void makeEffect() = 0;
};


/////////ARMOR////////
class Armor : public Item{
private:
	int type;
public:
	Armor(){};
	//virtual void makeEffect();
	virtual ~Armor();
	virtual Armor* clone()const;
	void setType(int _type){type = _type;}
	
	int getType(){return type;}
};


/////////WEAPON////////
class Weapon : public Item{
private:
	int coef;
public:
	//virtual void makeEffect();
	
	virtual ~Weapon();
	
	//Pure virtual
	virtual Weapon* clone()const;
	void setCoef(int c){coef = c;}
	
	int getCoef(){return coef;}
};


/////////POTION////////
class Potion : public Item{
private:
	int type;
public:
	//virtual void makeEffect(Player &player);
	virtual ~Potion();
	
	//Pure virtual
	virtual Potion* clone()const;
	void setType(int _type){type = _type;}
	
	int getType(){return type;}
};


#endif /* Item_hpp */
