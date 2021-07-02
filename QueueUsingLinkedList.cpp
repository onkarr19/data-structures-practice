# include <iostream>
using namespace std;

#define get(a) int a; cin >> a;
#define println(a) cout << a << '\n';
#define print(a) cout << a;
#define N 5


struct Node {
    int data;
    Node * next;
};

Node * front = NULL;
Node * rear = NULL;

int isEmpty(){
    return (front==NULL);
}

int isFull(){
    Node * temp = new Node();
    return (temp==NULL);
}

void enqueue(int k) {
    if (isFull()) {
        println("Queue Overflow...");
    } else {
        Node* temp = new Node();
        temp->data=k;
        temp->next=NULL;
        if (front==NULL){
            front=rear=temp;
        } else {
            rear->next=temp;
            rear=temp;
        }
    }
}

int dequeue() {
    int k=-1;
    if(isEmpty()) {
        println("Queue is empty");
    } else {
        k=front->data;
        Node * temp = front;
        front = front->next;
        free(temp);
    }
    return k;
}


void display() {
    Node * ptr = front;
    while(ptr!=NULL) {
        println(ptr->data);
        ptr = ptr->next;
    }
}



int main() {
    enqueue(4);
    enqueue(6);
    enqueue(9);
    println(dequeue());
    println(dequeue());
    println(dequeue());
    println(dequeue());

    display();

    return 0;
}