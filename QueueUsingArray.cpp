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
		println("Queue Overflow...");
	} else if (front==-1 && rear==-1) {
		queue[rear+1] = k;
		front=0;
		rear=0;
	} else {
		queue[rear+1] = k;
		rear++;
	}
}

void display() {
	if (front==-1) {
		println("Queue is empty");
	} else for (int i = front; i <= rear; ++i)	{
		println(queue[i]);
	}
}

int dequeue() {
	int val = -1;
	if(front==-1) {
		println("Queue is empty");
	} else if(front==rear) {
		val = queue[front];
		front = rear = -1;
	} else {
		val = queue[front];
		front++;
	}
	return val;
}


int main() {
	enqueue(3);
	enqueue(5);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	display();

	
	print("Dequeued: ");
	println(dequeue());
	print("Dequeued: ");
	println(dequeue());
	print("Dequeued: ");
	println(dequeue());
	print("Dequeued: ");
	println(dequeue());
	print("Dequeued: ");
	println(dequeue());
	display();
	return 0;
}