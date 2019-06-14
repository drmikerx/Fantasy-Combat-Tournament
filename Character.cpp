/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the Character class. Please see below
for specifics about the member functions.
******************************************************************************************/


#include "Character.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


/******************************************************************************************
** Description: setArmor accepts an integer parameter and uses it to set the value of the
armor member variable.
******************************************************************************************/

void Character::setArmor(int enteredArmor)
{
	armor = enteredArmor;
}


/******************************************************************************************
** Description: getArmor returns the current value stored in the armor member variable.
******************************************************************************************/

int Character::getArmor()
{
	return armor;
}


/******************************************************************************************
** Description: setStrengthPoints accepts an integer parameter and uses it to set the 
value of the strengthPoints member variable.
******************************************************************************************/

void Character::setStrengthPoints(int enteredStrengthPoints)
{
	strengthPoints = enteredStrengthPoints;
}


/******************************************************************************************
** Description: getStrengthPoints returns the current value stored in the strengthPoints 
member variable.
******************************************************************************************/

int Character::getStrengthPoints()
{
	return strengthPoints;
}


/******************************************************************************************
** Description: setCharacterType accepts a string parameter and uses it to set the 
value of the characterType member variable.
******************************************************************************************/

void Character::setCharacterType(string enteredCharacterType)
{
	characterType = enteredCharacterType;
}


/******************************************************************************************
** Description: getCharacterType returns the current value stored in the characterType 
member variable.
******************************************************************************************/

string Character::getCharacterType()
{
	return characterType;
}

// NEED DESCRIPTION
void Character::setCharacterName(string enteredName)
{
	characterName = enteredName;
}

// NEED DESCRIPTION
string Character::getCharacterName()
{
	return characterName;
}



/******************************************************************************************
** Description: The Character constructor accepts two integers and a string as parameters
and calls the set functions for armor, strength points, and character type to set the
values of the respective member variables.
******************************************************************************************/

Character::Character(int enteredArmor, int enteredStrengthPoints, string enteredCharacterType)
{
	setArmor(enteredArmor);
	setStrengthPoints(enteredStrengthPoints);
	setCharacterType(enteredCharacterType);
}


/******************************************************************************************
** Description: setTotalAttack accepts an integer parameter and uses it to set the 
value of the totalAttack member variable.
******************************************************************************************/

void Character::setTotalAttack(int enteredAttack)
{
	totalAttack = enteredAttack;
}


/******************************************************************************************
** Description: getTotalAttack returns the current value stored in the totalAttack 
member variable.
******************************************************************************************/

int Character::getTotalAttack()
{
	return totalAttack;
}


/******************************************************************************************
** Description: setTotalDefense accepts an integer parameter and uses it to set the 
value of the totalDefense member variable.
******************************************************************************************/

void Character::setTotalDefense(int enteredDefense)
{
	totalDefense = enteredDefense;
}


/******************************************************************************************
** Description: getTotalDefense returns the current value stored in the totalDefense 
member variable.
******************************************************************************************/

int Character::getTotalDefense()
{
	return totalDefense;
}


/******************************************************************************************
** Description: restoreSomeStrength is called at the end of each battle. Per program
specifications, the winner of each round recovers a random % of the damage they received
during the fight. The % recovered is based on a die roll from 1 to 5. 1 represents 10%,
2 represents 20%, etc. If the results of the calculation of damage * % to recover is a
number less than 1, the function restores 1 point of strength to the character. Because
these decimals need to be seen temporarily, the amountStrengthToAdd has been declared as
a double. Since strength points are represented by integers, the amount to add is converted
to an integer and the decimal discarded before adding it to the character's strength.
******************************************************************************************/

