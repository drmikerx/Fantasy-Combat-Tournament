/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the header file for the HarryPotter class. It is a child class of
the Character class. In addtion to the variables and functions inherited from that class,
it has 2 attackDice variables, and 2 defenseDice variables to store the results returned
from the random number generators. Its constructor uses the base class constructor to
set variable values armor, strengthPoints, and characterType, and sets the class specific 
variable hasDiedBefore to false. It also overwrites the parent functions printAttackStats, 
printDefenseStats, attack, and defense.
******************************************************************************************/


#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"
#include <string>

class HarryPotter : public Character
{
private:
	int attackDice1;
	int attackDice2;

	int defenseDice1;
	int defenseDice2;

	bool hasDiedBefore;

public:

	HarryPotter(int, int, std::string);

	virtual void printAttackStats();

	virtual void printDefenseStats();

	int randomNumber1To6();


	// Overwrite base class versions
	virtual int attack();
	virtual int defense(int);

};


#endif