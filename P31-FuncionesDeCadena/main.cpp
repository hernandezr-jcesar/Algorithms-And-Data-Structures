// A C++ program to insert a linked list in 
// to another linked list at position k 
#include <bits/stdc++.h> 
using namespace std; 

/* Structure for a linked list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

// Function to insert whole linked list in 
// to another linked list at position k 
void insert(struct Node* head1, struct Node* head2, 
			int k) 
{ 
	// traverse the first linked list until k-th 
	// point is reached 
	int count = 1; 
	struct Node* curr = head1; 
	while (count < k) { 
		curr = curr->next; 
		count++; 
	} 

	// backup next node of the k-th point 
	struct Node* temp = curr->next; 

	// join second linked list at the kth point 
	curr->next = head2; 

	// traverse the second linked list till end 
	while (head2->next != NULL) 
		head2 = head2->next; 

	// join the second part of the linked list 
	// to the end 
	head2->next = temp; 
} 

// Function to print linked list recursively 
void printList(Node* head) 
{ 
	if (head == NULL) 
		return; 

	// If head is not NULL, print current node 
	// and recur for remaining list 
	cout << head->data << " "; 
	printList(head->next); 
} 

/* Given a reference (pointer to pointer) to the head 
of a list and an int, insert a new node on the front 
of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Driven program to test above function */
int main() 
{ 
	/* The constructed linked lists are : 
	a: 1->2->3->4->5; 
	b: 7->8->9->10->11 */
	struct Node* a = NULL; 
	struct Node* b = NULL; 
	int k = 2; 

	// first linked list 
	push(&a, 5); 
	push(&a, 4); 
	push(&a, 3); 
	push(&a, 2); 
	push(&a, 1); 

	// second linked list 
	push(&b, 11); 
	push(&b, 10); 
	push(&b, 9); 
	push(&b, 8); 
	push(&b, 7); 

	printList(a); 
	cout << "\n"; 

	printList(b); 

	insert(a, b, k); 

	cout << "\nResulting linked list\t"; 
	printList(a); 

	return 0; 
} 
