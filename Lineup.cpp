/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the implementation file for the Lineup class. Please see below
for specific details about the various member functions.
******************************************************************************************/


#include "Lineup.hpp"

#include <iostream>
using std::cout;
using std::endl;


/******************************************************************************************
** Description: addCharacterToLineup accepts a Character* as a parameter. It then creates
a new RosterNode object and stores this Character* inside the node and adds it to the
linked list queue. Each new node is added to the tail of the queue.
******************************************************************************************/

void Lineup::addCharacterToLineup(Character* characterToAdd)
{
	if (isEmpty())
	{
		head = new RosterNode(characterToAdd);
		tail = head;
	}


	// If there was at least one element in the list to begin with
	else
	{
		tail->next = new RosterNode(characterToAdd);
		tail = tail->next;
	}
}


/******************************************************************************************
** Description: removeCharacterFromLineup is called when a character loses a fight. It
deletes the node where the Character* is located and frees the dynamic memory. It returns
the Character* of the losing character to the calling function so that it can be added to
the loser stack.
******************************************************************************************/

// if character at head of list loses, it moves to the loser pile
Character* Lineup::removeCharacterFromLineup()
{
	if (isEmpty())
	{
		//cout << "Lineup is empty! Nothing to remove!" << endl;
		return nullptr;
	}

	// If there's only one node in the lineup
	else if (!isEmpty() && head == tail)
	{
		Character* losingCharacter;

		losingCharacter = head->fighter;
		delete head;
		head = nullptr;
		tail = nullptr;

		return losingCharacter;
	}

	else
	{
		// If there's at least two nodes in the lineup
		
		Character* losingCharacter;
		RosterNode* garbage;

		// Losing character will always be at the head of the lineup
		losingCharacter = head->fighter;
		garbage = head;
		head = head->next;
		delete garbage;

		return losingCharacter;
	}

}


/******************************************************************************************
** Description: increaseTotalPoints is called when a team wins a round. Their totalPoints
variable is increased by 1.
******************************************************************************************/

void Lineup::increaseTotalPoints()
{
	this->totalPoints++;
}


/******************************************************************************************
** Description: getTotalPoints returns the integer value currently stored in the
totalPoints member variable.
******************************************************************************************/

int Lineup::getTotalPoints()
{
	return totalPoints;
}


/******************************************************************************************
** Description: getHeadPtr function returns the RosterNode* that is currently at the head
of the queue. This node contains the fighter that is to battle.
******************************************************************************************/

RosterNode* Lineup::getHeadPtr()
{
	return head;
}


/******************************************************************************************
** Description: isEmpty is used throughout the other class member functions to make sure
there are elements in the queue before dereferencing any pointers so as to avoid
segmentation faults. It returns true if the queue is empty and false otherwise.
******************************************************************************************/

bool Lineup::isEmpty()
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}

	else
	{
		return false;
	}
}


/******************************************************************************************
** Description: moveWinnerToTail is called after a character has won a battle. It causes
the current head node to become the new tail node so that the next node in line becomes
the new head node, and the next fighter in the queue participates in the next round of
the tournament.
******************************************************************************************/

void Lineup::moveWinnerToTail()
{
	if (isEmpty())
	{
		//cout << "The lineup is empty! Nothing to move!" << endl;
	}

	// If there is only one node in the lineup
	else if (!isEmpty() && head == tail)
	{
		// Don't need to do anything because there's no different node to put at front
		//cout << "Only one character in lineup! The winner stays put!" << endl;
	}

	// If there's two nodes still in the lineup
	else if (head->next == tail)
	{
		RosterNode* tempPtr = tail;
		tempPtr->next = head;		// tail becomes the new head
		head->next = nullptr;		// head becomes the new tail
		tail = head;
		head = tempPtr;
	}

	// If there's more than two nodes left in the lineup
	else
	{
		RosterNode* tempPtr = head;
		tail->next = head;
		head = head->next;
		tempPtr->next = nullptr;
		tail = tail->next;
	}
}


/******************************************************************************************
** Description: resetLineup gets called at the end of each tournament in case the user
wants to reset the game. Total points get set back to 0, and the Lineup destructor is
called to make sure all the memory from the previous tournament is freed.
******************************************************************************************/

void Lineup::resetLineup()
{
	this->totalPoints = 0;
	this->~Lineup();
}


/******************************************************************************************
** Description: Though printLineup was not used in the final design, it was used throughout
the testing process so it was kept in the program.
******************************************************************************************/

void Lineup::printLineup()
{
	if (isEmpty())
	{
		//cout << "The lineup is empty! Nothing to print!" << endl;
	}

	else
	{
		RosterNode* nodePtr = head;

		// We know there's at least one node

		//cout << nodePtr->fighter->getCharacterName() << " is in the roster!" << endl;
		nodePtr = nodePtr->next;

		while (nodePtr != nullptr)
		{
			//cout << nodePtr->fighter->getCharacterName() << " is in the roster!" << endl;
			nodePtr = nodePtr->next;
		}
	}
}


/******************************************************************************************
** Description: The Lineup destructor is responsible for freeing all dynamic memory used
by the fighters and nodes in each Lineup class. It first makes sure to free all character
objects that the nodes point to. After this is done, it frees all of the RosterNode
objects so there are no memory leaks.
******************************************************************************************/

Lineup::~Lineup()
{
	// Step through each node of the queue and first free the Character object pointed to
	if (isEmpty())
	{
		// don't need to do anything since there are no nodes
	}

	// We know there's at least one node in the queue
	else
	{
		RosterNode* nodePtr;
		nodePtr = head;

		delete nodePtr->fighter;	// Free the character object
		nodePtr = nodePtr->next;

		while (nodePtr != nullptr)	// Once nullptr is reached it's the end of the queue
		{
			delete nodePtr->fighter;
			nodePtr = nodePtr->next;
		}

		// At this point all characters have been freed, now free the RosterNodes

		RosterNode* garbage;

		garbage = head;

		while (head != nullptr)
		{
			head = head->next;
			delete garbage;
			garbage = head;
		}

		head = nullptr;
		tail = nullptr;
	}
}
