# include <iostream>
using namespace std;

#define get(a) int a; cin >> a;
#define println(a) cout << a << '\n';
#define print(a) cout << a;


struct Node {
    int data;
    Node * left, * right;
};

Node * create() {
    get(x);
    if (x==-1) {return NULL;}
    Node * ptr = new Node();
    ptr->data = x;
    ptr->left = create();
    ptr->right = create();

    return ptr; 
}

// Left - Root - Right
void inorderTraversal(Node * ptr) {
    if(ptr==NULL) return;
    inorderTraversal(ptr->left);
    println(ptr->data);
    inorderTraversal(ptr->right);
}

// Root - Left - Right
void preorderTraversal(Node * ptr) {
    if(ptr==NULL) return;
    println(ptr->data);
    preorderTraversal(ptr->left);
    preorderTraversal(ptr->right);
}

// Left - Right - Root
void postorderTraversal(Node * ptr) {
    if(ptr==NULL) return;
    postorderTraversal(ptr->left);
    postorderTraversal(ptr->right);
    println(ptr->data);
}




int main() {
    Node * root = create();
    inorderTraversal(root);
    // preorderTraversal(root);
    // postorderTraversal(root);

    println("Working");

    return 0;
}