#include <iostream>
#include <list>
#include <iterator>
#include <list>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "character.h"

using namespace std;

// Function to allow the player to choose a character class
Character chooseCharacter()
{
   string choice;
   int num;
   cout << "1. WARRIOR (Medium Attack, Medium Defense)\n";
   cout << "2. MAGE (High Attack, Low Defense)\n";
   cout << "3. GUARDIAN (Low Attack, High Defense)\n";
   cout << "What class do you want to play as?\n> ";
   getline(cin, choice);
   num = stoi(choice);
   Character hero;
   hero.createCharacter(num, true);
   return hero;
}

// Function to create a random character for the opponent
Character createRandom()
{
   Character opponent;
   int choice = rand() % 3;
   opponent.createCharacter(choice, false);
   return opponent;
}

// Function to display the information of a character
void displayCharacter(Character hero)
{
   cout << "Name: " << hero.getName() << endl;
   cout << "Class: " << hero.getClassName() << endl;
   cout << "Armor: " << hero.getArmor() << endl << endl;
}

// Function to display the health of the player and opponent
void displayHealth(Character hero, Character opponent)
{
   cout << "Your health: " << hero.getHP() << endl;
   cout << "Your opponent's health: " << hero.getHP() << endl;
}

// Function to perform a random action for a character on their opponent
int performRandomAction(Character& hero, Character& opponent)
{
   int action = rand() % 4 + 1;
   if (action == 1)
   {
      hero.performAttack(opponent);
      cout << endl << hero.getName() << " attacks!\n";
      return 1;
   }
   else if (action == 2)
   {
      hero.setDefense(true);
      cout << endl << hero.getName() << " defends!\n";
      return 2;
   }
   else if (action == 3)
   {
      hero.heal();
      cout << endl << hero.getName() << " heals!\n";
      return 3;
   }
}

// Function to display the results of the battle
void displayResults(int attacks, int defends, int heals)
{
   cout << "You attacked " << attacks << " times.\n";
   cout << "You defended " << defends << " times.\n";
   cout << "You healed " << heals << " times.\n";
}

int main()
{
   bool surrender = false;
   cout << "Welcome to the Battle Dome!\n";
   Character hero = chooseCharacter();
   Character opponent = createRandom();
   cout << "Your character:\n";
   displayCharacter(hero);
   cout << "Your opponent:\n";
   displayCharacter(opponent);
   int heroAttacks = 0;
   int heroHeals = 0;
   int heroDefends = 0;
   bool loop = true;
   while (loop && hero.getHP() >= 0 && opponent.getHP() >= 0)
   {
      hero.setDefense(false);
      opponent.setDefense(false);
      string choice;
      int action;
      displayHealth(hero, opponent);
      cout << "1. Attack\n";
      cout << "2. Defend\n";
      cout << "3. Heal\n";
      cout << "4. Random Action\n";
      cout << "5. Surrender\n";
      cout << "What would you like to do? ";
      getline(cin, choice);
      action = stoi(choice);
      if (action == 1)
      {
         hero.performAttack(opponent);
         cout << endl << hero.getName() << " attacks!\n";
         heroAttacks++;
         performRandomAction(opponent, hero);
      }
      else if (action == 2)
      {
         hero.setDefense(true);
         cout << endl << hero.getName() << " defends!\n";
         heroDefends++;
         performRandomAction(opponent, hero);
      }
      else if (action == 3)
      {
         hero.heal();
         cout << endl << hero.getName() << " heals!\n";
         heroHeals++;
         performRandomAction(opponent, hero);
      }
      else if (action == 4)
      {
         int random = performRandomAction(hero, opponent);
         if (random == 1)
         {
            heroAttacks++;
         }
         else if (random == 2)
         {
            heroDefends++;
         }
         else if (random == 3)
         {
            heroHeals++;
         }
         performRandomAction(opponent, hero);
      }

      else if (action == 5)
      {
         loop = false;
         surrender = true;
         cout << "You've surrendered the game! You lose.\n";
         displayResults(heroAttacks, heroDefends, heroHeals);
      }
      cout << endl;
   }
   if (!surrender)
   {
      if (hero.getHP() <= 0 && opponent.getHP() <= 0)
      {
         cout << "It was a tie! Better luck next time!\n";
      }
      else if (hero.getHP() <= 0)
      {
         cout << opponent.getName() << " has won the match! Better luck next time!\n";
         displayResults(heroAttacks, heroDefends, heroHeals);
      }
      else
      {
         cout << hero.getName() << "has won the match! Congratulations!";
         displayResults(heroAttacks, heroDefends, heroHeals);
      }
   }
}
