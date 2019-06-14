/******************************************************************************************
** Program name: Project 4 - Fantasy Combat Tournament
** Author: Michael Childress
** Date: 5/22/2018
** Description: This is the header file for the Lineup class as well as the file where
the RosterNode structs are declared. Each RosterNode struct has a Character pointer and a
successor pointer that points to the next node in the queue. By design choice, this was
implemented as a singly linked list. The RosterNode constructor handles the assignment of
the fighter and next member variables.
The Lineup class has two RosterNode pointers that point to the head and tail of the queue.
It also has an int member variable called totalPoints that keeps track of the team's score.
The Lineup constructor sets head and tail to nullptr to symbolize an empty queue at the
start, and sets totalPoints to 0 since the team has not scored yet. Each Lineup object 
will represent a team's roster of characters and keep track of the team's score. Please 
see the implementation file for more details about the member functions of this class.
******************************************************************************************/


#ifndef LINEUP_HPP
#define LINEUP_HPP

#include "Character.hpp"

struct RosterNode
{
	Character* fighter;	// points to the fighter "stored inside node"
	RosterNode* next;	// successor pointer

	RosterNode(Character* newFighter, RosterNode* next1 = nullptr)
	{
		fighter = newFighter;
		next = next1;
	}
};


class Lineup
{
private:
	
	RosterNode* head;	// points to first node in the queue
	RosterNode* tail;	// points to the last node in the queue
	int totalPoints;


public:
	Lineup()
	{
		head = nullptr;		// Queue starts empty when class object is made
		tail = nullptr;		// Queue starts empty when class object is made
		totalPoints = 0;
	}

	void addCharacterToLineup(Character*);
	Character* removeCharacterFromLineup();

	void increaseTotalPoints();
	int getTotalPoints();

	RosterNode* getHeadPtr();

	bool isEmpty();

	void moveWinnerToTail();

	void resetLineup();

	void printLineup();		// FOR TESTING!

	~Lineup();

};



#endif