
void MainCPP() {
#include "ListOfInts.h"
#include "NodeofInt.h"
#include <iostream>

using namespace std;

	ListOfInts s;
	s.insertBack(3);
	s.insertBack(5);
	s.insertBack(7);

	s.displayList();
}

void NodeOfIntH() {
#pragma once
#include "ListOfInts.h"

using namespace std;

class NodeofInt {
	friend class ListOfInts;
private:
	int theValue;
	NodeofInt *next;

public:
	NodeofInt();
};
typedef struct NodeofInt* nodePtr;
}

void NodeOfIntCPP() {
#include "NodeofInt.h"

using namespace std;

NodeofInt::NodeofInt() {

	// Constructor

}
}

void ListOfIntsH() {
#pragma once
#include "NodeofInt.h"

using namespace std;

class ListOfInts {
	friend class NodeofInt;

private:
	nodePtr head;

public:
	ListOfInts();
	void insertBack(int a);
	void displayList();
	int deleteMostRecent();
	~ListOfInts();
};


}

void ListOfIntsCPP() {
#include "ListOfInts.h"
#include <iostream>

using namespace std;

ListOfInts::ListOfInts()
	:head(NULL){
	
	// Constructor
	cout << "ListOfInts Constructor\n";

}

ListOfInts::~ListOfInts() {

	// Deconstructor
	cout << "ListOfInts Deconstructor\n";

}

void ListOfInts::insertBack(int a) {

	// Insert back Function
	nodePtr newNode = new NodeofInt;
	newNode->next = NULL;
	newNode->theValue = a;

	nodePtr tempPtr;

	if (head != NULL) {
		head = newNode;
	}
	else
	{
		for (tempPtr = head; tempPtr->next; tempPtr = tempPtr->next);
		tempPtr->next = newNode;
	}

}

void ListOfInts::displayList() 
{
	// Display list function
	nodePtr tempptr = head;

	while (tempptr != NULL) 
	{
		cout << tempptr->theValue << endl;
		tempptr = tempptr->next;
	}
}

int ListOfInts::deleteMostRecent() {

	// Delete Most Recent Function
	nodePtr delPtr = NULL;
	nodePtr current = NULL;
	nodePtr temp = NULL;

	temp = head;
	current = head;

	while (current != NULL) {
		temp = current;
		current = current->next;

	}
	if (current == NULL) {
		cout << "There is no list\n";
		delete delPtr;
	}
	else {
		delPtr = current;
		current = current->next;
		temp->next = current;
		delete delPtr;
		cout << " The value " << current << "Has been deleted \n";

	}
}

}

