// Gal elefersy 315850008
#pragma once
#include<iostream>
#ifndef _btree_h
#define _btree_h
class LinkedList;

struct node
{
	int key_value;
	node *left;
	node *right;
};

using namespace std;

class btree
{
	friend class LinkedList;

private:
	node *root;
	// flag to know if the tree go through miror
	bool mir;
	// help method for the destructor
	void destroyTree(node* root);
	// print tree (in order)
	friend ostream& inorder(ostream& os, node* leaf);
	// help to return the depth of tree
	int getTreeDepth(node* leaf, int depth);
	// find max between 3 number
	int max(int num1, int num2, int num3);
	// insert num into the tree
	void insert(node* &root, int key);
	// insert num into the tree if miror activated
	void insertMirror(node* &root, int key);
	// create new node
	node* createNewNode(int key);
	// help to copy Constructor by tree
	node* copy(const node *toCopy);
	// reverse the tree
	void mirror(node* leaf);
	//help method to return arrays of LinkedList of the trees levels
	void Tree2linkListbyDepth(LinkedList* arr, node* leaf, int i);
	
public:
	// Default constructor
	btree();
	// destructor
	~btree();

	// Copy Constructor by list
	btree(LinkedList & list);

	// Copy Constructor by tree
	btree(btree & bt);

	// assignment operator from linked list
	btree & operator=(const LinkedList & ls);

	// assignment operator from tree
	btree& operator=(const btree &bt);

	// insert new value to binary tree
	void insert(int key);

	// reverse the tree
	void mirror();

	//return arrays of LinkedList of the trees levels
	LinkedList* Tree2linkListbyDepth();
	// return the depth of tree
	int getTreeDepth();

	// print tree (in order)
	friend ostream& operator<<(ostream& os, btree& dt);
};
#endif