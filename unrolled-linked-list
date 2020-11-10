// C program to implement unrolled linked list
// and traversing it.
#include<stdio.h>
#include<stdlib.h>
#define maxElements 4

// Unrolled Linked List Node
struct Node
{
	int numElements;
	int array[maxElements];
	struct Node *next;
};

/* Function to traverse am unrolled linked list
and print all the elements*/
void printUnrolledList(struct Node *n)
{
	while (n != NULL)
	{
		// Print elements in current node
		for (int i=0; i<n->numElements; i++)
			printf("%d ", n->array[i]);

		// Move to next node 
		n = n->next;
	}
}

// Program to create an unrolled linked list
// with 3 Nodes
int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// allocate 3 Nodes
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	// Let us put some values in second node (Number
	// of values must be less than or equal to
	// maxElement)
	head->numElements = 3;
	head->array[0] = 1;
	head->array[1] = 2;
	head->array[2] = 3;

	// Link first Node with the second Node
	head->next = second;

	// Let us put some values in second node (Number
	// of values must be less than or equal to
	// maxElement)
	second->numElements = 3;
	second->array[0] = 4;
	second->array[1] = 5;
	second->array[2] = 6;

	// Link second Node with the third Node
	second->next = third;

	// Let us put some values in third node (Number
	// of values must be less than or equal to
	// maxElement)
	third->numElements = 3;
	third->array[0] = 7;
	third->array[1] = 8;
	third->array[2] = 9;
	third->next = NULL;

	printUnrolledList(head);

	return 0;
}

