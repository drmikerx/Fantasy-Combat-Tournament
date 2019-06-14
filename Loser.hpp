/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the header file for the LoserStack class. The class uses structs
called LoserNodes for its nodes. Each LoserNode has a Character* that points to a losing
character and a successor pointer that points to the next node in the stack. The LoserNode
constructor handles the assignment of the losingFighter and next variables.
The LoserStack only has one member variable; a LoserNode pointer that points to the head
of the stack. The class was set up as a singly linked stack so the list of losers could
easily be printed from top to bottom if the user wants to view it. The LoserStack
constructor sets head to nullptr to symbolize an empty stack to begin with. Please see
the implementation file for more details about the member functions of this class.
******************************************************************************************/


#ifndef LOSER_HPP
#define LOSER_HPP

#include "Character.hpp"

class LoserStack
{
private:

	struct LoserNode
	{
		Character* losingFighter;
		LoserNode* next;

		LoserNode(Character* characterLost, LoserNode* next1 = nullptr)
		{
			losingFighter = characterLost;
			next = next1;
		}
	};

	LoserNode* head;

public:

	LoserStack()
	{
		head = nullptr;		// Empty list at the start
	}

	void addLoserToStack(Character*);
	void printLoserStack();

	bool isEmpty();

	void resetStack();

	~LoserStack();

};


#endif