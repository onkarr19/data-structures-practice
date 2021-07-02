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

void enqueueRear(int k) {
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

void enqueueFront(int k) {
    if (isFull()) {
        println("Queue Overflow...");
    } else {
        Node* temp = new Node();
        temp->data=k;
        // temp->next=NULL;
        if (front==NULL){
            front=rear=temp;
        } else {
            temp->next=front;
            front=temp;
        }
    }
}

int dequeueFront() {
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

int dequeueRear() {
    int k=-1;
    // Not Possible with Singly LL
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
    enqueueRear(4);
    enqueueRear(6);
    enqueueRear(9);

    dequeueRear();
    dequeueRear();
    dequeueRear();
    dequeueRear();

    display();

    return 0;
}