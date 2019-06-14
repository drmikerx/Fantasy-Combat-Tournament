/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the Medusa class. Please see below
for more specific details about the member functions.
******************************************************************************************/


#include "Medusa.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


/******************************************************************************************
** Description: The Medusa constructor accepts 2 integers and a string as parameters. It
passes these values to the Character constructor which sets the values of armor,
strengthPoints, and characterType.
******************************************************************************************/

Medusa::Medusa(int enteredArmor, int enteredStrengthPoints, string enteredCharacterType)
	: Character(enteredArmor, enteredStrengthPoints, enteredCharacterType)
{
	// Base class constructor handles setup of all variables
}


/******************************************************************************************
** Description: This overwritten version of printAttackStats prints data specific to
Medusa attack values after a Medusa attacks. Though this function was not used in
the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void Medusa::printAttackStats()
{
	cout << "The attacker rolled a " << this->attackDice1 << " and " << this->attackDice2 << "." << endl;
	cout << "This means the total attack value is: " << this->getTotalAttack() << endl;
}


/******************************************************************************************
** Description: This overwritten version of printDefenseStats prints data specific to
Medusa defense values after a Medusa defends. Though this function was not used in
the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void Medusa::printDefenseStats()
{
	cout << "The defender rolled a " << this->defenseDice1 << "." << endl;
	cout << "This means the total defense value is: " << this->getTotalDefense() << endl;
}


/******************************************************************************************
** Description: randomNumber1To6 generates a random integer between 1 and 6 and returns
it to the calling function. It is used to simulate attack and defense die rolling.
******************************************************************************************/

int Medusa::randomNumber1To6()
{
	int randomNumber;
	const int MIN_VALUE = 1;
	const int MAX_VALUE = 6;

	randomNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + 1;

	return randomNumber;
}


/******************************************************************************************
** Description: This overwritten version of the attack function starts by simulating two
die rolls each producing a number between 1 and 6. If a 12 happens to be rolled, Medusa's
Glare ability is activated causing her to attack with a tremendous value of 100,000. This
serves as a one hit kill to any defending character (unless Vampire also uses Charm). 
If Harry Potter gets hit by it on his first life, he gets resurrected for a second life. 
If a 12 is not rolled, the attack die are summed and the total attack value is returned 
to the calling function.
******************************************************************************************/

int Medusa::attack()
{
	attackDice1 = randomNumber1To6();
	attackDice2 = randomNumber1To6();

	if (attackDice1 + attackDice2 == 12)
	{
		//cout << "\nMedusa uses Glare! She has turned her opponent to stone!" << endl;
		this->setTotalAttack(100000);	// One hit kill
	}

	else
	{
		this->setTotalAttack(attackDice1 + attackDice2);
		// Included a total attack member variable so I could display it to screen after each round
	}

	return this->getTotalAttack();
}


/******************************************************************************************
** Description: This overwritten version of the defense function accepts an integer as a
parameter. This number is the integer returned from the opponent's attack function. It
gets one random number between 1 and 6 for the defense die, it then sets this value as
the totalDefense. Using the attack value, defense value, and the defending character's
armor, the total damage is calculated and applied to the defender's strength points.
Lastly, the function returns the damage to the calling function. If the result of the
damage calculation is zero or negative, the function returns 0 damage receieved.
******************************************************************************************/

int Medusa::defense(int opponentAttackValue)
{
	int damage;

	defenseDice1 = randomNumber1To6();

	this->setTotalDefense(defenseDice1);

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