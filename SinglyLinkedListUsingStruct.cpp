#include <iostream>
using namespace std;
#define debug() cout << "Working...\n";
#define get(x) int x; cin >> x;
#define put(x) cout << x << "\n";


struct Node;
Node* head = NULL;

struct Node {
	int data;
	Node* next;

	void print() {
		Node* ptr = head;
		while(ptr!=NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}

	void prepend(int k) {
		Node * temp = new Node();
		temp->data = k;
		temp->next = head;
		head = temp;
	}

	void append(int k) {
		Node* temp = new Node();
		temp->data = k;

		Node* ptr = head;
		while(ptr->next!=NULL) ptr = ptr->next;
		ptr->next = temp;
	}

	void insert(int k, int index) {
		if (index<=0)
		{
			prepend(k);
			return;
		}
		Node*ptr = head;
		while(--index > 0 && ptr->next!=NULL) {
			ptr = ptr->next;
		}
		Node* temp = new Node();
		temp->data = k;
		temp->next = ptr->next;
		ptr->next = temp;
	}

	void insertAfterValue(int k, int val) {
		Node* temp = new Node();
		temp->data = k;
		Node* ptr = head;
		while(ptr->data!=val) ptr = ptr->next;
		temp->next = ptr->next;
		ptr->next = temp;
	}

	void deleteAtBeginning() {
		Node* ptr = head;
		head = head->next;
		free(ptr);
	}

	void deleteAtEnd(){
		if (head == NULL)
		{
			put("List Underflow");
		} else if (head->next == NULL) {
			delete(head);
			head = NULL;
		} else {
			Node* ptr = head;
			while(ptr->next->next!=NULL) ptr = ptr->next;
			delete(ptr->next);
			ptr->next = NULL;
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

	void destruct() {
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
	Node* head = new Node();
	head = NULL;

	head->prepend(2);
	head->prepend(15);
	// head->print();
	head->append(6);
	head->append(7);
	head->prepend(90);
	head->append(23);
	// head->print();
	head->insert(12,-10);
	head->insert(43,10);
	// (*head).print();

	head->insertAfterValue(87, 2);
	head->print();
	// head->deleteAtEnd();
	// put(head->search());
	head->deleteAtIndex(head->search(15));
	head->print();


	head->destruct();
	return 0;
}