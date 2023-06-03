#include "character.h"
#include <iostream>;
#include <list>;
#include <iterator>;
#include <list>;
#include <iomanip>;
#include <algorithm>;
#include <numeric>;

using namespace ::std;

string possibleNames[] = { "Jim", "Overlord of the Underworld", "Speffen", "Trevor", "Varis Omen", "Salazar Dalen", "Kevin", "Ryder Throckmorton", "Damocles"};

Character::Character() {}

void Character::createCharacter(int num, bool isPlayer)
{
	if (isPlayer)
	{
		string name;
		cout << "Enter the name of your fighter: ";
		getline(cin, name);
		this->name = name;
	}
	else {
		string name;
		int random = rand() % 9;
		name = possibleNames[random];
		this->name = name;
	}
	

	if (num == 1) {
		className = "Warrior";
		armor = 2;
		hp = 10;
		damage = 2;
	}
	else if (num == 2) {
		className = "Mage";
		armor = 1;
		hp = 10;
		damage = 3;
	}
	else if (num == 3) {
		className = "Guardian";
		armor = 3;
		hp = 10;
		damage = 1;
	}
}

int Character::getArmor() { return armor; }

int Character::getHP() { return hp; }

void Character::setHP(int damage) 
{
	hp -= damage;
}

string Character::getName() { return name; }

string Character::getClassName() { return className; }

bool Character::isAlive() { return hp <= 0; }

void Character::heal()
{
	this->hp += 1;
}

bool Character::isDefend()
{
	return defending;
}

void Character::setDefense(bool setDefense)
{
	defending = setDefense;
}

void Character::performAttack(Character & opponent)
{
	int damageDealt = 1;
	int damage = this->damage;
	if (!opponent.isDefend()) {
		damageDealt = damage - armor;
		if (damageDealt <= 0) {
			damageDealt = 1;
		}
	}
	opponent.setHP(damageDealt);
}
