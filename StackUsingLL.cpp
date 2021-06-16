#include <iostream>
using namespace std;
#define size 10

class stack {
private:
	int top;
	int s[size];

	bool isFull() {
		return top == size-1;
	}

	bool isEmpty() {
		return top == -1;
	}

public:
	void push(int m) {
		if (!isFull())
		{
			s[++top] = m;
		} else cout << "Stack Overflow\n";
	}

	int pop() {
		int val = -1;
		if (!isEmpty())
		{
			val = s[top];
			top--;
		} else cout << "Stack Underflow\n";
		return val;
	}

	int peek() {
		return s[top];
	}
};

int main() {
	
	stack s;
	s.push(1);
	s.push(2);
	s.push(14);
	s.push(13);
	s.push(19);
	s.push(12);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;
}
