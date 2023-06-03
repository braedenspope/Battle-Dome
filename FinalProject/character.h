#pragma once
#include <iostream>;
#include <list>;
#include <iterator>;
#include <list>;
#include <iomanip>;
#include <algorithm>;
#include <numeric>;
#include <string>;

using namespace std;

class Character
{
private:
	string className;
	string name;
	bool defending;
	int armor;
	int hp;
	int damage;
public:
	Character();
	void createCharacter(int num, bool isPlayer);
	int getArmor();
	int getHP();
	void setHP(int damage);
	string getName();
	string getClassName();
	bool isDefend();
	void setDefense(bool setDefense);
	void heal();
	bool isAlive();
	void performAttack(Character & opponent);

};

