// Program to find ceil of a given value in BST 
#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has key, left child and right child */
struct node { 
	int key; 
	struct node* left; 
	struct node* right; 
}; 

/* Helper function that allocates a new node with the given key and 
NULL left and right pointers.*/
struct node* newNode(int key) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	return (node); 
} 

// Function to find ceil of a given input in BST. If input is more 
// than the max key in BST, return -1 
int Ceil(struct node* root, int input) 
{ 
	// Base case 
	if (root == NULL) 
		return -1; 

	// We found equal key 
	if (root->key == input) 
		return root->key; 

	// If root's key is smaller, ceil must be in right subtree 
	if (root->key < input) 
		return Ceil(root->right, input); 

	// Else, either left subtree or root has the ceil value 
	int ceil = Ceil(root->left, input); 
	return (ceil >= input) ? ceil : root->key; 
} 

// Driver program to test above function 
int main() 
{ 
	struct node* root = newNode(8); 

	root->left = newNode(4); 
	root->right = newNode(12); 

	root->left->left = newNode(2); 
	root->left->right = newNode(6); 

	root->right->left = newNode(10); 
	root->right->right = newNode(14); 

	for (int i = 0; i < 16; i++) 
		printf("%d %d\n", i, Ceil(root, i)); 

	return 0; 
} 

