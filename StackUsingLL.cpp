#include <iostream>
using namespace std;
#define get(a) int a; cin >> a;
#define println(a) cout << a << "\n";
#define print(a) cout << a << " ";

class Node{
public:
	int data;
	Node* next;
	Node() {next=NULL;}
};


class Stack{
	Node* top;
public:
	Stack() {top=NULL;}

	void push(int k) {
		Node* temp = new Node();
		if (temp) {
			temp->data = k;
			temp->next = top;
			top = temp;
		} else println("Stack Overflow");
	}

	bool isEmpty() {
		return top == NULL;
	}

	int peek() {
		return isEmpty() ? -1 : top->data;
	}

	int pop() {
		if(isEmpty()) {
			println("Stack Underflow");
			return -1;
		} else {
			int val = top->data;
			Node* temp = top;
			top = top->next;
			temp->next = NULL;
			free(temp);
			return val;
		}
	}

	void printStack() {
		println("Stack elements:");
		if (isEmpty())
		{
			println("Stack Underflow");
			return;
		}
		Node* temp = top;
		while(temp!=NULL) {
			println(temp->data);
			temp = temp->next;
		} println(" ");
	}
};


int main() {
	Stack s;
	s.push(23);
	s.push(43);
	s.push(89);
	s.push(53);
	s.printStack();
	println(s.peek());

	println("Popping: ");

	// cout << s.pop() << endl;
	cout << s.pop() << endl;
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;

	s.printStack();
	println(s.peek());
	return 0;
}