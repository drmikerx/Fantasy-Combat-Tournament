/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the Character class. It serves as
the parent class for all of the various character types used in the program. Each child
class will inherit an armor, strengthPoints, characterType, totalAttack, and totalDefense
variable. There are get and set functions for these variables as well. Its constructor
calls the set functions for armor, strengthPoints, and characterType and assigns these
variables the values of the respecitve constructor parameters. It also has virtual
printAttackStats, and printDefenseStats functions. Lastly, it has pure virtual functions
attack and defense, making this class an abstract class.
New for Project 4: a function called restoreSomeStrength, and a random number generator
from 1 to 5 was added to handle the new recovery system after each battle. See the
implementation file for more details.
******************************************************************************************/


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character
{
private:
	int armor;
	int strengthPoints;
	std::string characterType;
	int totalAttack;
	int totalDefense;
	std::string characterName;

public:

	void setArmor(int);
	int getArmor();

	void setStrengthPoints(int);
	int getStrengthPoints();

	void setCharacterType(std::string);
	std::string getCharacterType();

	void setCharacterName(std::string);
	std::string getCharacterName();

	Character(int, int, std::string);	// Constructor sets armor / strengthPoints / characterType

	virtual void printAttackStats()
	{
		// To be defined in the child classes
	}

	virtual void printDefenseStats()
	{
		// To be defined in the child classes
	}

	void setTotalAttack(int);
	int getTotalAttack();

	void setTotalDefense(int);
	int getTotalDefense();

	void restoreSomeStrength(int);
	int randomNumberFrom1to5();
	

	virtual int attack() = 0;	// Pure virutal
	virtual int defense(int) = 0; // Pure virtual
	// takes in value returned from other character's attack function and will apply
	// damage to defending character's strength points after accounting for defense


};



#endif