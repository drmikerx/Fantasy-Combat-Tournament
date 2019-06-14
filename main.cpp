/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the main function for the Fantasy Combat Tournament program. It
is primarily responsible for gathering all preliminary data from the user so it can be
sent to the runBattles function where the actual tournament takes place. It starts by
asking the user if they want to play. If they select 1, the game starts, otherwise, the
program immediately ends. The bulk of the main function occurs in a do-while loop so the
user can start the game over at the end if they wish. The user is asked for the size they
would like each team to be. After this, the user is asked for the type and name of the
characters to add, and the characters are added to the appropriate team Lineup object.
An empty LoserStack object is also created. The two Lineup objects and the LoserStack
object are sent as arguments to the runBattles function for the rest of the tournament
to take place. Once back in main, the objects are reset to their empty states and the
user is asked if they would like to play again.
******************************************************************************************/


#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "Lineup.hpp"
#include "Loser.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ctime>

#include <string>
using std::string;

int startMenu();
bool continueMenu();
int characterSelectMenu();

int inputValidationRosterSize(string dataToCheck);
Character* generateCharacter(int characterChoice);
void runBattles(Lineup & teamA, Lineup & teamB, LoserStack& losers);


int main()
{
	unsigned seed;         // srand expects an unsigned integer
	seed = time(0);        // seed set to changing value of time
	srand(seed);           // initiating seed in srand

	int userChoiceFromStartMenu;
	bool wantsToPlay;

	Lineup lineupTeamA;
	Lineup lineupTeamB;
	LoserStack stackOfLosers;

	userChoiceFromStartMenu = startMenu();

	if (userChoiceFromStartMenu == 1)
	{
		wantsToPlay = true;
	}

	else if (userChoiceFromStartMenu == 2)
	{
		wantsToPlay = false;
	}


	do
	{
		if (wantsToPlay == true)
		{
			string teamARosterSize;
			int teamARosterSizeValidated;

			string teamBRosterSize;
			int teamBRosterSizeValidated;

			// The main portion of the game can now begin


			// Get Team A roster size
			cout << "\nOk, let's play!" << endl;
			cout << "\nFirst, enter an integer for the number of characters in Team A:" << endl;

			getline(cin, teamARosterSize);
			while (teamARosterSize.empty())
			{
				cout << "No data input. Try again." << endl;
				getline(cin, teamARosterSize);
			}

			teamARosterSizeValidated = inputValidationRosterSize(teamARosterSize);


			// Get Team B roster size
			cout << "\nNow, enter an integer for the number of characters in Team B:" << endl;

			getline(cin, teamBRosterSize);
			while (teamBRosterSize.empty())
			{
				cout << "No data input. Try again." << endl;
				getline(cin, teamBRosterSize);
			}

			teamBRosterSizeValidated = inputValidationRosterSize(teamBRosterSize);


			// Get the Characters input into the roster for Team A

			for (int count = 1; count <= teamARosterSizeValidated; count++)
			{
				int choiceOfCharacter;
				Character* characterToAdd;

				cout << "\nPlease input your choice for Team A Character #" << count << endl;
				choiceOfCharacter = characterSelectMenu();

				characterToAdd = generateCharacter(choiceOfCharacter);

				lineupTeamA.addCharacterToLineup(characterToAdd);

			}

			//lineupTeamA.printLineup();

			// Get Character's put into the roster for Team B

			for (int count = 1; count <= teamBRosterSizeValidated; count++)
			{
				int choiceOfCharacter;
				Character* characterToAdd;

				cout << "\nPlease input your choice for Team B Character #" << count << endl;
				choiceOfCharacter = characterSelectMenu();

				characterToAdd = generateCharacter(choiceOfCharacter);

				lineupTeamB.addCharacterToLineup(characterToAdd);
			}

			//lineupTeamB.printLineup();

			runBattles(lineupTeamA, lineupTeamB, stackOfLosers);

		}

		lineupTeamA.resetLineup();
		lineupTeamB.resetLineup();
		stackOfLosers.resetStack();

	} while (wantsToPlay == true && continueMenu());



	return 0;
}