// Sometimes the result of the calculation will be a double. 
// In these cases, just allow the decimal to be discarded by design choice
void Character::restoreSomeStrength(int totalDamage)
{
	int randomNumberReturned;
	double amountStrengthToAdd;

	randomNumberReturned = randomNumberFrom1to5();

	if (randomNumberReturned == 1)
	{
		// Restore 10% of damage received
		amountStrengthToAdd = totalDamage * 0.1;

		// If the result is between 0 and 1, just add 1 to strength
		if (amountStrengthToAdd > 0 && amountStrengthToAdd < 1)
		{
			//cout << "\nWinner restores 1 point of strength!" << endl;
			this->strengthPoints += 1;	// They will at least have one strength point added
		}

		// Otherwise add the amount (minus its decimal) to the strength points
		else
		{
			//cout << "Winner restores 10% damage or: " << static_cast<int>(amountStrengthToAdd) << endl;
			this->strengthPoints += static_cast<int>(amountStrengthToAdd);
		}
	}

	else if (randomNumberReturned == 2)
	{
		// Restore 20% of damage received
		amountStrengthToAdd = totalDamage * 0.2;

		// If the result is between 0 and 1, just add 1 to strength
		if (amountStrengthToAdd > 0 && amountStrengthToAdd < 1)
		{
			//cout << "\nWinner restores 1 point of strength!" << endl;
			this->strengthPoints += 1;	// They will at least have one strength point added
		}

		// Otherwise add the amount (minus its decimal) to the strength points
		else
		{
			//cout << "Winner restores 20% damage or: " << static_cast<int>(amountStrengthToAdd) << endl;
			this->strengthPoints += static_cast<int>(amountStrengthToAdd);
		}
	}

	else if (randomNumberReturned == 3)
	{
		// Restore 30% of damage received
		amountStrengthToAdd = totalDamage * 0.3;

		// If the result is between 0 and 1, just add 1 to strength
		if (amountStrengthToAdd > 0 && amountStrengthToAdd < 1)
		{
			//cout << "\nWinner restores 1 point of strength!" << endl;
			this->strengthPoints += 1;	// They will at least have one strength point added
		}

		// Otherwise add the amount (minus its decimal) to the strength points
		else
		{
			//cout << "Winner restores 30% damage or: " << static_cast<int>(amountStrengthToAdd) << endl;
			this->strengthPoints += static_cast<int>(amountStrengthToAdd);
		}
	}

	else if (randomNumberReturned == 4)
	{
		// Restore 40% of damage received
		amountStrengthToAdd = totalDamage * 0.4;

		// If the result is between 0 and 1, just add 1 to strength
		if (amountStrengthToAdd > 0 && amountStrengthToAdd < 1)
		{
			//cout << "\nWinner restores 1 point of strength!" << endl;
			this->strengthPoints += 1;	// They will at least have one strength point added
		}

		// Otherwise add the amount (minus its decimal) to the strength points
		else
		{
			//cout << "Winner restores 40% damage or: " << static_cast<int>(amountStrengthToAdd) << endl;
			this->strengthPoints += static_cast<int>(amountStrengthToAdd);
		}
	}

	else if (randomNumberReturned == 5)
	{
		// Restore 50% of damage received
		amountStrengthToAdd = totalDamage * 0.5;

		// If the result is between 0 and 1, just add 1 to strength
		if (amountStrengthToAdd > 0 && amountStrengthToAdd < 1)
		{
			//cout << "\nWinner restores 1 point of strength!" << endl;
			this->strengthPoints += 1;	// They will at least have one strength point added
		}

		// Otherwise add the amount (minus its decimal) to the strength points
		else
		{
			//cout << "Winner restores 50% damage or: " << static_cast<int>(amountStrengthToAdd) << endl;
			this->strengthPoints += static_cast<int>(amountStrengthToAdd);
		}
	}

}


/******************************************************************************************
** Description: randomNumberFrom1To5 is used to simulate a die roll to determine the % of
damage the winner of the battle is to recover. It generates the random integer and then
returns it to the calling function.
******************************************************************************************/


int Character::randomNumberFrom1to5()
{
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 5;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;

}