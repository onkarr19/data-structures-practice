#include <iostream>
#include <math.h>
using namespace std;
#define println(a) cout << a << "\n";
#define print(a) cout << a;

int precedenceOf(char);
bool isOperator(char);
string infixToPostfix(string);
int evalPostfix(string);

template <class T>
class Node{
public:
	T data;
	Node* next;

	Node(){next=NULL;}
};
/*
template <class T>
struct Node{
	T data;
	Node* next;
};
*/

template <class T>
class Stack{
public:
	Node<T> *head;
	Stack(){head=NULL;}

	void push(T k) {
		Node<T>*temp = new Node<T>;
		temp->data = k;
		temp->next = head;
		head = temp;
	}

	bool isEmpty() {return head==NULL;}

	void display() {
		if (isEmpty()) {
			println("Stack is Empty");
			return;
		}
		Node<T>*ptr = head;
		while(ptr!=NULL) {
			print(ptr->data);
			ptr = ptr->next;
		}
		cout <<endl;
	}

	T pop() {
		if(isEmpty()) return '-';
		Node<T> *temp = head;
		T k = head->data;
		head = head->next;
		free(temp);
		return k;
	}

	T top() {
		if (isEmpty()) return '-';
		return head->data;
	}

	~Stack() {
		Node<T> *ptr = head;
		while( ptr != NULL ) {
		    Node<T>*next = ptr->next;
		    delete(ptr);
		    ptr = next;
		}
		head = NULL;
	}
};


int precedenceOf(char c) {
	if (c=='^') return 3;
	if (c=='*' ||c=='/') return 2;
	if (c=='+' || c=='-') return 1;
	return -1;
}


bool isOperator(char a) {
	string operators = "+-*/^";
	for (int i = 0; i < operators.length(); ++i) {
		if (a == operators[i]) return true;
	}
	return false;
}


string infixToPostfix(string s) {
	Stack<char> stack;
	char c;
	string res;
	for (int i = 0; s[i]; ++i) {
		c = s[i];
		if (c!=' ') {
			if (c=='(') {stack.push(c);}
			else if (c==')') {
					while (!stack.isEmpty() && stack.top()!='(') {
						res += stack.pop();
					} stack.pop();
			} else if (isOperator(c)) {
				while (!stack.isEmpty() && precedenceOf(stack.top()) >= precedenceOf(c)) {
					res += stack.pop();
				} stack.push(c);
			} else res += c;
		}
	}
	while(!stack.isEmpty()) {
		res += stack.pop();
	}

	return res;
}


int evalPostfix(string s) {
	Stack<int> stack;
	int a,b;
	char c;
	for (int i = 0; s[i]; ++i) {
		c = s[i];
		if (c==' ') continue;
		if (isOperator(c)) {
			b = stack.pop();
			a = stack.pop();
			print(a); print(c); println(b);
			switch(c) {
				case '+': stack.push(a+b); break;
				case '-': stack.push(a-b); break;
				case '*': stack.push(a*b); break;
				case '/': stack.push(a/b); break;
				case '^': stack.push(pow(a,b)); break;
			}
		} else {
			int num=0;
			while(isdigit(s[i])) { 
				num = num * 10 + (s[i] - '0'); 
				i++; 
            }
            i--; 
			stack.push(num);
		}
	}
	return stack.pop();
}


int main() {
	string exprsn; 
	getline(cin, exprsn);
	println(exprsn);
	print(infixToPostfix(exprsn));
	// println(evalPostfix(exprsn));
	return 0;
}