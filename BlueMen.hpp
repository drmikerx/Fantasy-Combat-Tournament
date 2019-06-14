/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the header file for the BlueMen class. It is a child class of
the Character class. In addtion to the variables and functions inherited from that class,
it has 2 attackDice variables, and 3 defenseDice variables to store the results returned
from the random number generators. Its constructor uses the base class constructor to
set variable values armor, strengthPoints, and characterType. It also overwrites the
parent functions printAttackStats, printDefenseStats, attack, and defense. Lastly, it has
an extra variable called strengthBeforeAttack that is unique to this class. It is used
in the printDefenseStats function to account for the Mob ability. Please see implementation
file for more details.
******************************************************************************************/


#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"
#include <string>

class BlueMen : public Character
{
private:

	int attackDice1;
	int attackDice2;

	int defenseDice1;
	int defenseDice2;
	int defenseDice3;

	int strengthBeforeAttack;

public:

	BlueMen(int, int, std::string);

	virtual void printAttackStats();

	virtual void printDefenseStats();

	int randomNumber1To6();
	int randomNumber1To10();


	// Overwrite base class versions
	virtual int attack();
	virtual int defense(int);


};



#endif