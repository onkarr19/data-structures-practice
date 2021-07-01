#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define println(a) cout << a << "\n";
#define print(a) cout << a;


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

int eval(int a, int b, char c) {
	switch(c) {
		case '+': return (a+b);
		case '-': return (a-b);
		case '*': return (a*b);
		case '/': return (a/b);
		case '^': return (pow(a,b));
	}
}


int precedenceOf(char c) {
	if (c=='^') return 4;
	// if (c=='(' ||c==')') return 3;
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
			a = stack.pop();
			b = stack.pop();
			stack.push(eval(b,a,c));
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


string infixToPrefix(string s) {
	s = string(s.rbegin(), s.rend());
	char c;
	string ans;
	Stack<char>stack;
	for (int i = 0; s[i]; ++i) {
		c = s[i];
		if (c==' ') continue;
		else if (c==')') {
			stack.push(c);
		}
		else if (c=='(') {
			while (stack.top()!=')') {
				ans += stack.pop();
			} stack.pop();
		} else if (isOperator(c)) {
			if (stack.top() == ')') {stack.push(c);}
			else if(stack.isEmpty() || precedenceOf(c) > precedenceOf(stack.top())) {
				stack.push(c);
			} else {
				while (precedenceOf(c) < precedenceOf(stack.top())) {
					ans += stack.pop();
				} 
				stack.push(c);
			}  
		} else {ans += c;}
	}

	while(!stack.isEmpty()) {
		ans += stack.pop();
	}
	return string(ans.rbegin(), ans.rend());
}


int evalPrefix(string s) {
	Stack<int> stack;
	int a,b;
	char c;

	for (int i = s.length(); i <= 0; --i) {
		c = s[i];
		if (isOperator(c)) {
			a = stack.pop();
			b = stack.pop();
			stack.push(eval(a,b,c));
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
	string exprsn, s;
	getline(cin, exprsn);
	println(exprsn);
	println("Infix to Prefix:");
	s = infixToPrefix(exprsn);
	println(s);
	// println(evalPrefix(s));
	
	println(' ');
	
	println("Infix to Postfix:");
	s = infixToPostfix(exprsn);
	println(s);
	// println(evalPostfix(s));
	return 0;
}