/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This file contains function definitions for various functions needed to
run the gameplay components of the program. See below for more details.
******************************************************************************************/


#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include "Lineup.hpp"
#include "Loser.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

int inputValidationContinueMenu(string dataToCheck);


/******************************************************************************************
** Description: generateCharacter is called after the user selects their character choice
from the beginning menu. It accepts an integer parameter that represents the user choice
and based on this number, it dynamically allocates memory for the appropriate character
type. Per program specifications, it also asks the user for the characters's name and 
stores it in the characterName member variable of the character object. It then returns 
a character pointer to the calling function that contains the address for this new object.
******************************************************************************************/

Character* generateCharacter(int characterChoice)
{
	Character* characterToCreate = NULL;
	string characterName;

	if (characterChoice == 1)
	{
		// generate Vampire
		characterToCreate = new Vampire(1, 18, "Vampire");
		
		cout << "\nNow please name this Vampire: ";
		getline(cin, characterName);
		while (characterName.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, characterName);
		}

		characterToCreate->setCharacterName(characterName);

	}

	else if (characterChoice == 2)
	{
		// generate Barbarian
		characterToCreate = new Barbarian(0, 12, "Barbarian");

		cout << "\nNow please name this Barbarian: ";
		getline(cin, characterName);
		while (characterName.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, characterName);
		}

		characterToCreate->setCharacterName(characterName);
	}

	else if (characterChoice == 3)
	{
		// generate Blue Men
		characterToCreate = new BlueMen(3, 12, "Blue Men");

		cout << "\nNow please name this Blue Men: ";
		getline(cin, characterName);
		while (characterName.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, characterName);
		}

		characterToCreate->setCharacterName(characterName);
	}

	else if (characterChoice == 4)
	{
		// generate Medusa
		characterToCreate = new Medusa(3, 8, "Medusa");

		cout << "\nNow please name this Medusa: ";
		getline(cin, characterName);
		while (characterName.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, characterName);
		}

		characterToCreate->setCharacterName(characterName);
	}

	else if (characterChoice == 5)
	{
		// generate Harry Potter
		characterToCreate = new HarryPotter(0, 10, "Harry Potter");

		cout << "\nNow please name this Harry Potter: ";
		getline(cin, characterName);
		while (characterName.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, characterName);
		}

		characterToCreate->setCharacterName(characterName);
	}

	return characterToCreate;
}


/******************************************************************************************
** Description: areBothCharactersAlive is called after each attack to determine if there
is a winner for the round. It accepts two Character*'s as parameters, which represent the
characters that have just done battle. If one of them has strengthPoints <=0, false is 
returned meaning that character has died. Otherwise, both characters are alive, and true is
returned. The returned bool is used to control the do-while loop in runBattles() that 
keeps the battle going.
******************************************************************************************/

bool areBothCharactersAlive(Character* teamACharacter, Character* teamBCharacter)
{
	if (teamACharacter->getStrengthPoints() <= 0)	// Team A character is dead
	{
		//cout << "\nCharacter from Team A has died. Team B wins." << endl;
		return false;
	}

	else if (teamBCharacter->getStrengthPoints() <= 0)	// Team B character is dead
	{
		//cout << "\nCharacter from Team B has died. Team A wins." << endl;
		return false;
	}

	// Both characters are still alive
	else
	{
		//cout << "\nBoth characters are still alive. The fight continues." << endl;
		return true;
	}
}


/******************************************************************************************
** Description: runBattles is the function that runs fights and controls the tournament
in the program. It accepts the two Lineup objects and the LoserStack object, created and 
populated in main by reference so that their contents can be changed. The tournament is
run in a while loop that only ends when one of the team's lineups is empty. This occurs
when all of their fighters have lost. It calculates each character's beginning strength
so the recovery function can later calculate the % of damage to restore. Each round is
controlled by a while loop that only ends when one character has died in the battle. Until
then, the characters keep taking turns attacking and defending. Once one character has
died, a bool becomes false causing the end of round stats to display. The winner gets 
some strength recovered, and is moved to the back of the team lineup. The loser is removed
from their lineup and sent to the loser pile. This process continues until one Lineup
becomes empty causing the outer while loop to end. At this point the tournament is over
so the final results are displayed, and the user is asked if they would like to see the
loser pile. If yes, the stack is displayed showing the fighter defeated last on top
through the first fighter defeated on the bottom.
******************************************************************************************/

