// Gal elefersy 315850008
#include "btree.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
btree::btree() {
	root = NULL;
	mir = false;
}
// destructor
btree::~btree() {
	destroyTree(root);
}
// help method for the destructor
void btree::destroyTree(node* leaf) {
	if (leaf != NULL) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}
// Copy Constructor by list
btree::btree(LinkedList& list) {
	if (list.head == NULL) {
		return;
	}
	Node* temp = list.head;
	while (temp != NULL) {
		insert(temp->data);
		temp = temp->next;
	}
	mir = false;
}
// Copy Constructor by tree
btree::btree(btree &bt) {
	mir = bt.mir;
	root = copy(bt.root);
}
// help to copy Constructor by tree
node* btree::copy(const node *leaf) {
	if (leaf == NULL) {
		return NULL;
	}
	node* copyTree = new node();
	copyTree->key_value = leaf->key_value;
	copyTree->left = copy(leaf->left);
	copyTree->right = copy(leaf->right);
	return copyTree;
}
// return the depth of tree
int btree::getTreeDepth() {
	if (root == NULL) {
		return 0;
	}
	return getTreeDepth(root, 1);
}
int btree::getTreeDepth(node* leaf, int depth) {
	int bigger = 0;
	if (leaf->left == NULL && leaf->right == NULL) {
		return depth;
	}
	if (leaf->left != NULL) {
		bigger = max(getTreeDepth(leaf->left, depth + 1), depth, bigger);
	}
	if (leaf->right != NULL) {
		bigger = max(getTreeDepth(leaf->right, depth + 1), depth, bigger);
	}
	return bigger;
}
int btree::max(int num1, int num2, int num3) {
	if (num1 >= num2 && num1 >= num3) {
		return num1;
	}else if (num2 >= num1 && num2 >= num3) {
		return num2;
	}else {
		return num3;
	}
}
// print tree (in order)
ostream& inorder(ostream& os, node* leaf) {
	if (leaf == NULL) {
		return os;
	}
	inorder(os, leaf->left);
	os << leaf->key_value << ",";
	inorder(os, leaf->right);
	return os;
}
ostream& operator<<(ostream& os, btree& dt){
	os << "Tree:";
	return inorder(os, dt.root) << endl;
}
// reverse the tree
void btree::mirror() {
	mir = !mir;
	mirror(root);
}
void btree::mirror(node* leaf) {
	if (leaf == NULL) {
		return;
	}
	mirror(leaf->left);
	mirror(leaf->right);
	node* temp = leaf->left;
	leaf->left = leaf->right;
	leaf->right = temp;
}
// insert new value to binary tree
node* btree::createNewNode(int key) {
	node* temp = new node;
	temp->key_value = key;
	temp->left = temp->right = NULL;
	return temp;
}
void btree::insert(node* &leaf, int key) {
	if (leaf == NULL) {
		leaf = createNewNode(key);
		return;
	}
	if (key < leaf->key_value) {
		insert(leaf->left, key);
	}else {
		insert(leaf->right, key);
	}
}
void btree::insertMirror(node* &leaf, int key) {
	if (leaf == NULL) {
		leaf = createNewNode(key);
		return;
	}
	if (key >= leaf->key_value) {
		insertMirror(leaf->left, key);
	}else {
		insertMirror(leaf->right, key);
	}
}
void btree::insert(int key) {
	if (mir == false) {
		insert(root, key);
	}else {
		insertMirror(root, key);
	}
}
// return arrays of LinkedList of the trees levels
LinkedList* btree::Tree2linkListbyDepth() {
	LinkedList* arr = new LinkedList[getTreeDepth()];
	if (root == NULL) {
		return arr;
	}
	int i = 0;
	Tree2linkListbyDepth(arr, root, i);
	return arr;
}
void btree::Tree2linkListbyDepth(LinkedList* arr, node* leaf, int i) {
	if (leaf == NULL) {
		return;
	}
	arr[i].add(leaf->key_value);
	Tree2linkListbyDepth(arr, leaf->left, i + 1);
	Tree2linkListbyDepth(arr, leaf->right, i + 1);
}
// assignment operator from linked list
btree & btree::operator=(const LinkedList& ls) {
	destroyTree(this->root);
	this->root = NULL;
	if (ls.head == NULL) {
		return *this;
	}
	Node* temp = ls.head;
	while (temp != NULL) {
		insert(temp->data);
		temp = temp->next;
	}
	this->mir = false;
	return *this;
}
// assignment operator from tree
btree & btree::operator=(const btree& bt) {
	if (this->root == bt.root) {
		return *this;
	}
	destroyTree(this->root);
	this->root = NULL;
	this->mir = bt.mir;
	if (bt.root == NULL) {
		return *this;
	}
	this->root = copy(bt.root);
	return *this;
}