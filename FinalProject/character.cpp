#include "character.h"
#include <iostream>
#include <list>
#include <iterator>
#include <list>
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;

// Potential random names
string possibleNames[] = { "Jim", "Overlord of the Underworld", "Speffen", "Trevor", "Varis Omen", "Salazar Dalen", "Kevin", "Ryder Throckmorton", "Damocles" };

Character::Character() {}

void Character::createCharacter(int num, bool isPlayer)
{
	if (isPlayer)
	{
		string name;
		cout << "Enter the name of your fighter: ";
		getline(cin, name);
		this->name = name; // Set the name of the character
	}
	else {
		string name;
		int random = rand() % 9; // Generate a random number between 0 and 8
		name = possibleNames[random]; // Assign a random name from the possibleNames array
		this->name = name; // Set the name of the character
	}

	// Set the attributes based on the input number
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

// Get the armor of the character
int Character::getArmor() { return armor; }

// Get the current health of the character
int Character::getHP() { return hp; }

// Reduce the character's health
void Character::setHP(int damage)
{
	hp -= damage;
}

// Get the name of the character
string Character::getName() { return name; }

// Get the class name of the character
string Character::getClassName() { return className; }

// Check if the character is alive
bool Character::isAlive() { return hp <= 0; }

// Increase the character's health by 1
void Character::heal()
{
	this->hp += 1;
}

// Check if the character is defending
bool Character::isDefend()
{
	return defending;
}

// Set the character's defense status
void Character::setDefense(bool setDefense)
{
	defending = setDefense;
}

// Perform an attack on the opponent character
void Character::performAttack(Character& opponent)
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
