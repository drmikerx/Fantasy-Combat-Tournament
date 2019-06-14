/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the HarryPotter class. Please see
below for specifics about the member functions.
******************************************************************************************/


#include "HarryPotter.hpp"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


/******************************************************************************************
** Description: The HarryPotter constructor receives 2 integers and a string as parameters
and passes them off to the Character constructor to set the armor, strengthPoints, and
characterType member variables. It also sets the Harry Potter specific member variable
hasDiedBefore to false. This variable is used to determine with Harry can use Hogwarts
when his strength falls to 0 or below.
******************************************************************************************/

HarryPotter::HarryPotter(int enteredArmor, int enteredStrengthPoints, string enteredCharacterType)
	: Character(enteredArmor, enteredStrengthPoints, enteredCharacterType)
{
	// Base class constructor handles setup of variables

	hasDiedBefore = false;	// Will be set to true if Harry Potter uses Hogwarts ability once
}


/******************************************************************************************
** Description: This overwritten version of printAttackStats prints data specific to
Harry Potter attack values after a Harry Potter attacks. Though this function was not used 
in the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void HarryPotter::printAttackStats()
{
	cout << "The attacker rolled a " << this->attackDice1 << " and " << this->attackDice2 << "." << endl;
	cout << "This means the total attack value is: " << this->getTotalAttack() << endl;
}


/******************************************************************************************
** Description: This overwritten version of printDefenseStats prints data specific to
Harry Potter defense values after a Harry Potter defends. Though this function was not used 
in the final design, it was utilized during testing, so it was left in the project.
******************************************************************************************/

void HarryPotter::printDefenseStats()
{
	cout << "The defender rolled a " << this->defenseDice1 << " and " << this->defenseDice2 << "." << endl;
	cout << "This means the total defense value is: " << this->getTotalDefense() << endl;
}


/******************************************************************************************
** Description: randomNumber1To6 generates a random integer between 1 and 6 and returns
it to the calling function. It is used to simulate attack and defense die rolling.
******************************************************************************************/

int HarryPotter::randomNumber1To6()
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
int HarryPotter::attack()
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
armor, the total damage is calculated and applied to the defender's strength points. If 
the result of subtracting the damage from the strength points causes the value to be 0 or
lower, and this is Harry's first life (hasDiedBefore = false), then the function sets
hasDiedBefore to true so this path cannot be used a second time. It then sets Harry's
strength points back up to 20.  If strength points did not reach 0 or below or this is
Harry's second life, then the reduction in strength points is sustained. The function
finishes by passing the value of damage to the calling function. If the result of the
damage calculation is zero or negative, the function returns 0 damage receieved.
******************************************************************************************/

int HarryPotter::defense(int opponentAttackValue)
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

		// He has technically died, but this is still his first life
		if (getStrengthPoints() <= 0 && this->hasDiedBefore == false)
		{
			this->hasDiedBefore = true;		// He won't be able to do this again
			this->setStrengthPoints(20);
			//cout << "\nHarry's defense this round was " << defenseDice1 << " + " << defenseDice2 << " = " << this->getTotalDefense()
				//<< " which means the attack caused enough damage to kill him..." << endl;
			//cout << "\nBut, Harry Potter has used the Hogwarts ability and is alive again with 20 Strength Points!" << endl;
			//cout << "Any total damage shown below is merely to display attack results."
				//<< " Despite this damage, Harry's strength is now 20." << endl;
		}

		return damage;
	}

	// If result of calculation was 0 or negative, then no damage was taken by the defender
	else
	{
		return 0;
	}
}