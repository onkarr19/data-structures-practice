#include <iostream>
using namespace std;
#define get(a) int a; cin >> a;
#define println(a) cout << a << "\n";
#define print(a) cout << a;
#define N 5
int queue[N];
int front=-1,rear=-1;


void enqueue(int k) {
	if (rear==N-1) {
		println("Queue Overloading...");
	} else if (front==rear) {
		queue[rear+1] = k;
		front++;
		rear++;
	} else {
		queue[rear+1] = k;
		rear++;
	}
}

void display() {
	if (front==-1) {
		println("Queue is empty");
	} else for (int i = front; i < rear; ++i)	{
		println(queue[i]);
	}
}





int main() {
	enqueue(3);
	enqueue(5);
	enqueue(7);
	println("gjri");
	
	display();
	return 0;
}