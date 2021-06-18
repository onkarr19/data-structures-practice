#include <iostream>
using namespace std;


struct Node{
	int data;
	Node * next;
};

// Node * head = NULL;


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
Node * push(Node *s, int p) {
	Node *temp = new Node();
	temp->data = p;
	temp->next = s;
	s = temp;
	return s;
}


// At beginning, Time Complexity -> O(1)
void prepend(Node *s, int k) {
	Node * temp = new Node();
	temp->data = k;
	temp->next = s;
	s = temp;
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


// Delete top-most element, Time Complexity -> O(1)
int pop(Node * s) {
	if (s == NULL) return -1;
	Node* temp = new Node();
	temp = s;
	int val = s->data;
	s->next = temp->next->next;
	// free(temp);
	return val;
}


int main() {
	Node * head = new Node();
	head = NULL;

	int n,x;
	cin >> n;
	for (int i = 0; i < 5; ++i)
	{
		cin >> x;
		head = push(head, x);
	}
	// traverse(head);
	// insert(head, 30,1);
	// traverse(head);
	// append(head, 500);
	// traverse(head);
	// head = push(head, 233);
	// head = push(head,430);
	traverse(head);
	prepend(head,32);

	// cout << pop(head) << endl;
	// cout << pop(head) << endl;
	// cout << pop(head) << endl;
	// cout << pop(head) << endl;
	// cout << pop(head) << endl;
	// cout << pop(head) << endl;



	traverse(head);
	return 0;
}