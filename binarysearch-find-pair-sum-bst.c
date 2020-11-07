/* In a balanced binary search tree isPairPresent two element which sums to 
a given value time O(n) space O(logn) */
#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 100 

// A BST node 
struct node { 
	int val; 
	struct node *left, *right; 
}; 

// Stack type 
struct Stack { 
	int size; 
	int top; 
	struct node** array; 
}; 

// A utility function to create a stack of given size 
struct Stack* createStack(int size) 
{ 
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
	stack->size = size; 
	stack->top = -1; 
	stack->array = (struct node**)malloc(stack->size * sizeof(struct node*)); 
	return stack; 
} 

// BASIC OPERATIONS OF STACK 
int isFull(struct Stack* stack) 
{ 
	return stack->top - 1 == stack->size; 
} 

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1; 
} 

void push(struct Stack* stack, struct node* node) 
{ 
	if (isFull(stack)) 
		return; 
	stack->array[++stack->top] = node; 
} 

struct node* pop(struct Stack* stack) 
{ 
	if (isEmpty(stack)) 
		return NULL; 
	return stack->array[stack->top--]; 
} 

// Returns true if a pair with target sum exists in BST, otherwise false 
bool isPairPresent(struct node* root, int target) 
{ 
	// Create two stacks. s1 is used for normal inorder traversal 
	// and s2 is used for reverse inorder traversal 
	struct Stack* s1 = createStack(MAX_SIZE); 
	struct Stack* s2 = createStack(MAX_SIZE); 

	// Note the sizes of stacks is MAX_SIZE, we can find the tree size and 
	// fix stack size as O(Logn) for balanced trees like AVL and Red Black 
	// tree. We have used MAX_SIZE to keep the code simple 

	// done1, val1 and curr1 are used for normal inorder traversal using s1 
	// done2, val2 and curr2 are used for reverse inorder traversal using s2 
	bool done1 = false, done2 = false; 
	int val1 = 0, val2 = 0; 
	struct node *curr1 = root, *curr2 = root; 

	// The loop will break when we either find a pair or one of the two 
	// traversals is complete 
	while (1) { 
		// Find next node in normal Inorder traversal. See following post 
		// https:// www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/ 
		while (done1 == false) { 
			if (curr1 != NULL) { 
				push(s1, curr1); 
				curr1 = curr1->left; 
			} 
			else { 
				if (isEmpty(s1)) 
					done1 = 1; 
				else { 
					curr1 = pop(s1); 
					val1 = curr1->val; 
					curr1 = curr1->right; 
					done1 = 1; 
				} 
			} 
		} 

		// Find next node in REVERSE Inorder traversal. The only 
		// difference between above and below loop is, in below loop 
		// right subtree is traversed before left subtree 
		while (done2 == false) { 
			if (curr2 != NULL) { 
				push(s2, curr2); 
				curr2 = curr2->right; 
			} 
			else { 
				if (isEmpty(s2)) 
					done2 = 1; 
				else { 
					curr2 = pop(s2); 
					val2 = curr2->val; 
					curr2 = curr2->left; 
					done2 = 1; 
				} 
			} 
		} 


