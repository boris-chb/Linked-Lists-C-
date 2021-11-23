void MainCPP() {
#include "ListOfBooks.h"
#include <iostream>

using namespace std;

int main() {
	ListOfBooks list;
	Book a;
	a.setIsbn(2);
	a.setString("Second book");
	Book b;
	b.setIsbn(3);
	b.setString("Third Book");
	list.insertBack(a);
	list.insertBack(b);
	list.displayList();

	return 0;
}
}

void BookH() {
#pragma once
#include <string>
#include "NodeOfBook.h"
#include "ListOfBooks.h"

using namespace std;

class Book {
	friend class NodeOfBook;
	friend class ListOfBooks;
private:
	int isbn;
	string title;
public:
	int getIsbn();
	string getTitle();
	void setIsbn(int a);
	void setString(string a);
};

}

void BookCPP() {
#include "Book.h"
#include <iostream>
#include <string>

using namespace std;


Book::Book() {
	cout << "Making 1 book for da list\n";
	int isbn = 0;
	string title = "title";
}

void Book::setString(string a) {
	title = a;
}

void Book::setIsbn(int a) {
	isbn = a;
}

string Book::getTitle() {
	return title;
}

int Book::getIsbn() {
	return isbn;
}

Book::~Book() {
	cout << "Deleteing 1 book for da list\n";
}
}

void NodeofBookH() {
#pragma once
#include "Book.h"
#include "ListOfBooks.h"
#include <string>


class NodeOfBook {
	friend class Book;

private:
	Book theBook;
	NodeOfBook* next;
public:
	NodeOfBook();
};
}

void NodeofBookCPP() {
#include "NodeOfBook.h"

NodeOfBook::NodeOfBook(){
	next = nullptr;
	theBook.setString("First Book");
	theBook.setIsbn(1);
}
}

void ListOfBooksH() {
#pragma once
#include "NodeOfBook.h"
#include "Book.h"


using namespace std;

class ListOfBooks {
	friend class NodeOfBook;
	friend class Book;
private:
	NodeOfBook* head;
public:
	ListOfBooks();
	void insertBack(Book a);
	void displayList();
	int deleteMostRecent();
	~ListOfBooks();
};
}

void ListOfBooksCPP() {
#include "ListOfBooks.h"
#include <iostream>

using namespace std;

ListOfBooks::ListOfBooks():head(NULL){
	cout << "Linked List constructor\n";


}

ListOfBooks::~ListOfBooks(){


	cout << "Linked List Deconstructor\n";

}

void ListOfBooks::insertBack(Book a) {
	NodeOfBook* n = new NodeOfBook;
	n->next = NULL;
	n->theBook = a;
	NodeOfBook* tempPtr;

	if (head != NULL) {
		tempPtr = head;
		while (tempPtr != NULL) {
			tempPtr = tempPtr->next;
		}

		tempPtr->next = n;
	}

	else {
		head = n;
	}

}

int ListOfBooks::deleteMostRecent() {
	NodeOfBook* deletePntr = NULL;
	NodeOfBook* tempPtr;
	NodeOfBook* crntPtr;
	tempPtr = head;
	crntPtr = head;
	if (head == NULL) {
		cout << "Linked List is empty";
		delete deletePntr;
		return 0;
	}
	while (crntPtr != NULL) {
		tempPtr = crntPtr;
		crntPtr = crntPtr->next;
	}
	deletePntr = crntPtr;
	crntPtr = crntPtr->next;
	tempPtr->next = crntPtr;
	delete deletePntr;

}

void ListOfBooks::displayList() {
	NodeOfBook* crntPtr = head;

	while (crntPtr != NULL)
	{
		cout << crntPtr->theBook.getTitle() << endl;
		crntPtr = crntPtr->next;
	}
}
}

