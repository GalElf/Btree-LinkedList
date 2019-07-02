// Gal elefersy 315850008
#pragma once
#include<iostream>
#ifndef _LinkedList_h
#define _LinkedList_h
class btree;

class Node
{
public:
	Node* next;
	int data;
};

using namespace std;

class LinkedList
{
	friend class btree;

private:
	// insert in the end of the list
	void insertAtEnd(int data);
	// help method to copy bianry tree into list
	void goToLocation(struct node* leaf);

public:
	int length;
	Node* head;

	// Copy Constructor by list
	LinkedList(btree &bt);
	// Copy Constructor by tree
	LinkedList(LinkedList &bt);

	// Default constructor
	LinkedList();
	// destructor
	~LinkedList();
	// add numner in the start of the list
	void add(int data);
	// assignment operator from linked list
	LinkedList& operator=(const LinkedList& bt);
	// assignment operator from bianry tree
	LinkedList& operator=(const btree &bt);
	// print list
	friend ostream& operator<<(ostream& os, LinkedList& l);
};
#endif