/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the various menu functions used in
the program. Please see below for more specific details.
******************************************************************************************/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int inputValidationCharacterSelect(string dataToCheck);
int inputValidationContinueMenu(string dataToCheck);


/******************************************************************************************
** Description: The startMenu function is called once at the very beginning of the
program and asks the user if they want to play or exit. User input is validated and the
integer they chose (either 1 or 2) is returned to the calling function.
******************************************************************************************/

int startMenu()
{
	string userChoice;
	int userChoiceValidated;

	cout << "Welcome to Fantasy Combat Tournament!" << endl;
	cout << "\n1. Play" << endl;
	cout << "2. Exit" << endl;

	getline(cin, userChoice);
	while (userChoice.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, userChoice);
	}

	userChoiceValidated = inputValidationContinueMenu(userChoice);

	return userChoiceValidated;

}


/******************************************************************************************
** Description: The characterSelectMenu is called each time the user is asked what type of
character they want their fighter to be. Once the user has made a choice, it is run 
through input validation to ensure that it is an integer between 1 and 5. The function 
then returns the validated integer to the calling function.
******************************************************************************************/

int characterSelectMenu()
{
	string choiceCharacter;
	int choiceCharacterValidated;

	cout << "\n1. Vampire" << endl;
	cout << "2. Barbarian" << endl;
	cout << "3. Blue Men" << endl;
	cout << "4. Medusa" << endl;
	cout << "5. Harry Potter" << endl;

	getline(cin, choiceCharacter);
	while (choiceCharacter.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, choiceCharacter);
	}

	choiceCharacterValidated = inputValidationCharacterSelect(choiceCharacter);

	return choiceCharacterValidated;
}


/******************************************************************************************
** Description: continueMenu is called at the end of the tournament when a team 
has won. It asks the user whether they would like to continue. User choice is sent
through input validation to ensure that it is an integer and either 1 or 2. If user
selects 1, the function returns true so the do-while loop controlling the tournament
will continue. Otherwise, it returns false so the do-while loop will end and the
program will terminate.
******************************************************************************************/

bool continueMenu()
{
	string continueChoice;
	int continueChoiceValidated;

	cout << "\nThe game has ended. Please choose one of the following:" << endl;
	cout << "\n1. Play again" << endl;
	cout << "2. Exit" << endl;

	getline(cin, continueChoice);
	while (continueChoice.empty())
	{
		cout << "No data input. Try again." << endl;
		getline(cin, continueChoice);
	}

	continueChoiceValidated = inputValidationContinueMenu(continueChoice);

	if (continueChoiceValidated == 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}