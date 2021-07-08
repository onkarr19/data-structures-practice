# include <iostream>
using namespace std;

#define get(a) int a; cin >> a
#define println(a) cout << a << '\n'
#define print(a) cout << a << ' '

struct Node{
    int data;
    Node * left, * right;
};

Node * create() {
    get(x);
    if(x==-1) return NULL;
    Node * ptr = new Node();
    ptr->data=x;
    ptr->left = create();
    ptr->right = create();
    return ptr;
}

void inorderTraversal(Node * ptr) {
    if(ptr==NULL) return;
    inorderTraversal(ptr->left);
    print(ptr->data);
    inorderTraversal(ptr->right);
}

bool isBST(Node * ptr) {
    static Node *prev = NULL;
    if(ptr!=NULL) {
        if(!isBST(ptr->left)) return false;
        if(prev!=NULL && ptr->data <= prev->data) return false;
        prev = ptr;
        return isBST(ptr->right);
    }
    else return true;
}

Node * search(Node* ptr, int k) {
	if (ptr==NULL) return NULL;
	if (ptr->data==k) return ptr;
	if (ptr->data>k) search(ptr->left, k);
	else search(ptr->right, k);
}

void insert(Node *ptr, int k) {
	Node *prev = NULL;
	while(ptr!=NULL) {
		prev = ptr;
		if (k==ptr->data) {
			println("Cannot insert, already in BST");
			return;
		}
		else if (k<ptr->data) ptr = ptr->left;
		else ptr = ptr->right;
	}
	Node* x = new Node();
	x->data=k;
	x->left=x->right=NULL;
	if (k<prev->data) prev->left = x;
	else prev->right = x;
}

void deletee(Node * ptr, int k) {
	// To DO
}


int main() {

    Node* root = create();
    inorderTraversal(root);
    println(' ');
	// println(isBST(root));
    // inorderTraversal(root);
	// Node * temp = search(root, 90);
	// if (temp!=NULL) println(temp->data);
	// else println("not found");
    insert(root, 4);
	inorderTraversal(root);
    return 0;
}