/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the various input validation functions
used by the program. Please see below for more specifics.
******************************************************************************************/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::stoi;


/******************************************************************************************
** Description: inputValidationCharacterSelect is called when the user selects a character
from the beginning menus. The final data must be an integer and between 1 and 5. It 
accepts the user input as a string, and first checks that something was actually entered.
If not, the user is re-prompted. It then checks that all characters entered are digits. 
If not, the user is re-prompted. If they are all digits then the string is converted to
an integer via stoi. It is then checked to make sure it is in the appropriate range,
and finally, is returned to the calling function if everything is ok.
******************************************************************************************/

int inputValidationCharacterSelect(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}


		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error, this was not a correct integer. It must be between 1 and 5." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData < 1 || checkedData > 5)
			{
				cout << "Error, this integer was not in range. It must be between 1 and 5." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;
}


/******************************************************************************************
** Description: inputValidationContinueMenu is called when the user selects whether or
not to continue after the tournament has ended. It is also used anytime the final data
must be an integer and the final value should be 1 or 2. It accepts the user input as a 
string, and first checks that something was actually entered. If not, the user is 
re-prompted. It then checks that all characters entered are digits. If not, the user is 
re-prompted. If they are all digits then the string is converted to an integer via stoi. 
It is then checked to make sure it is in the appropriate range, and finally, is returned 
to the calling function if everything is ok.
******************************************************************************************/

int inputValidationContinueMenu(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}


		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error, this was not a correct integer. It must be 1 or 2." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData < 1 || checkedData > 2)
			{
				cout << "Error, this integer was not in range. It must be 1 or 2." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;
}


/******************************************************************************************
** Description: inputValidationRosterSize is called when the user selects the size of
the lineup for each team. The final value must be an integer and be 1 or larger. 
It accepts the user input as a string, and first checks that something was actually 
entered. If not, the user is re-prompted. It then checks that all characters entered are 
digits. If not, the user is re-prompted. If they are all digits then the string is 
converted to an integer via stoi. It is then checked to make sure it is in the appropriate 
range, and finally, is returned to the calling function if everything is ok.
******************************************************************************************/

int inputValidationRosterSize(string dataToCheck)
{
	bool validSentinel = false;
	int checkedData;

	while (validSentinel == false)
	{
		bool allDigits = true;

		while (dataToCheck.empty())
		{
			cout << "No data input. Try again." << endl;
			getline(cin, dataToCheck);
		}


		for (unsigned int count = 0; count < dataToCheck.length(); count++)
		{
			if (!isdigit(dataToCheck[count]))
			{
				allDigits = false;
			}

		}


		if (allDigits == false)
		{
			cout << "Error, this was not a correct integer. It must be at least 1." << endl;
			getline(cin, dataToCheck);
		}

		else if (allDigits == true)
		{
			checkedData = stoi(dataToCheck);

			if (checkedData < 1)
			{
				cout << "Error, this integer was not in range. It must be at least 1." << endl;
				getline(cin, dataToCheck);
			}

			else
			{
				validSentinel = true;
			}
		}

	}

	return checkedData;
}