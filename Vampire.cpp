/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the Vampire class. Please see below
for more specific details about the member functions.
******************************************************************************************/


#include "Vampire.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


/******************************************************************************************
** Description: The Vampire constructor takes two integers and a string as parameters.
It calls upon the base class constructor to set the values of armor, strength points,
and character type.
******************************************************************************************/

Vampire::Vampire(int enteredArmor, int enteredStrengthPoints, string enteredCharacterType)
	: Character(enteredArmor, enteredStrengthPoints, enteredCharacterType)
{
	// Base class constructor handles setup of all variables
}


/******************************************************************************************
** Description: This overwritten version of printAttackStats prints data specific to
Vampire attack values after a Vampire attacks. Though this function was not used in
the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void Vampire::printAttackStats()
{
	cout << "The attacker rolled a " << this->attackDice1 << "." << endl;
	cout << "This means the total attack value is: " << this->getTotalAttack() << endl;
}


/******************************************************************************************
** Description: This overwritten version of printDefenseStats prints data specific to
Vampire defense values after a Vampire defends. Though this function was not used in
the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void Vampire::printDefenseStats()
{
	cout << "The defender rolled a " << this->defenseDice1 << "." << endl;
	cout << "This means the total defense value is: " << this->getTotalDefense() << endl;
}


/******************************************************************************************
** Description: randomNumber1To12 generates a random integer between 1 and 12 and returns
it to the calling function. It is used to simulate attack die rolling.
******************************************************************************************/

int Vampire::randomNumber1To12()
{
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 12;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}


/******************************************************************************************
** Description: randomNumber1To6 generates a random integer between 1 and 6 and returns
it to the calling function. It is used to simulate defense die rolling.
******************************************************************************************/

int Vampire::randomNumber1To6()
{
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 6;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}


/******************************************************************************************
** Description: randomNumber1Or2 generates a random integer either 1 or 2 and returns
it to the calling function. It is used to simulate a 50-50 chance of Charm activating.
******************************************************************************************/

int Vampire::randomNumber1Or2()
{
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 2;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}


/******************************************************************************************
** Description: This overwritten version of the attack function generates one attack die
roll producing a random number from 1 to 12. It then stores this value in the totalAttack 
member variable. Lastly, it returns this value to the calling function.
******************************************************************************************/

// Attacks with 1 12 sided die
int Vampire::attack()
{
	attackDice1 = randomNumber1To12();

	this->setTotalAttack(attackDice1);

	return this->getTotalAttack();
}


/******************************************************************************************
** Description: This overwritten version of the defense function accepts an integer as a
parameter. This number is the integer returned from the opponent's attack function. It
starts by calling a function to generate either 1 or 2. This simulates a 50-50 chance
that the Charm ability will be activated. It then gets a random number from 1 to 6 to
represent the defense die roll. totalDefense is set to the die roll value and then 
using the attack value, defense value, and the defending character's armor, the total 
damage is calculated. If charmChance was 1, this was taken to mean that Charm was not
activated and damage was actually sustained by the Vampire. If the result of the
damage calculation is zero or negative, the function returns 0 damage receieved. 
Otherwise, the damage is subtracted from the current value of strengthPoints for the 
character, and damage is returned to the calling function. If charmChance was 2 however, 
Charm activated and the Vampire avoided attack. A message displays and 0 is returned 
from the function to signify that the Vampire did not take any damage.
******************************************************************************************/

int Vampire::defense(int opponentAttackValue)
{
	int charmChance;
	int damage;

	charmChance = randomNumber1Or2();

	defenseDice1 = randomNumber1To6();

	this->setTotalDefense(defenseDice1);

	damage = opponentAttackValue - this->getTotalDefense() - this->getArmor();

	if (charmChance == 1)	// Charm was NOT activated
	{
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

	else if (charmChance == 2)	// Charm was activated
	{
		//cout << "\nVampire uses Charm! The opponent's attack has failed! "
			//<< "Regardless of attack and defense die rolls, Total Damage = 0!" << endl;
		return 0;	// Enemy did NOT damage the Vampire
	}
}