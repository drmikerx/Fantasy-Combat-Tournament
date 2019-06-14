/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the Barbarian class. Please see below
for specifics about the member functions.
******************************************************************************************/


#include "Barbarian.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

/******************************************************************************************
** Description: The Barbarian constructor takes two integers and a string as parameters.
It calls upon the base class constructor to set the values of armor, strength points,
and character type.
******************************************************************************************/


Barbarian::Barbarian(int enteredArmor, int enteredStrengthPoints, string enteredCharacterType) 
	: Character (enteredArmor, enteredStrengthPoints, enteredCharacterType)
{
	// Base class constructor handles setup of all variables
}


/******************************************************************************************
** Description: This overwritten version of printAttackStats prints data specific to
Barbarian attack values after a Barbarian attacks. Though this function was not used in
the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void Barbarian::printAttackStats()
{
	cout << "The attacker rolled a " << this->attackDice1 << " and " << this->attackDice2 << "." << endl;
	cout << "This means the total attack value is: " << this->getTotalAttack() << endl;
}


/******************************************************************************************
** Description: This overwritten version of printDefenseStats prints data specific to
Barbarian defense values after a Barbarian defends. Though this function was not used in
the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void Barbarian::printDefenseStats()
{
	cout << "The defender rolled a " << this->defenseDice1 << " and " << this->defenseDice2 << "." << endl;
	cout << "This means the total defense value is: " << this->getTotalDefense() << endl;
}


/******************************************************************************************
** Description: randomNumber1To6 generates a random integer between 1 and 6 and returns
it to the calling function. It is used to simulate attack and defense die rolling.
******************************************************************************************/

int Barbarian::randomNumber1To6()
{    
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 6;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}


/******************************************************************************************
** Description: This overwritten version of the attack function generates two attack die
rolls with each producing a random number from 1 to 6. It then sums these two, and stores
the final value in the totalAttack member variable. Lastly, it returns this value to the
calling function.
******************************************************************************************/

// Overwrite base class versions
int Barbarian::attack()
{
	attackDice1 = randomNumber1To6();
	attackDice2 = randomNumber1To6();

	this->setTotalAttack(attackDice1 + attackDice2);
	// Included a total attack member variable so I could display it to screen after each round

	return this->getTotalAttack();
}


/******************************************************************************************
** Description: This overwritten version of the defense function accepts an integer as a
parameter. This number is the integer returned from the opponent's attack function. It
gets two random numbers between 1 and 6 for the defense die, then sums the two values to
get the totalDefense. Using the attack value, defense value, and the defending character's
armor, the total damage is calculated and applied to the defender's strength points.
Lastly, the function returns the damage to the calling function. If the result of the
damage calculation is zero or negative, the function returns 0 damage receieved.
******************************************************************************************/

int Barbarian::defense(int opponentAttackValue)
{
	int damage;

	defenseDice1 = randomNumber1To6();
	defenseDice2 = randomNumber1To6();

	this->setTotalDefense(defenseDice1 + defenseDice2);

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