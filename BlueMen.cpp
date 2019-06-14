/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the BlueMen class. Please see below
for specifics about the member functions.
******************************************************************************************/


#include "BlueMen.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


/******************************************************************************************
** Description: The BlueMen constructor takes two integers and a string as parameters.
It calls upon the base class constructor to set the values of armor, strength points,
and character type.
******************************************************************************************/

BlueMen::BlueMen(int enteredArmor, int enteredStrengthPoints, string enteredCharacterType)
	: Character(enteredArmor, enteredStrengthPoints, enteredCharacterType)
{
	// Base class constructor handles setup of all variables
}


/******************************************************************************************
** Description: This overwritten version of printAttackStats prints data specific to
BlueMen attack values after a BlueMen attacks. Though this function was not used in
the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void BlueMen::printAttackStats()
{
	cout << "The attacker rolled a " << this->attackDice1 << " and " << this->attackDice2 << "." << endl;
	cout << "This means the total attack value is: " << this->getTotalAttack() << endl;
}


/******************************************************************************************
** Description: This overwritten version of the printDefenseStats function prints
different messages depending on the strength points of the BlueMen before the opponent's
attack. This is because the Mob ability causes BlueMen to lose one defense die every 4
strength points lost. This means the number of denfenceDice to display to the screen
differs. Though this function was not used in the final design, it was utilized during 
testing, so it was left in the project.
******************************************************************************************/

void BlueMen::printDefenseStats()
{
	// Prints different info depending on current value of strength points and thus number of die used
	if (this->strengthBeforeAttack >= 9)
	{
		cout << "Blue Men used 3 Defense Die!" << endl;
		cout << "The defender rolled a " << this->defenseDice1 << " and " << this->defenseDice2 << 
			" and " << this->defenseDice3 << "." << endl;
		cout << "This means the total defense value is: " << this->getTotalDefense() << endl;
	}

	else if (this->strengthBeforeAttack < 9 && this->strengthBeforeAttack >= 5)
	{
		cout << "Blue Men used 2 Defense Die!" << endl;
		cout << "The defender rolled a " << this->defenseDice1 << " and " << this->defenseDice2 << "." << endl;
		cout << "This means the total defense value is: " << this->getTotalDefense() << endl;
	}

	else if (this->strengthBeforeAttack <= 4)
	{
		cout << "Blue Men could only use 1 Defense Dice!" << endl;
		cout << "The defender rolled a " << this->defenseDice1 << "." << endl;
		cout << "This means the total defense value is: " << this->getTotalDefense() << endl;
	}
}


/******************************************************************************************
** Description: randomNumber1To6 generates a random integer between 1 and 6 and returns it
to the calling function. Used for the defense dice.
******************************************************************************************/

int BlueMen::randomNumber1To6()
{
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 6;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}


/******************************************************************************************
** Description: randomNumber1To10 generates a random integer between 1 and 10 and returns it
to the calling function. Used for the attack dice.
******************************************************************************************/

int BlueMen::randomNumber1To10()
{
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 10;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}


/******************************************************************************************
** Description: This overwritten version of the attack function simulates two attack dice
rolls and calculates their sum and assigns it to the totalAttack member variable. This
totalAttack is returned to the calling function.
******************************************************************************************/

// Overwrite base class versions
int BlueMen::attack()
{
	attackDice1 = randomNumber1To10();
	attackDice2 = randomNumber1To10();

	this->setTotalAttack(attackDice1 + attackDice2);
	// Included a total attack member variable so I could display it to screen after each round

	return this->getTotalAttack();
}


/******************************************************************************************
** Description: This overwritten version of the defense function accepts an integer as a
parameter. This integer represents the attack value produced in the opponent's attack
function. The function simulates 3 defense dice rolls. strengthBeforeAttack variable is used so the
printDefenseStats function can print the correct message based on strength before the
attack. Due to BlueMen's Mob ability, they lose 1 defense dice for each 4 points of damage
taken. This function determines how many dice will be used by checking the current value
of the strength points for the defending character. It then calculates damage based on
attack value, defense, and armor, adjusts the strength points and returns the value to 
the calling function. If damage <= 0, then 0 damage is returned.
******************************************************************************************/

int BlueMen::defense(int opponentAttackValue)
{
	int damage;

	defenseDice1 = randomNumber1To6();
	defenseDice2 = randomNumber1To6();
	defenseDice3 = randomNumber1To6();

	// This variable is used for the printDefenseStats function captures strength before damage
	strengthBeforeAttack = this->getStrengthPoints(); 

	// Mob causes character to lose 1 defense die for each 4 points of damage lost
	if (this->getStrengthPoints() >= 9)
	{
		// Gets to use all 3 die 
		this->setTotalDefense(defenseDice1 + defenseDice2 + defenseDice3);
		//cout << "\nBlue Men have strength over 8. They use all 3 defense die." << endl;
	}

	else if (this->getStrengthPoints() < 9 && this->getStrengthPoints() >= 5)
	{
		// After losing 4 points only 2 defense die can be used
		this->setTotalDefense(defenseDice1 + defenseDice2);
		//cout << "\nBlue Men have strength 8-5. They can only use 2 defense die now." << endl;
	}

	else if (this->getStrengthPoints() <= 4)
	{
		// Only gets to use 1 defense die after reaching 4 strength or below
		this->setTotalDefense(defenseDice1);
		//cout << "\nBlue Men have strength 4 or less. They can only use 1 defense die now." << endl;
	}

	damage = opponentAttackValue - this->getTotalDefense() - this->getArmor();

	if (damage > 0)
	{
		// use setStrengthPoints to reassign it the initial value - damage
		this->setStrengthPoints(this->getStrengthPoints() - damage);

		return damage;
	}

	// If result of calculation was 0 or negative, then no damage was taken by the defender
	else
	{
		return 0;
	}
}