void runBattles(Lineup & teamA, Lineup & teamB, LoserStack& losers)
{
	bool bothCharactersAlive = true;
	int totalAttack;
	int totalDamage;
	int roundNumber = 1;
	Character* losingCharacter;

	string wantsToPrintLosers;
	int wantsToPrintLosersValidated;

	int beginningSPTeamA;
	int beginningSPTeamB;
	int winnerSPAfterBattle;
	int damageSustainedByWinner;

	// Once one of the teams no longer has fighters, the battles should end
	// This happens when one of them has an empty queue
	while (!teamA.isEmpty() && !teamB.isEmpty())
	{
		beginningSPTeamA = teamA.getHeadPtr()->fighter->getStrengthPoints();
		beginningSPTeamB = teamB.getHeadPtr()->fighter->getStrengthPoints();
		// Keep running the individual battle until one character dies

		while (bothCharactersAlive)
		{
			// Only allow attack to happen if both characters still alive otherwise can skip

			if (bothCharactersAlive)
			{
				// Team A attacks first

				totalAttack = teamA.getHeadPtr()->fighter->attack();
				totalDamage = teamB.getHeadPtr()->fighter->defense(totalAttack);
				//cout << "\nTeam A's " << teamA.getHeadPtr()->fighter->getCharacterName()
					//<< "'s attack resulted in " << totalDamage << " points of damage to Team B's "
					//<< teamB.getHeadPtr()->fighter->getCharacterName() << endl;
				
				// Make sure both characters are still alive

				//cout << "\nCurrent strength points:" << endl;
				//cout << "Team A " << teamA.getHeadPtr()->fighter->getCharacterName()
					//<< ": " << teamA.getHeadPtr()->fighter->getStrengthPoints() << endl;
				//cout << "Team B " << teamB.getHeadPtr()->fighter->getCharacterName()
					//<< ": " << teamB.getHeadPtr()->fighter->getStrengthPoints() << endl;
				bothCharactersAlive = areBothCharactersAlive(teamA.getHeadPtr()->fighter, teamB.getHeadPtr()->fighter);
				//cout << "\nPlease press enter to continue....";
				//cin.get();
			}

			
			if (bothCharactersAlive)
			{
				// Now Team B attacks

				totalAttack = teamB.getHeadPtr()->fighter->attack();
				totalDamage = teamA.getHeadPtr()->fighter->defense(totalAttack);
				//cout << "\nTeam B's " << teamB.getHeadPtr()->fighter->getCharacterName()
					//<< "'s attack resulted in " << totalDamage << " points of damage to Team A's "
					//<< teamA.getHeadPtr()->fighter->getCharacterName() << endl;

				// Make sure both characters are still alive

				//cout << "\nCurrent strength points:" << endl;
				//cout << "Team A " << teamA.getHeadPtr()->fighter->getCharacterName()
					//<< ": " << teamA.getHeadPtr()->fighter->getStrengthPoints() << endl;
				//cout << "Team B " << teamB.getHeadPtr()->fighter->getCharacterName()
					//<< ": " << teamB.getHeadPtr()->fighter->getStrengthPoints() << endl;
				bothCharactersAlive = areBothCharactersAlive(teamA.getHeadPtr()->fighter, teamB.getHeadPtr()->fighter);
				//cout << "\nPlease press enter to continue....";
				//cin.get();
			}

			if (!bothCharactersAlive)
			{
				// Once one character has died, need to increase one team's points
				// Send loser to loser stack, and move winner to back of lineup
				if (teamA.getHeadPtr()->fighter->getStrengthPoints() <= 0)
				{
					// This means Team B won

					// Winning character recovers some strength
					winnerSPAfterBattle = teamB.getHeadPtr()->fighter->getStrengthPoints();
					damageSustainedByWinner = beginningSPTeamB - winnerSPAfterBattle;

					//cout << "\nSP of winner after battle was: " << teamB.getHeadPtr()->fighter->getStrengthPoints();

					teamB.getHeadPtr()->fighter->restoreSomeStrength(damageSustainedByWinner);

					//cout << "\nSP of winner is now: " << teamB.getHeadPtr()->fighter->getStrengthPoints();

					cout << "\nRound " << roundNumber << ": Team A "
						<< teamA.getHeadPtr()->fighter->getCharacterType() << " "
						<< teamA.getHeadPtr()->fighter->getCharacterName() << " vs. Team B "
						<< teamB.getHeadPtr()->fighter->getCharacterType() << " "
						<< teamB.getHeadPtr()->fighter->getCharacterName() << ", "
						<< teamB.getHeadPtr()->fighter->getCharacterType() << " "
						<< teamB.getHeadPtr()->fighter->getCharacterName() << " Won!" << endl;
					//cout << "\nTeam B won this round!" << endl;
					teamB.increaseTotalPoints();	// Team B gets a point
					losingCharacter = teamA.removeCharacterFromLineup();	// Losing character removed from lineup
					losers.addLoserToStack(losingCharacter);	// Losing character added to loser stack
					teamB.moveWinnerToTail();	// Winning character goes to the back of lineup
				}

				else if (teamB.getHeadPtr()->fighter->getStrengthPoints() <= 0)
				{
					// This means Team A won

					// Winning character recovers some strength
					winnerSPAfterBattle = teamA.getHeadPtr()->fighter->getStrengthPoints();
					damageSustainedByWinner = beginningSPTeamA - winnerSPAfterBattle;

					//cout << "\nSP of winner after battle was: " << teamA.getHeadPtr()->fighter->getStrengthPoints();

					teamA.getHeadPtr()->fighter->restoreSomeStrength(damageSustainedByWinner);

					//cout << "\nSP of winner is now: " << teamA.getHeadPtr()->fighter->getStrengthPoints();

					cout << "\nRound " << roundNumber << ": Team A "
						<< teamA.getHeadPtr()->fighter->getCharacterType() << " "
						<< teamA.getHeadPtr()->fighter->getCharacterName() << " vs. Team B "
						<< teamB.getHeadPtr()->fighter->getCharacterType() << " "
						<< teamB.getHeadPtr()->fighter->getCharacterName() << ", "
						<< teamA.getHeadPtr()->fighter->getCharacterType() << " "
						<< teamA.getHeadPtr()->fighter->getCharacterName() << " Won!" << endl;
					//cout << "\nTeam A won this round!" << endl;
					teamA.increaseTotalPoints();	// Team A gets a point
					losingCharacter = teamB.removeCharacterFromLineup();	// Losing character removed from lineup
					losers.addLoserToStack(losingCharacter);	// Losing character added to loser stack
					teamA.moveWinnerToTail();	// Winning character goes to the back of lineup
				}

			}

		}

		//cout << "\nCurrent lineups are as follows:" << endl;
		//teamA.printLineup();
		//cout << "\n";
		//teamB.printLineup();

		//cout << "\nCurrent scores are as follows:" << endl;
		//cout << "Team A: " << teamA.getTotalPoints() << endl;
		//cout << "Team B: " << teamB.getTotalPoints() << endl;

		cout << "\nThe round is over! Please press enter to continue...";
		cin.get();

		roundNumber++;
		bothCharactersAlive = true;		// this gets reset for the next battle
	}

	cout << "\nFinal results from the tournament:" << endl;
	cout << "Team A ended with: " << teamA.getTotalPoints() << " points" << endl;
	cout << "Team B ended with: " << teamB.getTotalPoints() << " points" << endl;

	if (teamA.getTotalPoints() > teamB.getTotalPoints())
	{
		cout << "\nThis means that Team A is the winner!" << endl;
	}

	else if (teamB.getTotalPoints() > teamA.getTotalPoints())
	{
		cout << "\nThis means that Team B is the winner!" << endl;
	}

	else if (teamA.getTotalPoints() == teamB.getTotalPoints())
	{
		cout << "\nThe tournament ends in a tie!" << endl;
	}

	cout << "\nWould you like to display the contents of the loser pile?" << endl;
	cout << "\n1. Yes" << endl;
	cout << "2. No" << endl;
	
	getline(cin, wantsToPrintLosers);
	while (wantsToPrintLosers.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, wantsToPrintLosers);
	}

	wantsToPrintLosersValidated = inputValidationContinueMenu(wantsToPrintLosers);

	// If they wanted to print the losers
	if (wantsToPrintLosersValidated == 1)
	{
		losers.printLoserStack();
	}

}