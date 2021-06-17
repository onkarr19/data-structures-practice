#include <iostream>
using namespace std;


struct Node{
	int data;
	Node * next;
};

Node * head = NULL;

// Traversal
// Time Complexity -> O(n)
void traverse(Node *s) {
	Node *ptr = s;
	while (ptr!=NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}


// Insertion
// At beginning, Time Complexity -> O(1)
Node * Spush(Node *s, int p) {
	Node *ptr = s;
	Node *temp = new Node();
	temp->data = p;
	temp->next = ptr;
	s = temp;
	return s;
}


// At beginning, Time Complexity -> O(1)
void push(Node *top, int val) {
	struct Node* temp = new Node();
	temp->data = val;
	temp->next = head;
	head = temp;
}


// Top most element, Time Complexity -> O(1)
int pop(Node *) {
	if (head == NULL) return -1;
	struct Node* temp = new Node();
	temp = head;
	int val = head->data;
	head = head->next;
	free(temp);
	return val;
}


// At end, Time Complexity -> O(n)
void append(Node *s, int p) {
	Node *ptr = s;
	while (ptr->next!=NULL) {
		ptr = ptr->next;
	}

	Node *temp = new Node();
	temp->data = p;
	ptr->next = temp;
	temp->next = NULL;
}


// At ith index, Time Complexity -> O(n)
void insert(Node *s, int p, int pos) {
	Node *ptr = s;
	while (--pos && ptr->next!=NULL) {
		ptr = ptr->next;
	}

	Node *temp = new Node();
	temp->data = p;
	temp->next = ptr->next;
	ptr->next = temp;
}

int main() {
	// Node * head = new Node();
	// head = NULL;

	push(head, 6);
	push(head, 3);
	push(head, 7);
	push(head, 9);
	push(head, 21);
	traverse(head);

	cout << pop(head) << endl;
	cout << pop(head) << endl;
	cout << pop(head) << endl;
	cout << pop(head) << endl;
	cout << pop(head) << endl;
	cout << pop(head) << endl;





	// traverse(head);
	return 0;
}