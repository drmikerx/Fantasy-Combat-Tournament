/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the LoserStack class. Please see
below for specifics about the class member functions.
******************************************************************************************/


#include "Loser.hpp"

#include <iostream>
using std::cout;
using std::endl;


/******************************************************************************************
** Description: addLoserToStack is called after a fighter has lost the round and has been
removed from their team lineup. It accepts the Character* returned from the 
removeCharacterFromLineup function and creates a new LoserNode object that stores this
Character*. The new node gets added to the head of the stack so that the most recently
defeated fighter is on top and the first defeated fighter is on the bottom.
******************************************************************************************/

// Adds new nodes to the top of the stack
void LoserStack::addLoserToStack(Character* characterThatLost)
{
	if (isEmpty())
	{
		head = new LoserNode(characterThatLost);
	}

	// There's at least one node in the stack already
	else
	{
		head = new LoserNode(characterThatLost, head);
		// Head points to a new node that stores the character and the new node points to the prevous head
	}
}


/******************************************************************************************
** Description: printLoserStack gets called if the user chooses to display the contents
of the loser stack after the tournament ends. It accesses each defeated character's
characterType and characterName variables so the user can visualize the order the
characters were defeated in.
******************************************************************************************/

void LoserStack::printLoserStack()
{
	if (isEmpty())
	{
		//cout << "\nThe loser stack is empty! Nothing to print!" << endl;
	}

	// If there's at least one node in the stack
	else
	{
		cout << "\nThe loser stack contains the following characters: " << endl;
		LoserNode* nodePtr = head;

		cout << nodePtr->losingFighter->getCharacterType() << " : " 
			<< nodePtr->losingFighter->getCharacterName() << endl;

		nodePtr = nodePtr->next;

		while (nodePtr != nullptr)
		{
			cout << nodePtr->losingFighter->getCharacterType() << " : "
				<< nodePtr->losingFighter->getCharacterName() << endl;

			nodePtr = nodePtr->next;
		}
		
	}
}


/******************************************************************************************
** Description: isEmpty is used throughout the other class member functions to make sure
there are elements in the stack before dereferencing any pointers so as to avoid
segmentation faults. It returns true if the stack is empty and false otherwise.
******************************************************************************************/

bool LoserStack::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}

	else
	{
		return false;
	}
}


/******************************************************************************************
** Description: resetStack gets called at the end of each tournament in case the user
wants to reset the game. The LoserStack destructor is called to make sure all the memory 
from the previous tournament is freed.
******************************************************************************************/

void LoserStack::resetStack()
{
	this->~LoserStack();
}


/******************************************************************************************
** Description: The LoserStack destructor is responsible for freeing all dynamic memory 
used by the fighters and nodes in the LoserStack class. It first makes sure to free all 
character objects that the nodes point to. After this is done, it frees all of the 
LoserNode objects so there are no memory leaks.
******************************************************************************************/

LoserStack::~LoserStack()
{
	// Step through each node of the queue and first free the Character object pointed to
	if (isEmpty())
	{
		// don't need to do anything since there are no nodes
	}

	// We know there's at least one node in the queue
	else
	{
		LoserNode* nodePtr;
		nodePtr = head;

		delete nodePtr->losingFighter;	// Free the character object
		nodePtr = nodePtr->next;

		while (nodePtr != nullptr)	// Once nullptr is reached it's the end of the queue
		{
			delete nodePtr->losingFighter;
			nodePtr = nodePtr->next;
		}

		// At this point all characters have been freed, now free the RosterNodes

		LoserNode* garbage;

		garbage = head;

		while (head != nullptr)
		{
			head = head->next;
			delete garbage;
			garbage = head;
		}

		head = nullptr;
	}
}