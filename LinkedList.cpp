// Gal elefersy 315850008
#include "LinkedList.h"
#include "btree.h"
#include<iostream>
using namespace std;
// Default constructor
LinkedList::LinkedList() {
	length = 0;
	head = NULL;
}
// destructor
LinkedList::~LinkedList() {
	length = 0;
	Node* temp = head;
	Node* cur = NULL;
	while (temp != NULL) {
		cur = temp;
		temp = temp->next;

		delete cur;
	}
}
// add numner in the start of the list
void LinkedList::add(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	
	if (head == NULL) {
		head = newNode;
		length++;
		return;
	}
	newNode->next = head;
	head = newNode;
	length++;
}
// Copy Constructor by list
LinkedList::LinkedList(LinkedList &bt) {
	head = NULL;
	if (bt.head == NULL) {
		head = bt.head;
		return;
	}
	Node *temp = bt.head;
	while (temp != NULL) {
		this->insertAtEnd(temp->data);
		temp = temp->next;
	}
}
// Copy Constructor by tree
LinkedList::LinkedList(btree &bt) {
	goToLocation(bt.root);
}
// help method to copy bianry tree into list
void LinkedList::goToLocation(node* leaf) {
	if (leaf->left != NULL) {
		goToLocation(leaf->left);
	}
	add(leaf->key_value);
	if (leaf->right != NULL) {
		goToLocation(leaf->right);
	}
}
// print list
ostream& operator<<(ostream& os, LinkedList& l) {
	Node* temp = l.head;
	os << "List:(";
	for (int i = 0; i < l.length; ++i) {
		os << temp->data << ",";
		temp = temp->next;
	}
	os << ")" << endl;
	return os;
}
// insert in the end of the list
void LinkedList::insertAtEnd(int data) {
	Node* node = new Node();
	node->data = data;
	node->next = NULL;
	if (head == NULL) {
		head = node;
		length++;
		return;
	}
	Node* cur = head;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = node;
	length++;
}
// assignment operator from linked list
LinkedList& LinkedList::operator=(const LinkedList& bt) {
	if (this->head == bt.head) {
		return *this;
	}
	Node* temp = head;
	Node* cur = NULL;
	while (temp != NULL) {
		cur = temp;
		temp = temp->next;
		delete cur;
	}
	length = 0;
	if (bt.length == 0) {
		return *this;
	}
	this->head = NULL;
	Node* copy = bt.head;
	for (int i = 0; i < bt.length; i++) {
		this->insertAtEnd(copy->data);
		copy = copy->next;
	}
	return *this;
}
// assignment operator from bianry tree
LinkedList& LinkedList::operator=(const btree &bt) {
	Node* temp = head;
	Node* cur = NULL;
	while (temp != NULL) {
		cur = temp;
		temp = temp->next;
		delete cur;
	}
	length = 0;
	if (bt.root == NULL) {
		return *this;
	}
	goToLocation(bt.root);
	return *this;
}