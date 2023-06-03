#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include <list>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

class Character
{
private:
	string className; // The class name of the character
	string name; // The name of the character
	bool defending; // Indicates if the character is defending
	int armor; // The armor value of the character
	int hp; // The health points of the character
	int damage; // The damage value of the character

public:
	Character(); // Default constructor

	// Creates a character based on the input number and player status
	void createCharacter(int num, bool isPlayer);

	// Get the armor value of the character
	int getArmor();

	// Get the current health points of the character
	int getHP();

	// Reduce the character's health points by the specified damage amount
	void setHP(int damage);

	// Get the name of the character
	string getName();

	// Get the class name of the character
	string getClassName();

	// Check if the character is defending
	bool isDefend();

	// Set the character's defense status
	void setDefense(bool setDefense);

	// Increase the character's health points by 1
	void heal();

	// Check if the character is alive (hp <= 0)
	bool isAlive();

	// Perform an attack on the opponent character
	void performAttack(Character& opponent);
};
