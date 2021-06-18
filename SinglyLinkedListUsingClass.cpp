#include <iostream>
using namespace std;
#define debug() cout << "Working...\n";
#define get(x) int x; cin >> x;
#define put(x) cout << x << "\n";

class Node{
public:
	int data;
	Node* next;
	Node() {next=NULL;}
};


class LinkedList
{
	Node* head;
public:
	LinkedList() {head=NULL;}

	void print() {
		Node* temp = head;
		while (temp!=NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void prepend(int x) {
		Node * temp = new Node();
		temp->data = x;
		temp->next = head;
		head = temp;
	}

	void append(int val) {
		Node * temp = new Node();
		temp->data = val;

		if (head==NULL)
			head = temp;
		else {
			Node *ptr = head;
			while (ptr->next!=NULL)
				ptr = ptr->next;
			ptr->next = temp;
		}
	}

	void insert(int val, int index) {
		if (index ==0 ) {
			prepend(val); return;
		}
		Node* temp = new Node();
		temp->data = val;

		Node* ptr = head;
		while (--index > 0 && ptr->next!=NULL) 
			ptr = ptr->next;
		temp->next = ptr->next;
		ptr->next=temp;
	}

	void insertAfterValue(int val, int key) {
		Node* temp = new Node();
		temp->data = val;

		Node* ptr = head;
		while(ptr->data!=key) ptr = ptr->next;
		temp->next = ptr->next;
		ptr->next = temp;
	}

	void deleteAtBeginning() {
		if (head==NULL) {
			put("List Underflow");
		}
		else {
			Node* temp = head;
			head = head->next;
			delete(temp);
		}
	}

	void deleteAtEnd() {
		if (head==NULL) {
			put("List Underflow");
		}
		else if (head->next==NULL) {
			delete(head);
			head=NULL;
		} else {
			Node* temp = head;
			while(temp->next->next!=NULL) temp = temp->next;
			delete(temp->next);
			temp->next=NULL;
		}
	}

	void deleteAtIndex(int index) {
		if (head==NULL) {
			put("List Underflow");
		} else if (index==0) {
			deleteAtBeginning();
		} else {
			Node* temp = head;
			Node* ptr = head;
			while(index>0 && ptr->next!=NULL) {
				temp = ptr;
				ptr = ptr->next;
				--index;
			}
			temp->next = ptr->next;	
			delete(ptr);
			// temp->next=NULL;
		}
	}

	int search(int p) {
		Node*ptr = head;
		int index = 0;
		while (ptr!=NULL) {
			if (ptr->data==p) {
				return index;
			}
			ptr = ptr->next;
			++index;
		}
		return -1;
	}

	void reverse() {
		Node *prev, *current, *ptr;
		prev = NULL;
		current = ptr = head;

		while(ptr!=NULL) {
			ptr = ptr->next;
			current->next = prev;
			prev = current;
			current = ptr;
		}
		head = prev;
	}

	~LinkedList() {
		Node* ptr = head;
		while( ptr != NULL ) {
		    Node* next = ptr->next;
		    delete(ptr);
		    ptr = next;
		}
		head = NULL;
	}
};


int main() {
	LinkedList head;
	head.append(33);
	head.prepend(45);
	
	// head.prepend(34);
	// head.prepend(75);
	// head.prepend(1);

	head.print();
	head.insert(21, 1);
	head.insertAfterValue(44, 21);
	head.print();
	head.deleteAtEnd();
	// head.print();

	// head.deleteAtIndex(9);
	// debug();
	// put(head.search(33));
	head.reverse();


	head.print();
	return 0;
}