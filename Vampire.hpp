/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the header file for the Vampire class. It is a child class of
the Character class. In addtion to the variables and functions inherited from that class,
it has 1 attackDice variable, and 1 defenseDice variable to store the results returned
from the random number generators. Its constructor uses the base class constructor to
set variable values armor, strengthPoints, and characterType. It also overwrites the
parent functions printAttackStats, printDefenseStats, attack, and defense.
******************************************************************************************/


#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

#include <string>

class Vampire : public Character
{
private:

	int attackDice1;
	int defenseDice1;


public:

	Vampire(int, int, std::string);	// Will use base class constructor to set values

	virtual void printAttackStats();

	virtual void printDefenseStats();

	int randomNumber1To12();	// For attack dice
	int randomNumber1To6();		// For defense dice
	int randomNumber1Or2();		// For Charm activation


	// Overwrite base class versions
	virtual int attack();
	virtual int defense(int);


};


#endif