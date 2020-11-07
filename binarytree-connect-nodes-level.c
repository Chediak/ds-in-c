// C program to connect nodes at same level using extended 
// pre-order traversal 
#include <stdio.h> 
#include <stdlib.h> 

struct node { 
	int data; 
	struct node* left; 
	struct node* right; 
	struct node* nextRight; 
}; 

void connectRecur(struct node* p); 

// Sets the nextRight of root and calls connectRecur() 
// for other nodes 
void connect(struct node* p) 
{ 
	// Set the nextRight for root 
	p->nextRight = NULL; 

	// Set the next right for rest of the nodes 
	// (other than root) 
	connectRecur(p); 
} 

/* Set next right of all descendents of p. 
Assumption: p is a compete binary tree */
void connectRecur(struct node* p) 
{ 
	// Base case 
	if (!p) 
		return; 

	// Set the nextRight pointer for p's left child 
	if (p->left) 
		p->left->nextRight = p->right; 

	// Set the nextRight pointer for p's right child 
	// p->nextRight will be NULL if p is the right 
	// most child at its level 
	if (p->right) 
		p->right->nextRight = (p->nextRight) ? p->nextRight->left : NULL; 

	// Set nextRight for other nodes in pre order fashion 
	connectRecur(p->left); 
	connectRecur(p->right); 
} 

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newnode(int data) 
{ 
	struct node* node = (struct node*) 
		malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	node->nextRight = NULL; 

	return (node); 
} 

/* Driver program to test above functions*/
int main() 
{ 

	/* Constructed binary tree is 
			10 
		/ \ 
		8	 2 
	/ 
	3 
*/
	struct node* root = newnode(10); 
	root->left = newnode(8); 
	root->right = newnode(2); 
	root->left->left = newnode(3); 

	// Populates nextRight pointer in all nodes 
	connect(root); 

	// Let us check the values of nextRight pointers 
	printf("Following are populated nextRight pointers in the tree "
		"(-1 is printed if there is no nextRight) \n"); 
	printf("nextRight of %d is %d \n", root->data, 
		root->nextRight ? root->nextRight->data : -1); 
	printf("nextRight of %d is %d \n", root->left->data, 
		root->left->nextRight ? root->left->nextRight->data : -1); 
	printf("nextRight of %d is %d \n", root->right->data, 
		root->right->nextRight ? root->right->nextRight->data : -1); 
	printf("nextRight of %d is %d \n", root->left->left->data, 
		root->left->left->nextRight ? root->left->left->nextRight->data : -1); 
	return 0; 
} 

